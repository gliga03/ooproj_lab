#include "Predmet.h"

Predmet::Predmet(Odsek* odsek, const char* naziv, const char* sifra, int ESPB, int semestar, bool obavezan) {

	this->odsek = odsek;

	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);

	this->sifra = new char[strlen(sifra) + 1];
	strcpy(this->sifra, sifra);

	this->ESPB = ESPB;
	this->semestar = semestar;
	this->obavezan = obavezan;

	maksimalnaPopunjenost = 200;
	trenutnaPopunjenost = 0;
	studenti = new Student * [maksimalnaPopunjenost];
	for (int i = 0; i < maksimalnaPopunjenost; i++)
		studenti[i] = 0;

}

Predmet::~Predmet() {

	if (naziv) {
		delete[] naziv;
		naziv = nullptr;
	}

	if (sifra) {
		delete[] sifra;
		sifra = nullptr;
	}

	if (studenti) {

		delete[] studenti;
		studenti = nullptr;

	}

}

void Predmet::dodajStudenta(Student* s) {

	if (trenutnaPopunjenost + 1 == maksimalnaPopunjenost)
		throw new exception("Predmet je dostigao maksimalan broj studenata!");

	studenti[trenutnaPopunjenost] = s;
	trenutnaPopunjenost++;
	
}

void Predmet::ukloniStudenta(Student* s) {

	bool nadjen = false;
	int i = 0;
	while (i < trenutnaPopunjenost && !nadjen) {
		if (studenti[i] == s) {
			nadjen = true;
		}
		else
			i++;
	}

	if (nadjen)
		studenti[i] = 0;
	else
		cout << "Navedeni student ne slusa ovaj predmet!";

}

void Predmet::print() {

	cout << "(" << naziv << ", " << sifra << ", " << ESPB << ", " << semestar << ", " << obavezan << ")" << endl;


}