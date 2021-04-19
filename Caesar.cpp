#include "Caesar.h"

using namespace std;

bool Caesar::setKey(const string& key)
{
    for (int i = 0; i < key.length(); i++) {
        if (!isdigit(key[i])) return false;
    }
    int tempKey = stoi(key);
    shift = tempKey;
    return true;
}

string Caesar::encrypt(const string& plaintext)
{
    string cipherText="";
    for (int i = 0; i < plaintext.length(); i++) {
        char index = plaintext[i];

        for (int j = 0; j < shift; j++) {
            if (isalpha(index)) {
                if (index == 'z') index = 'a';
                else index++;
            }
        }
        if (isalpha(index)) cipherText += index;
    }
    return cipherText;
}

string Caesar::decrypt(const string& ciphertext)
{
    string plainText="";
    for (int i = 0; i < ciphertext.length(); i++) {
        char index = ciphertext.at(i);

        for (int j = 0; j < shift; j++) {
            if (isalpha(index)) {
                if (index == 'a') index = 'z';
                else index--;
            }
        }
        if (isalpha(index)) plainText += index;
    }
    return plainText;
}