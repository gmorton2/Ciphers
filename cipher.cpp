#include <string>
#include "CipherInterface.h"
#include "RowTranspose.h"
#include "Vigenere.h"
#include "RailFence.h"
#include "Caesar.h"
#include "Playfair.h"
#include "Hill.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	//from file
	string userinput;
	// PLF RTS RFC VIG CES
	string ciphername = argv[1];
	// key being used
	string keyinput = argv[2];
	// ENC or DEC
	string functype = argv[3];
	//  file taking input from
	string inputfile = argv[4];
	// file writing input to
	string outputfile = argv[5];

	ifstream infile;
	infile.open(inputfile);
	string line;
	while (getline(infile, line)) {
		userinput += line;
	}
	infile.close();



	//Playfair
	if (ciphername == "PLF") {
		CipherInterface* cipher = new Playfair();

		/* Error checks */
		if (!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
				__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		/* Set the encryption key */
		cipher->setKey(keyinput);

		if (functype == "ENC")
		{
			/* Perform encryption */
			userinput = cipher->encrypt(userinput);
		}
		if (functype == "DEC")
		{
			/* Perform decryption */
			userinput = cipher->decrypt(userinput);
		}

	}
		//Row transposition
		if (ciphername == "RTS") {
			CipherInterface* cipher = new RowTranspose();

			/* Error checks */
			if (!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			if (!cipher->setKey(keyinput))
			cipher->setKey(keyinput);

			if (functype == "ENC")
			{
				/* Perform encryption */
				userinput = cipher->encrypt(userinput);
			}
			if (functype == "DEC")
			{
				/* Perform decryption */
				userinput = cipher->decrypt(userinput);
			}
		}
		//Railfence
		if (ciphername == "RFC") {
			CipherInterface* cipher = new RailFence();

			/* Error checks */
			if (!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			cipher->setKey(keyinput);

			if (functype == "ENC")
			{
				/* Perform encryption */
				userinput = cipher->encrypt(userinput);
			}
			if (functype == "DEC")
			{
				/* Perform decryption */
				userinput = cipher->decrypt(userinput);
			}
		}
		//Vigenre
		if (ciphername == "VIG") {
			CipherInterface* cipher = new Vigenere();

			/* Error checks */
			if (!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			cipher->setKey(keyinput);

			if (functype == "ENC")
			{
				/* Perform encryption */
				userinput = cipher->encrypt(userinput);
			}
			if (functype == "DEC")
			{
				/* Perform decryption */
				userinput = cipher->decrypt(userinput);
			}
		}
		//Caesar
		if (ciphername == "CES") {
			CipherInterface* cipher = new Caesar();

			/* Error checks */
			if (!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			cipher->setKey(keyinput);

			if (functype == "ENC")
			{
				/* Perform encryption */
				userinput = cipher->encrypt(userinput);
			}
			if (functype == "DEC")
			{
				/* Perform decryption */
				userinput = cipher->decrypt(userinput);
			}
		}

		if (ciphername == "HIL") {
			CipherInterface* cipher = new Hill();
	
			/* Error checks */
			if (!cipher)
			{
				fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
					__FILE__, __FUNCTION__, __LINE__);
				exit(-1);
			}

			/* Set the encryption key */
			cipher->setKey(keyinput);			

			if (functype == "ENC")
			{
				/* Perform encryption */
				userinput = cipher->encrypt(userinput);
			}
			if (functype == "DEC")
			{
				/* Perform decryption */
				userinput = cipher->decrypt(userinput);
			}
		}


		//This is for outputting the contents of the encryption algorithm to file
		ofstream out(outputfile);
		out << userinput;
		out.close();

		return 0;
}
