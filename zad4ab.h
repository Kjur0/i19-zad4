#pragma once 

#include <string>

using std::string;

// zad: 1,2
int numberUpperCase(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (isupper(str[i])) cnt++;
	return cnt;
}

// zad: 1,2
int numberLowerCase(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (islower(str[i])) cnt++;
	return cnt;
}

// zad: 1,2
int numberDigits(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i])) cnt++;
	return cnt;
}

// zad: 2
bool consecutiveLowerCase(string str) {
	for (int i = 0; i < str.length() - 2; i++)
		if (islower(str[i]) && islower(str[i + 2]) && str[i] + 1 == str[i + 1] && str[i] + 2 == str[i + 2]) return true;
	return false;
}

// zad: 2
bool consecutiveUpperCase(string str) {
	for (int i = 0; i < str.length() - 2; i++)
		if (isupper(str[i]) && isupper(str[i + 2]) && str[i] + 1 == str[i + 1] && str[i] + 2 == str[i + 2]) return true;
	return false;
}

// zad: 2
bool consecutiveDigits(string str) {
	for (int i = 0; i < str.length() - 2; i++)
		if (isdigit(str[i]) && isdigit(str[i + 2]) && str[i] + 1 == str[i + 1] && str[i] + 2 == str[i + 2]) return true;
	return false;
}

// zad: 2
bool repeatingCharacters(string str) {
	for (int i = 0; i < str.length() - 2; i++)
		if (str[i] == str[i + 1] == str[i + 2]) return true;
	return false;
}
