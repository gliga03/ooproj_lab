#include "Odsek.h"

Odsek::Odsek(Fakultet* fakultet, const char* naziv, int kapacitet) {

	this->fakultet = fakultet;

	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);

	maksimalnaPopunjenost = kapacitet;
	trenutnaPopunjenost = 0;
	studenti = new Student * [maksimalnaPopunjenost];
	for (int i = 0; i < maksimalnaPopunjenost; i++)
		studenti[i] = 0;

	maksimalniBrojPredmeta = 60;
	trenutniBrojPredmeta = 0;
	predmeti = new Predmet*[maksimalniBrojPredmeta];
	for (int i = 0; i < maksimalniBrojPredmeta; i++)
		predmeti[i] = 0;

}

Odsek::~Odsek() {

	if (naziv) {
		delete[] naziv;
		naziv = nullptr;
	}

	if (predmeti) {

		for (int i = 0; i < trenutniBrojPredmeta; i++)
		{
			delete predmeti[i];
			predmeti[i] = nullptr;
		}

		delete[] predmeti;
		predmeti = nullptr;

	}

	if (studenti) {

		for (int i = 0; i < trenutnaPopunjenost; i++)
		{
			delete studenti[i];
			studenti[i] = nullptr;
		}

		delete[] studenti;
		studenti = nullptr;

	}

}

void Odsek::dodajPredmet(const char* naziv, const char* sifra, int ESPB, int semestar, bool obavezan) {

	Predmet* predmet = new Predmet(this, naziv, sifra, ESPB, semestar, obavezan);
	if (trenutniBrojPredmeta + 1 == trenutniBrojPredmeta)
		throw new exception("Odsek je dostigao maksimalan broj predmeta!");

	predmeti[trenutniBrojPredmeta] = predmet;
	trenutniBrojPredmeta++;

}

Predmet* Odsek::getPredmet(const char* sifra) {

	Predmet* temp = nullptr;
	bool nadjen = false;
	int i = 0;
	while (i < trenutniBrojPredmeta && !nadjen) {

		if (!(strcmp(predmeti[i]->getSifra(), sifra))) {
			temp = predmeti[i];
			nadjen = true;
		}

		i++;
	}

	return temp;


}

void Odsek::dodajStudenta(Odsek* o, Student* s) {

	if (trenutnaPopunjenost + 1 == maksimalnaPopunjenost)
		throw new exception("Odsek je dostigao maksimalan broj studenata!");

	studenti[trenutnaPopunjenost] = s;
	trenutnaPopunjenost++;

	s->setOdsek(o);


}

void Odsek::printPredmeti() {

	cout << "Odsek: " << naziv << endl;

	cout << endl;

	for (int i = 0; i < trenutniBrojPredmeta; i++) {

		cout << i + 1 << ". ";
		predmeti[i]->print();

	}

}

void Odsek::printStudenti() {

	cout << "Odsek: " << naziv << endl;

	cout << endl;

	for (int i = 0; i < trenutnaPopunjenost; i++) {

		cout << i + 1 << ". ";
		studenti[i]->print();

	}

}

void Odsek::print() {

	cout << "Odsek: " << naziv << endl;

	cout << endl;

	for (int i = 0; i < trenutnaPopunjenost; i++) {

		cout << i+1 << ". ";
		studenti[i]->printPredmeti();

	}

}