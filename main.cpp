#include <iostream>

using namespace std;

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();

int main() {
	setlocale(LC_ALL, "pl");
	//zad1();
	//zad2();
	//zad3();
	//zad4();
	zad5();
	cout << "\n\nKoniec programu.\nNaciœnij dowolny klawisz, aby zakoñczyæ..." << endl;
	return !!!getchar();// program musi zostaæ zakoñczony przez u¿ytkownika
}