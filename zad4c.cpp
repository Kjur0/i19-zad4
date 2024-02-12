#include <iostream>
#include <regex>

using namespace std;

bool isValidFormat(const string& phoneNumber) {
	regex pattern("^(\\d{3})[- ]?(\\d{3})[- ]?(\\d{4})$");
	return regex_match(phoneNumber, pattern);
}

string unformat(const string& phoneNumber) {
	regex pattern("(\\d{3})[- ]?(\\d{3})[- ]?(\\d{4})");
	return regex_replace(phoneNumber, pattern, "$1$2$3");
}

void zad3() {
	string phoneNumber;
	cout << "Wprowad� numer telefonu: ";
	getline(cin, phoneNumber);
	if (isValidFormat(phoneNumber)) {
		cout << "Numer telefonu po usuni�ciu formatowania: " << unformat(phoneNumber) << endl;
	} else {
		cout << "Nieprawid�owy format numeru telefonu." << endl;
	}
}