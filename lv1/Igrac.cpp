#include "Igrac.h"

Polje* Igrac::PoljeIgraca() {

	return tabla->getPolje(i,j);

}

void Igrac::move(int p) {

	char c = PoljeIgraca()->getSimbol();

	if (c == 'S')
		turnRight = true;

	if (c == 'T')
		turnRight = false;

	int broj = p;

	if (c == 'H') {
		if (Hpolje) {
			broj = brPolja * 2;
			brPolja = 0;
			Hpolje = false;
		}
		else {
			broj = brPolja = p * 2;
			Hpolje = true;
		}
	}
	else {
		brPolja = 0;
		Hpolje = false;
	}

	if (c == 'X') {
		if (Xpolje) {
			broj = (p / 2 + 1) / 2 + 1;
			Xpolje = false;
		}
		else {
			broj = p / 2 + 1;
			Xpolje = true;
		}
	}
	else {
		Xpolje = false;
	}

	if (c == 'P') {

		if (!Ppolje) {
			Polje* sledece = tabla->scanForP(PoljeIgraca());
			setPos(sledece->getI(), sledece->getJ());
			Ppolje = true;
			return;
		}
		else {
			Ppolje = false;
		}

	}

	for (int i = 0; i < broj; i++) {
		moveOnce();
		if (isStart())
			brKrugova++;
	}

}

void Igrac::moveOnce() {

	if (i == 0 && j == 12 && turnRight) {
		i = i + 1;
		return;
	}

	if (i == 19 && j == 7 && turnRight) {
		i = i - 1;
		return;
	}

	if (i == 0) {
		if (tabla->pripadaTabli(i, j + 1))
			j = j + 1;
		else
			i = i + 1;
		return;
	}

	if (i == 19) {
		if (tabla->pripadaTabli(i, j - 1))
			j = j - 1;
		else
			i = i - 1;
		return;
	}

	if (j == 0) {
		if (tabla->pripadaTabli(i - 1, j))
			i = i - 1;
		else
			j = j + 1;
		return;
	}

	if (j == 19) {
		if (tabla->pripadaTabli(i + 1, j))
			i = i + 1;
		else
			j = j - 1;
		return;
	}

	if (j == 12) {
		if (tabla->pripadaTabli(i + 1, j))
			i = i + 1;
		else
			j = j + 1;
		return;
	}

	if (i == 7) {
		if (tabla->pripadaTabli(i, j + 1))
			j = j + 1;
		else
			i = i + 1;
		return;
	}

	if (j == 7) {
		if (tabla->pripadaTabli(i - 1, j))
			i = i - 1;
		else
			j = j - 1;
		return;
	}

	if (i == 11) {
		if (tabla->pripadaTabli(i, j - 1))
			j = j - 1;
		else
			i = i - 1;
		return;
	}

}