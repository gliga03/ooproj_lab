#include "Fakultet.h"

Fakultet* Fakultet::instanca = nullptr;

Fakultet::Fakultet(const char* naziv, const char* adresa, const char* grad, const char* datumOsnivanja, int maksimalniBrojOdseka) {

	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);

	this->adresa = new char[strlen(adresa) + 1];
	strcpy(this->adresa, adresa);

	this->grad = new char[strlen(grad) + 1];
	strcpy(this->grad, grad);

	this->datumOsnivanja = new char[strlen(datumOsnivanja) + 1];
	strcpy(this->datumOsnivanja, datumOsnivanja);

	this->trenutniBrojOdseka = 0;
	this->maksimalniBrojOdseka = maksimalniBrojOdseka;
	odseci = new Odsek * [maksimalniBrojOdseka];
	for (int i = 0; i < maksimalniBrojOdseka; i++)
		odseci[i] = 0;

}

Fakultet::~Fakultet() {

	if (naziv) {
		delete[] naziv;
		naziv = nullptr;
	}

	if (adresa) {
		delete[] adresa;
		adresa = nullptr;
	}

	if (grad) {
		delete[] grad;
		grad = nullptr;
	}
		
	if (datumOsnivanja) {
		delete[] datumOsnivanja;
		datumOsnivanja = nullptr;
	}

	if (odseci) {

		for (int i = 0; i < trenutniBrojOdseka; i++)
		{
			delete odseci[i];
			odseci[i] = nullptr;
		}

		delete[] odseci;
		odseci = nullptr;

	}

}

void Fakultet::dodajOdsek(const char* naziv, int kapacitet) {

	Odsek* odsek = new Odsek(this, naziv, kapacitet);
	if (trenutniBrojOdseka + 1 == maksimalniBrojOdseka)
		throw new exception("Maksimalni broj odseka je dostignut!");

	odseci[trenutniBrojOdseka] = odsek;
	trenutniBrojOdseka++;

}

void Fakultet::upisiStudenta(Student* s, const char* imeOdseka) {

	Odsek* odsek = getOdsek(imeOdseka);
	if (odsek)
		odsek->dodajStudenta(odsek, s);

}

void Fakultet::dodajPredmet(const char* odsek, const char* naziv, const char* sifra, int ESPB, int semestar, bool obavezan) {

	Odsek* temp = getOdsek(odsek);
	
	if (odsek) {
		temp->dodajPredmet(naziv, sifra, ESPB, semestar, obavezan);
	}
	else
		cout << "Ne postoji zadati odsek na ovom fakultetu!";

}

Odsek* Fakultet::getOdsek(const char* naziv) {

	Odsek* temp = nullptr;
	bool nadjen = false;
	int i = 0;
	while (i < trenutniBrojOdseka && !nadjen) {

		if (!(strcmp(odseci[i]->getName(), naziv))) {
			temp = odseci[i];
			nadjen = true;
		}

		i++;

	}

	return temp;

}

void Fakultet::printPredmeti() {

	for (int i = 0; i < trenutniBrojOdseka; i++) {

		odseci[i]->printPredmeti();
		cout << "--------------------------------------------------------------------------------------------------" << endl;

	}

}

void Fakultet::printStudenti() {

	for (int i = 0; i < trenutniBrojOdseka; i++) {

		odseci[i]->printStudenti();
		cout << "--------------------------------------------------------------------------------------------------" << endl;

	}

}

void Fakultet::print() {

	cout << "--------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < trenutniBrojOdseka; i++) {

		odseci[i]->print();
		cout << "--------------------------------------------------------------------------------------------------" << endl;

	}

}