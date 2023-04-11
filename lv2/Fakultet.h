#pragma once
#include "Student.h"
#include "Odsek.h"
#include <iostream>
#include <string.h>
#include <exception>
using namespace std;

class Odsek;
class Student;

class Fakultet
{
private:
	char* naziv;
	char* adresa;
	char* grad;
	char* datumOsnivanja;

	Odsek** odseci;
	int trenutniBrojOdseka;
	int maksimalniBrojOdseka;
	
	static Fakultet* instanca;
	Fakultet(const char* naziv, const char* adresa, const char* grad, const char* datumOsnivanja, int maksimalniBrojOdseka);

public:

	~Fakultet();

	static Fakultet* getInstance() {
		return instanca;
	}

	static void setInstance(const char* naziv, const char* adresa, const char* grad, const char* datumOsnivanja, int maksimalniBrojOdseka)
	{
		if (instanca == nullptr)
		{
			instanca = new Fakultet(naziv, adresa, grad, datumOsnivanja, maksimalniBrojOdseka);
		}
	}

	void dodajOdsek(const char* naziv, int kapacitet);
	Odsek* getOdsek(const char* naziv);
	void dodajPredmet(const char* odsek, const char* naziv, const char* sifra, int ESPB, int semestar, bool obavezan);
	void upisiStudenta(Student* s, const char* odsek);
	void printPredmeti();
	void printStudenti();
	void print();

};