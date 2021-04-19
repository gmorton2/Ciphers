#include "RowTranspose.h"
#include <iostream>
using namespace std;

bool RowTranspose::setKey(const string& key) {
	for (int i = 0; i < key.length(); i++) 
		if (!isdigit(key[i]) && key[i] !=' ') return false;
	cipherKey = key;
	cout << "set key: " << cipherKey << endl;
	return true;
}

string RowTranspose::encrypt(const string& plaintext) 
{ 
	string ciphertext = "";
	int maxcolumns = 0;

	for (int i = 0; i < cipherKey.length(); i++)
		if (cipherKey[i] != ' ') maxcolumns++;

	int maxrows = ceil(plaintext.length()/(double)maxcolumns);
	vector<vector<char>> matrix(maxrows, vector<char>(maxcolumns));

	int i = 0;
	for (int row = 0; row < maxrows; row++) {
		for (int col = 0; col < maxcolumns; col++) {
			if (i < plaintext.length()) {
				matrix[row][col] = plaintext[i];
				i++;
			}
			else matrix[row][col] = 'x';
		}
	}
	cout << "enter\n";
	for (int j = 0; j < cipherKey.length(); j++) {
		cout << cipherKey[j] << endl;

		if (cipherKey[j] == ' ') continue;
		else {
			cout << "enter\n";
			for (int row = 0; row < maxrows; row++) {
				ciphertext.push_back(matrix[row][cipherKey[j] - '1']);
			}
			cout << "\nexit";

		}
	}
	cout << "\nexit";

	return ciphertext;
}

string RowTranspose::decrypt(const string& ciphertext) {
	
	string plaintext = "";
	int maxcolumns = 0;

	for (int i = 0; i < cipherKey.length(); i++)
		if (cipherKey[i] != ' ') maxcolumns++;

	int maxrows = ceil(ciphertext.length()/(double)maxcolumns);
	vector<vector<char>> matrix(maxrows, vector<char>(maxcolumns));
	int i = 0;

	for (int col = 0; col < cipherKey.length(); col++) {
		for (int row = 0; row < maxrows; row++) {
			if (cipherKey[col] == ' ') break;
			else {
				matrix[row][cipherKey[col] - '1'] = ciphertext[i];
				i++;
			}
		}
	}
	for (int row = 0; row < maxrows; row++) 
		for (int col = 0; col < maxcolumns; col++) 
			if(matrix[row][col] != 'x') plaintext.push_back(matrix[row][col]);
		
	return plaintext;
}