#pragma once
#include "Tabla.h"
#include "Polje.h"

class Tabla;

class Igrac
{
private:
	int i;
	int j;
	int brKrugova;

	int brPolja;
	bool Hpolje;
	bool Xpolje;
	bool Ppolje;
	bool turnRight;
	Tabla* tabla;
public:
	Igrac(Tabla* tabla) {
		i = j = 0;
		brPolja = 0;
		brKrugova = 0;
		turnRight = false;
		Hpolje = false;
		Xpolje = false;
		Ppolje = false;
		this->tabla = tabla;
	}

	void setPos(int i, int j) { this->i = i; this->j = j; }
	bool playerPosition(int i, int j) { return this->i == i && this->j == j; }

	Polje* PoljeIgraca();
	void move(int p);
	void moveOnce();

	int getBrKrugova() { return brKrugova; }
	bool isStart() { return PoljeIgraca()->getSimbol() == 'O'; }

};