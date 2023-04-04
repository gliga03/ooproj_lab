#pragma once
class Polje
{
private:
	char simbol;
	int i;
	int j;

public:
	Polje(int i, int j, char c) { 
		this->i = i;
		this->j = j;
		simbol = c; 
	}

	char getSimbol() { return simbol; }

	int getI() { return i; }
	int getJ() { return j; }

};

