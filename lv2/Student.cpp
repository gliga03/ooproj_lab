#include "Student.h"

Student::Student(const char* ime, const char* prezime, int brojIndeksa, const char* JMBG, const char* datumRodjenja, const char* datumUpisa, const char* email) {

	this->odsek = 0;

	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);

	this->prezime = new char[strlen(prezime) + 1];
	strcpy(this->prezime, prezime);

	this->JMBG = new char[strlen(JMBG) + 1];
	strcpy(this->JMBG, JMBG);

	this->datumRodjenja = new char[strlen(datumRodjenja) + 1];
	strcpy(this->datumRodjenja, datumRodjenja);

	this->datumUpisa = new char[strlen(datumUpisa) + 1];
	strcpy(this->datumUpisa, datumUpisa);

	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);

	this->brojIndeksa = brojIndeksa;

	maksimalniBrojPredmeta = 12;
	predmeti = new Predmet * [maksimalniBrojPredmeta];
	for (int i = 0; i < maksimalniBrojPredmeta; i++)
		predmeti[i] = 0;

}

Student::~Student() {

	if (ime) {
		delete[] ime;
		ime = nullptr;
	}

	if (prezime) {
		delete[] prezime;
		prezime = nullptr;
	}

	if (JMBG) {
		delete[] JMBG;
		JMBG = nullptr;
	}


	if (datumRodjenja) {
		delete[] datumRodjenja;
		datumRodjenja = nullptr;
	}

	if (datumUpisa) {
		delete[] datumUpisa;
		datumUpisa = nullptr;
	}

	if (email) {
		delete[] email;
		email = nullptr;
	}

	if (predmeti) {

		delete[] predmeti;
		predmeti = nullptr;

	}

}

void Student::izaberiPredmet(const char* sifra) {

	Predmet* predmet = odsek->getPredmet(sifra);	
	if (predmet) {
		predmet->dodajStudenta(this);
		predmeti[trenutniBrojPredmeta] = predmet;
		trenutniBrojPredmeta++;
	}
	else
		cout << "Ne postoji predmet sa datom sifrom!";

}

void Student::promeniPredmet(const char* sifra1, const char* sifra2) {

	Predmet* predmet1 = odsek->getPredmet(sifra1);
	Predmet* predmet2 = odsek->getPredmet(sifra2);

	bool nadjen = false;
	int i = 0;
	while (i < trenutniBrojPredmeta && !nadjen) {
		if (predmet1 == predmeti[i])
			nadjen = true;
		else
			i++;
	}

	if (nadjen) {
		predmet1->ukloniStudenta(this);
		predmeti[i] = predmet2;
		predmet2->dodajStudenta(this);
	}
	else {
		izaberiPredmet(sifra2);
	}
	
}

int Student::getESPB() {

	int broj = 0;
	for (int i = 0; i < trenutniBrojPredmeta; i++) {
		broj = broj + predmeti[i]->getESPB();
	}
	return broj;

}

void Student::setOdsek(Odsek* o) {

	odsek = o;

}

void Student::print() {

	cout << "(" << ime << " " << prezime << ", " << brojIndeksa << ", " << JMBG << ", " << datumRodjenja << ", " << datumUpisa << ", " << email << ")" << endl;

}

void Student::printPredmeti() {

	print();

	cout << endl;
	cout << "Predmeti: " << endl;

	for (int i = 0; i < trenutniBrojPredmeta; i++) {

		predmeti[i]->print();

	}

	cout << endl;

}