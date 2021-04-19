#ifndef CAESAR_H
#define CAESAR_H

#include <string>
#include "CipherInterface.h"
using namespace std;

class Caesar : public CipherInterface
{
public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

protected:
	int shift;
};

#endif