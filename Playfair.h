#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include "CipherInterface.h"
#include<string>

using namespace std;

class Playfair : public CipherInterface
{
public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

protected:
	string secretKey;
	char mat[5][5];	
};

#endif
