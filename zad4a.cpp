#include <iostream>
#include "zad4ab.h"

using namespace std;

void zad1() {
	const int MIN_LENGTH = 8;
	string password;
	cout << "Program sprawdza, czy wprowadzone hasło" << endl
		<< "spełnia następujące wymagania:" << endl
		<< "(1) Hasło musi się składać z co najmniej 8 znaków." << endl
		<< "(2) Hasło musi zawierać co najmniej 1 dużą literę." << endl
		<< "(3) Hasło musi zawierać co najmniej 1 małą literę." << endl
		<< "(4) Hasło musi zawierać co najmniej 1 cyfrę." << endl
		<< endl;
	cout << "Wprowadź hasło: ";
	cin >> password;

	if (password.length() < MIN_LENGTH) cout << "Hasło jest za krótkie!";
	else if (numberUpperCase(password) < 1) cout << "Hasło nie zawiera co najmniej 1 dużej litery!";
	else if (numberLowerCase(password) < 1) cout << "Hasło nie zawiera co najmniej 1 małej litery!";
	else if (numberDigits(password) < 1) cout << "Hasło nie zawiera co najmniej 1 cyfry!";
	else cout << "Hasło jest prawidłowe!";
}

