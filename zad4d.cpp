#include <iostream>
#include <regex>

using namespace std;

bool isValid(const string& phoneNumber) {
    regex pattern("^\\d{11}$");
    return regex_match(phoneNumber, pattern);
}

std::string formatNumber(const std::string& phoneNumber) {
    regex pattern("(\\d{2})(\\d{3})(\\d{3})(\\d{3})");
    return regex_replace(phoneNumber, pattern, "+$1 $2-$3-$4");
}

void zad4() {
    string phoneNumber;
    cout << "WprowadŸ numer telefonu: ";
    getline(cin, phoneNumber);

    if (isValid(phoneNumber)) {
        cout << "Sformatowany numer telefonu: " << formatNumber(phoneNumber) << endl;
    } else {
        cout << "Nieprawid³owy numer telefonu." << endl;
    }
}
