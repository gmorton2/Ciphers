#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H

#include <vector>
#include <string>
#include "CipherInterface.h"

using namespace std;

class RowTranspose : public CipherInterface
{
public:
	virtual bool setKey(const string& key);
	virtual string encrypt(const string& plaintext);
	virtual string decrypt(const string& ciphertext);

protected:
	string cipherKey;

};

#endif