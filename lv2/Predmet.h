#pragma once

#include "Student.h"
#include <string.h>

class Student;
class Odsek;

class Predmet
{
private:
	char* naziv;
	char* sifra;
	int ESPB;
	int semestar;
	bool obavezan;

	Student** studenti;
	int trenutnaPopunjenost;
	int maksimalnaPopunjenost;

	Odsek* odsek;

	friend class Odsek;
	
	Predmet(Odsek* odsek, const char* naziv, const char* sifra, int ESPB, int semestar, bool obavezan);
	~Predmet();
public:
	int getESPB() { return ESPB; }
	char* getSifra() { return sifra; }
	void dodajStudenta(Student* s);
	void ukloniStudenta(Student* s);

	void print();

};

