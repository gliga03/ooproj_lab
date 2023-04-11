#pragma once

#include "Predmet.h"
#include "Odsek.h"

class Predmet;
class Odsek;

class Student
{
private:
	char* ime;
	char* prezime;
	int brojIndeksa;
	char* JMBG;
	char* datumRodjenja;
	char* datumUpisa;
	char* email;

	Odsek* odsek;
	Predmet** predmeti;
	int maksimalniBrojPredmeta;
	int trenutniBrojPredmeta = 0;

public:
	Student(const char* ime, const char* prezime, int brojIndeksa, const char* JMBG, const char* datumRodjenja, const char* datumUpisa, const char* email);
	~Student();
	void izaberiPredmet(const char* predmet);
	void promeniPredmet(const char* sifra1, const char* sifra2);
	int getESPB();
	void setOdsek(Odsek* o);

	void print();
	void printPredmeti();

};

