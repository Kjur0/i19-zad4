#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, string> morseCodeMap = {
	{'A', ".-"},
	{'B', "-..."},
	{'C', "-.-."},
	{'D', "-.."},
	{'E', "."},
	{'F', "..-."},
	{'G', "--."},
	{'H', "...."},
	{'I', ".."},
	{'J', ".---"},
	{'K', "-.-"},
	{'L', ".-.."},
	{'M', "--"},
	{'N', "-."},
	{'O', "---"},
	{'P', ".--."},
	{'Q', "--.-"},
	{'R', ".-."},
	{'S', "..."},
	{'T', "-"},
	{'U', "..-"},
	{'V', "...-"},
	{'W', ".--"},
	{'X', "-..-"},
	{'Y', "-.--"},
	{'Z', "--.."},
	{'1', ".----"},
	{'2', "..---"},
	{'3', "...--"},
	{'4', "....-"},
	{'5', "....."},
	{'6', "-...."},
	{'7', "--..."},
	{'8', "---.."},
	{'9', "----."},
	{'0', "-----"},
	{',', "--..--"},
	{'.', ".-.-.-"},
	{'?', "..--.."},
	{';', "-.-.-."},
	{':', "---..."},
	{'\'', ".----."},
	{'-', "-....-"},
	{'/', "-..-."},
	{'(', "-.--."},
	{')', "-.--.-"},
	{'_', "..--.-"},
	{'=', "-...-"},
	{'+', ".-.-."},
	{'@', ".--.-."},
	{'!', "-.-.--"},
	{' ', "/"}
};

string convertToMorse(const string& input) {
	string morseCode;
	for (char c : input) {
		c = toupper(c);
		morseCode += morseCodeMap[c] + " ";
	}
	return morseCode;
}

void zad5() {
	string input;
	cout << "Wprowad� ci�g znak�w: ";
	getline(cin, input);
	cout << "Ci�g znak�w w alfabecie Morse'a: " << convertToMorse(input) << endl;
}