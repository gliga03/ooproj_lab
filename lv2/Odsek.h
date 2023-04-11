#pragma once

#include "Fakultet.h"
#include "Student.h"
#include "Predmet.h"
#include <string.h>

class Fakultet;
class Student;
class Predmet;

class Odsek
{
private:
	friend class Fakultet;
	char* naziv;
	Fakultet* fakultet;

	Student** studenti;
	int trenutnaPopunjenost;
	int maksimalnaPopunjenost;

	Predmet** predmeti;
	int trenutniBrojPredmeta;
	int maksimalniBrojPredmeta;

	Odsek(Fakultet* fakultet, const char* naziv, int kapacitet);
	~Odsek();

public:

	char* getName() { return naziv; }
	Predmet* getPredmet(const char* sifra);
	void dodajPredmet(const char* naziv, const char* sifra,int ESPB, int semestar, bool obavezan);
	void dodajStudenta(Odsek* o, Student* s);
	void printPredmeti();
	void printStudenti();
	void print();

};