#include "Vigenere.h"

using namespace std;

bool Vigenere::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++)
        if (isdigit(key[i])) return false;
    cipherKey = key;
    return true;
}

string Vigenere::encrypt(const string& plaintext)
{
    string inputtemp = plaintext;
    string cipherText = "";
    int cipherKeyIdx = 0;
    int textIdx = 0;
    cipherKey = findKeySize(inputtemp);

    for (int i = 0; i < plaintext.length(); i++) {
        cipherKeyIdx = findPosition(cipherKey, i);
        textIdx = findPosition(inputtemp, i);
        cipherText += letters[(cipherKeyIdx + textIdx) % 26];
    }

    return cipherText;

}
string Vigenere::decrypt(const string& ciphertext)
{
    string inputtemp = ciphertext;
    string plainText;
    int cipherKeyIdx = 0;
    int textIdx = 0;
    cipherKey = findKeySize(inputtemp);
 
    for (int i = 0; i < ciphertext.length(); i++) {
        cipherKeyIdx = findPosition(cipherKey, i);
        textIdx = findPosition(inputtemp, i);
        plainText += letters[(textIdx - cipherKeyIdx + 26) % 26];
    }
    return plainText;
}

string Vigenere::findKeySize(const string& input)
{
    while (input.size() > cipherKey.size())
        cipherKey += cipherKey;
    return cipherKey;
}


int Vigenere::findPosition(const string& text, int idx)
{
    for (int i = 0; i < letters.size(); i++)
        if (text[idx] == letters[i]) return i;
    return 0;
}