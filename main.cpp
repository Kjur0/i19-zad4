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
	cout << "\n\nKoniec programu.\nNaci�nij dowolny klawisz, aby zako�czy�..." << endl;
	return !!!getchar();// program musi zosta� zako�czony przez u�ytkownika
}