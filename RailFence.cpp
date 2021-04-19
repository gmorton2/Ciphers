#include "RailFence.h"
#include<iostream>
using namespace std;

bool RailFence::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++) {
        if (!isdigit(key[i])) return false;
    }
    int tempkey = stoi(key);
    cipherKey = tempkey;
    return true;
}

string RailFence::encrypt(const string& plaintext)
{
    vector<vector<char>> matrix(cipherKey, vector<char>(plaintext.length()));
    bool direction = false;
    int row = 0, column = 0;
    string result = "";

    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < plaintext.length(); j++)
            matrix[i][j] = '\n';

    for (int i = 0; i < plaintext.length(); i++) {
        if (row == 0 || row == cipherKey - 1) direction = !direction;
        matrix[row][column++] = plaintext[i];
        if (direction) row++;
        else row--;
    }

    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < plaintext.length(); j++)
            if (matrix[i][j] != '\n') result.push_back(matrix[i][j]);

    return result;
}
string RailFence::decrypt(const string& ciphertext)
{
    vector<vector<char>> matrix(cipherKey, vector<char>(ciphertext.length()));
    bool direction;
    int row = 0, column = 0;
    string result = "";

    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < ciphertext.length(); j++)
            matrix[i][j] = '\n';

    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0) direction = true;
        if (row == cipherKey - 1) direction = false;
        matrix[row][column++] = '_';
        if (direction) row++;
        else row--;
        
    }
    int index = 0;
    for (int i = 0; i < cipherKey; i++)
        for (int j = 0; j < ciphertext.length(); j++)
            if (matrix[i][j] == '_' && index < ciphertext.length()) matrix[i][j] = ciphertext[index++];

    row = 0, column = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0) direction = true;
        if (row == cipherKey - 1) direction = false;
        if (matrix[row][column] != '_') result.push_back(matrix[row][column++]);
        if (direction) row++;
        else row--;
    }
    return result;
}