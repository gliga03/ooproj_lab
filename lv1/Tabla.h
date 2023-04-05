#pragma once
#include "Igrac.h"
#include "Polje.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Igrac;

class Tabla
{
private:
	Polje*** t;
	Igrac* igrac;

	static Tabla* instanca;
	Tabla();
public:
	static Tabla* getInstance() {
		return instanca;
	}

	static void setInstance()
	{
		if (instanca == nullptr)
		{
			instanca = new Tabla();
		}
	}

	~Tabla();
	void ucitaj(ifstream& f);
	void print();

	void postavi(int i, int j, Polje* polje);
	bool pripadaTabli(int i, int j);
	Polje* getPolje(int i, int j) { return t[i][j]; }
	Polje* scanForP(Polje* prvo);
	void findStart();

	void start(int k);

};