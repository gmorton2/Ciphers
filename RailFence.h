#ifndef RAILFENCECIPHER_H
#define RAILFENCECIPHER_H

#include <vector>
#include <string>
#include "CipherInterface.h"

using namespace std;

class RailFence : public CipherInterface
{
public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

protected:
	int cipherKey;
};

#endif
