#include "Tabla.h"
#include "Igrac.h"
#include "Polje.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	Tabla::setInstance();
	Tabla* tabla = Tabla::getInstance();

	int k;
	cout << "Unesite broj krugova: ";
	cin >> k;
	
	ifstream uldat("polje.txt");
	if (!uldat.good())
		cout << "Datoteka nije ispravna!";
	tabla->ucitaj(uldat);
	uldat.close();

	tabla->start(k);

}