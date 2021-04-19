#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <vector>
#include <string>
#include "CipherInterface.h"

using namespace std;

class Vigenere : public CipherInterface
{
public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);
	virtual string findKeySize(const string& input);
	virtual int findPosition(const string& text, int idx);

protected:
	string cipherKey;
	const vector<char>& letters{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

};

#endif