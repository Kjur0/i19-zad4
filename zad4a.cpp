#include <iostream>
#include <string>

using namespace std;

int zad1numberUpperCase(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (isupper(str[i])) cnt++;
	return cnt;
}

int zad1numberLowerCase(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (islower(str[i])) cnt++;
	return cnt;
}

int zad1numberDigits(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i])) cnt++;
	return cnt;
}

void zad1() {
	setlocale(LC_ALL, "pl");
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
	else if (zad1numberUpperCase(password) < 1) cout << "Hasło nie zawiera co najmniej 1 dużej litery!";
	else if (zad1numberLowerCase(password) < 1) cout << "Hasło nie zawiera co najmniej 1 małej litery!";
	else if (zad1numberDigits(password) < 1) cout << "Hasło nie zawiera co najmniej 1 cyfry!";
	else cout << "Hasło jest prawidłowe!";
	
	system("pause>nul");
}

