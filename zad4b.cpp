#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <Wincrypt.h>
#include <iomanip>
#include "zad4ab.h"

using namespace std;

class UserManager {
private:
	string password;
protected:
	string passhash;
	string username;
	vector<string> usernames;
private:
	void addUser() {
		ofstream file("users.csv", ios::app);
		file << username << "," << passhash << endl;
		file.close();
	}

	void setUsername() {
		do {
			cout << "Wprowad� nazw� u�ytkownika: ";
			cin >> username;
			if (usernameExists(username)) cout << "U�ytkownik o tej nazwie ju� istnieje!" << endl;
		} while (usernameExists(username));
	}

	void setPassword() {
		const int MIN_LENGTH = 8;
		cout << "Program sprawdza, czy wprowadzone has�o" << endl
			<< "spe�nia nast�puj�ce wymagania:" << endl
			<< "(1) Has�o musi si� sk�ada� z co najmniej 8 znak�w." << endl
			<< "(2) Has�o musi zawiera� co najmniej 1 du�� liter�." << endl
			<< "(3) Has�o musi zawiera� co najmniej 1 ma�� liter�." << endl
			<< "(4) Has�o musi zawiera� co najmniej 1 cyfr�." << endl
			<< "(5) W ha�le nie mo�e wyst�powa� ci�g kolejnych wielkich liter" << endl
			<< "(6) W ha�le nie mo�e wyst�powa� ci�g kolejnych ma�ych liter" << endl
			<< "(7) W ha�le nie mo�e wyst�powa� ci�g kolejnych cyfr" << endl
			<< "(8) W ha�le nie znajduje si� sekwencja powtarzaj�cych si� znak�w" << endl
			<< endl;
		do {
			cout << "Wprowad� has�o: ";
			cin >> password;
			if (password.length() < MIN_LENGTH) cout << "Has�o jest za kr�tkie!" << endl;
			if (numberUpperCase(password) < 1) cout << "Has�o nie zawiera co najmniej 1 du�ej litery!" << endl;
			if (numberLowerCase(password) < 1) cout << "Has�o nie zawiera co najmniej 1 ma�ej litery!" << endl;
			if (numberDigits(password) < 1) cout << "Has�o nie zawiera co najmniej 1 cyfry!" << endl;
			if (consecutiveUpperCase(password)) cout << "Has�o zawiera ci�g kolejnych wielkich liter!" << endl;
			if (consecutiveLowerCase(password)) cout << "Has�o zawiera ci�g kolejnych ma�ych liter!" << endl;
			if (consecutiveDigits(password)) cout << "Has�o zawiera ci�g kolejnych cyfr!" << endl;
			if (repeatingCharacters(password)) cout << "Has�o zawiera sekwencj� powtarzaj�cych si� znak�w!" << endl;
		} while (password.length() < MIN_LENGTH || numberUpperCase(password) < 1 || numberLowerCase(password) < 1 || numberDigits(password) < 1 || consecutiveUpperCase(password) || consecutiveLowerCase(password) || consecutiveDigits(password) || repeatingCharacters(password));
		cout << "Has�o jest prawid�owe!" << endl;
	}

public:
	void readUsernames() {
		ifstream file("users.csv");
		string line;
		while (getline(file, line)) {
			size_t pos = line.find(',');
			if (pos != string::npos) {
				usernames.push_back(line.substr(0, pos));
			}
		}
		file.close();
	}

	bool usernameExists(const string& check) {
		for (const string& existingUsername : usernames) {
			if (existingUsername == check) {
				return true;
			}
		}
		return false;
	}

	void hashPassword() {
		HCRYPTPROV hProv = 0;
		HCRYPTHASH hHash = 0;
		BYTE rgbHash[16];
		DWORD cbHash = 0;

		CryptAcquireContext(&hProv, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
		CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash);
		CryptHashData(hHash, (BYTE*)password.c_str(), password.size(), 0);
		cbHash = 16;
		CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0);

		stringstream ss;
		for (int i = 0; i < cbHash; i++) {
			ss << hex << setw(2) << setfill('0') << (int)rgbHash[i];
		}

		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);

		passhash = ss.str();
	}

	UserManager() {
		ofstream file("users.csv", ios::app);
		file.close();
		readUsernames();
		setUsername();
		setPassword();
		hashPassword();
	}

	string getUsername() {
		return username;
	}

	string getPasshash() {
		return passhash;
	}

	vector<string> getUsernames() {
		return usernames;
	}

	void save() {
		cout << "Zapisywanie do pliku users.csv...";
		addUser();
	}
};

void zad2() {
	UserManager umngr;
	umngr.save();
}

