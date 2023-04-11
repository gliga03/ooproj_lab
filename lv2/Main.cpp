#include "Fakultet.h"

int main() {

	Fakultet::setInstance("Elektronski fakultet", "Aleksandra Medvedeva 14", "Nis", "01-01-1960", 6);
	Fakultet* fakultet = Fakultet::getInstance();

	Student* s1 = new Student("Dusan", "Gligorijevic", 18608, "0202003734925", "02-02-2003", "01-10-2021", "dusan.gligorijevic@elfak.rs");
	Student* s2 = new Student("Marko", "Markovic", 19502, "1104998730581", "11-04-1998", "01-10-2017", "marko.markovic@elfak.rs");
	Student* s3 = new Student("Mila", "Milosevic", 17203, "1112000737810", "11-12-2000", "01-10-2019", "mila.milosevic@elfak.rs");
	Student* s4 = new Student("Lazar", "Blagojevic", 19290, "2008003732356", "20-08-2003", "01-10-2022", "lazar.blagojevic@elfak.rs");
	Student* s5 = new Student("Jelena", "Cirkovic", 14403, "1305995738251", "13-05-1995", "01-10-2014", "jelena.cirkovic@elfak.rs");

	fakultet->dodajOdsek("Racunarstvo i informatika", 180);
	fakultet->dodajOdsek("Komunikacije i informacione tehnologije", 30);

	// dodavanje predmeta za RII odsek
	fakultet->dodajPredmet("Racunarstvo i informatika", "Objektno orijentisano projektovanje", "3OEP4O01", 6, 4, true);
	fakultet->dodajPredmet("Racunarstvo i informatika", "Strukture podataka", "3OEP4O02", 6, 4, true);
	fakultet->dodajPredmet("Racunarstvo i informatika", "Programski jezici", "3OEP4O03", 6, 4, true);
	fakultet->dodajPredmet("Racunarstvo i informatika", "Arhitektura i organizacija racunara 2", "3OEP4O04", 6, 4, true);
	fakultet->dodajPredmet("Racunarstvo i informatika", "Matricna izracunavanja", "3OEP4A01", 3, 4, false);
	fakultet->dodajPredmet("Racunarstvo i informatika", "Teorija grafova", "3OEP4A02", 3, 4, false);

	// dodavanje predmeta za KIT odsek
	fakultet->dodajPredmet("Komunikacije i informacione tehnologije", "Digitalna elektronika", "3OEK4O01", 6, 4, true);
	fakultet->dodajPredmet("Komunikacije i informacione tehnologije", "Komunikaciona akustika", "3OEK4O02", 6, 4, true);
	fakultet->dodajPredmet("Komunikacije i informacione tehnologije", "Uvod u digitalne komunikacije", "3OEK4O03", 6, 4, true);
	fakultet->dodajPredmet("Komunikacije i informacione tehnologije", "Primenjena elektromagnetika", "3OEK4O04", 3, 4, false);
	fakultet->dodajPredmet("Komunikacije i informacione tehnologije", "Verovatoca i statistika", "3OEK4A01", 3, 4, false);

	fakultet->upisiStudenta(s1, "Racunarstvo i informatika");
	fakultet->upisiStudenta(s2, "Komunikacije i informacione tehnologije");
	fakultet->upisiStudenta(s3, "Racunarstvo i informatika");
	fakultet->upisiStudenta(s4, "Komunikacije i informacione tehnologije");
	fakultet->upisiStudenta(s5, "Racunarstvo i informatika");

	s1->izaberiPredmet("3OEP4O02");
	s1->izaberiPredmet("3OEP4O04");
	s1->izaberiPredmet("3OEP4A02");

	s2->izaberiPredmet("3OEK4O01");
	s2->izaberiPredmet("3OEK4O04");

	s3->izaberiPredmet("3OEP4A02");
	s3->izaberiPredmet("3OEP4A01");
	s3->izaberiPredmet("3OEP4O02");

	s4->izaberiPredmet("3OEK4O02");
	s4->izaberiPredmet("3OEK4O03");
	s4->izaberiPredmet("3OEK4A01");

	s5->izaberiPredmet("3OEP4A02");


	fakultet->print();

	s1->print();
	cout << "ESPB: " << s1->getESPB() << endl;

	s3->print();
	cout << "ESPB: " << s3->getESPB() << endl;

	s1->promeniPredmet("3OEP4O04", "3OEP4O03");
	s2->promeniPredmet("3OEK4O01", "3OEK4O03");

	fakultet->print();

	return 0;

}