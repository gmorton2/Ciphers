#include"Playfair.h"
using namespace std;



bool Playfair::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++)
    {
        if (isdigit(key[i])) {
            return false;
        }
    }
    secretKey = key;
    return true;
}

string Playfair::encrypt(const string& message)
{
    /* flag keeps track of letters that are filled in matrix */
    /* flag = 0 -> letter not already present in matrix */
    /* flag = 1 -> letter already present in matrix */
    //Generating the matrix
    int flag[26] = { 0 };
    int x = 0, y = 0;

    /* Add all characters present in the key */
    for (int i = 0; i < secretKey.length(); i++)
    {
        if (secretKey[i] == 'j') secretKey[i] = 'i'; // replace j with i

        if (flag[secretKey[i] - 'a'] == 0)
        {
            mat[x][y++] = secretKey[i];
            flag[secretKey[i] - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    /* Add remaining characters */
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == 'j') continue; // don't fill j since j was replaced by i

        if (flag[ch - 'a'] == 0)
        {
            mat[x][y++] = ch;
            flag[ch - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    //formating the string
    string tempMsg = message;
    for (int i = 0; i < tempMsg.length(); i++)
    {
        if (tempMsg[i] == 'j')  tempMsg[i] = 'i';
    }

    for (int i = 1; i < tempMsg.length(); i += 2) //pairing two characters
    {
        if (tempMsg[i - 1] == tempMsg[i])  tempMsg.insert(i, "x");
    }

    if (tempMsg.length() % 2 != 0)  tempMsg += "x";
    

    string ctext = "";
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    for (int i = 0; i < tempMsg.length(); i += 2)    // i is incremented by 2 inorder to check for pair values
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (tempMsg[i] == mat[j][k])
                {
                    x1 = j;
                    y1 = k;
                }
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (tempMsg[i+1] == mat[j][k])
                {
                    x2 = j;
                    y2 = k;
                }
       
        if (x1 == x2) // same row
        {
            ctext += mat[x1][(y1 + 1) % 5];
            ctext += mat[x2][(y2 + 1) % 5];
        }
        else if (y1 == y2) // same column
        {
            ctext += mat[(x1 + 1) % 5][y1];
            ctext += mat[(x2 + 1) % 5][y2];
        }
        else
        {
            ctext += mat[x1][y2];
            ctext += mat[x2][y1];
        }
    }
    return ctext;
}


string Playfair::decrypt(const string& message)
{
    int flag[26] = { 0 };
    int x = 0, y = 0;

    /* Add all characters present in the key */
    for (int i = 0; i < secretKey.length(); i++)
    {
        if (secretKey[i] == 'j') secretKey[i] = 'i'; // replace j with i

        if (flag[secretKey[i] - 'a'] == 0)
        {
            mat[x][y++] = secretKey[i];
            flag[secretKey[i] - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    /* Add remaining characters */
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == 'j') continue; // don't fill j since j was replaced by i

        if (flag[ch - 'a'] == 0)
        {
            mat[x][y++] = ch;
            flag[ch - 'a'] = 1;
        }
        if (y == 5) x++, y = 0;
    }

    string ptext = "";
    string tempMsg = message;
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    for (int i = 0; i < tempMsg.length(); i += 2) // i is incremented by 2 inorder to check for pair values
    {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (tempMsg[i] == mat[j][k])
                {
                    x1 = j;
                    y1 = k;
                }
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                if (tempMsg[i + 1] == mat[j][k])
                {
                    x2 = j;
                    y2 = k;
                }

        if (x1 == x2) // same row
        {
            ptext += mat[x1][--y1 < 0 ? 4 : y1];
            ptext += mat[x2][--y2 < 0 ? 4 : y2];
        }
        else if (y1 == y2) // same column
        {
            ptext += mat[--x1 < 0 ? 4 : x1][y1];
            ptext += mat[--x2 < 0 ? 4 : x2][y2];
        }
        else
        {
            ptext += mat[x1][y2];
            ptext += mat[x2][y1];
        }
    }
    return ptext;
}