#include "Tabla.h"

Tabla* Tabla::instanca = nullptr;

Tabla::Tabla() {

	igrac = new Igrac(this);
	t = new Polje * *[20];

	for (int i = 0; i < 20; i++) {

		t[i] = new Polje * [20];

		for (int j = 0; j < 20; j++)
			t[i][j] = 0;

	}

}

Tabla::~Tabla() {

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			delete t[i][j];
			t[i][j] = nullptr;
		}
	}

	for (int i = 0; i < 20; i++)
		delete[] t[i];

	delete[] t;
	t = nullptr;

}

void Tabla::ucitaj(ifstream& f) {

	char c;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c = f.get();
			if (c == ' ')
				this->postavi(i, j, new Polje(i, j, '0'));
			else
				this->postavi(i, j, new Polje(i, j, c));
		}
		f.ignore();
	}

}

void Tabla::postavi(int i, int j, Polje* polje) {

	if (!pripadaTabli(i, j))
		return;

	if (this->t[i][j] != 0)
		delete this->t[i][j];

	this->t[i][j] = polje;

}

bool Tabla::pripadaTabli(int i, int j) {

	if (i < 0 || i > 19)
		return false;

	if (j < 0 || j> 19)
		return false;

	if (getPolje(i, j) != 0) {
		if (getPolje(i, j)->getSimbol() == '0')
			return false;
	}

	return true;

}

void Tabla::print() {

	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (t[i][j] != 0)
			{
				if (igrac->playerPosition(i,j))
					cout << "i ";
				else {
					if (t[i][j]->getSimbol() == '0')
						cout << " " << " ";
					else
						cout << t[i][j]->getSimbol() << " ";
				}
			}
			else
			{
				cout << " " << " ";
			}
		}
		cout << endl;
	}

	cout << endl;

}

void Tabla::start(int k) {

	srand(time(0));
	int i = 0;
	findStart();
	while (i < k) {
		print();
		int c;
		int kockica = 0;;
		cout << "Pritisnite taster 0 da biste bacili kockicu: ";
		cin >> c;
		if (c == 0) {
			kockica = rand() % 6 + 1;
		}
		else if (c>=1 && c<=6) {
			kockica = c;
		}
		cout << "Kockica: " << kockica << endl;
		igrac->move(kockica);
		i = igrac->getBrKrugova();
	}
	print();

	cout << "Igrac je presao " << k << " krugova!" << endl;


}

Polje* Tabla::scanForP(Polje* prvo) {

	Polje* temp = nullptr;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (getPolje(i,j)->getSimbol() == 'P' && getPolje(i,j) != prvo)
				temp = getPolje(i,j);
		}
	}

	return temp;
	
}

void Tabla::findStart() {

	Polje* temp = nullptr;
	bool nadjen = false;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (getPolje(i, j)->getSimbol() == 'O' && !nadjen) {
				temp = getPolje(i, j);
				nadjen = true;
			}
		}
	}

	if (temp != nullptr) {
		int i = temp->getI();
		int j = temp->getJ();
		igrac->setPos(i, j);
	}

}