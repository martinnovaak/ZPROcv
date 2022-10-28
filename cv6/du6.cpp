#include <iostream>
using namespace std;

struct Cisla
{
	double a, b, c, d;
};

/* Funkce z 5. cviceni
* bude ji treba upravit pro realna cisla !
int nacti_nezaporne()
{
	int n; // promena, do ktere ulozime vstup od uzivatele
	for (;;) // nekonecny cyklus pres prikaz for - pouzivana alternativa: while(true)
	{
		// Zacatek cyklu
		// vyzveme uzivatele k zadani nezaporneho cisla
		cout << "Zadejte nezaporne cislo: ";
		cin >> n;

		if (!cin) // a) Kontrola, zda-li nedoslo k zablokovani vstupniho proudu nespravnym vstupem
		{
			cout << "Nezadali jste cislo" << endl; // informujeme uzivatele
			cin.clear();						   // uvolneni vstupniho proudu
			cin.ignore(256, '\n');				   // vycisteni bufferu (v bufferu se totiz porad nachazi vstup, ktery nam zablokoval vstupni proud.
			//    Pokud bychom znovu zavolali cin >> n. Znovu by se nacetla tento stary vstup a opet by doslo k chybe. (vysledkem by byl nekonecny cyklus ...)
			continue; // vrat se na zacatek cyklu
		}
		if (n < 0) // b) Kontrola zda-li uzivatel nezadal zaporne cislo 
		{
			cout << "Zadali jste zaporne cislo" << endl; // informujeme uzivatele
			continue;									 // vrat se na zacatek cyklu
		}
		// (Az sem se dostaneme pouze v pripade, ze uzivatel zadal korektni nezaporny cislo na vstupu) 
		return n;  // v promenne n se nachazi nezaporne cislo -> vrat toto cislo 
		// return ukoncuje funkci tedy i zaroven nekonecny cyklus, v kterem se nachazi
	}
}
*/
// Za oreseni korektniho vstupu max 0,2 body v pripade spravneho volani z funkce main()
//____________________________________________________________________________________________________

// Funkce usporadej1 vrati strukturu Cisla tak, ze:
// v atributu a bude nejvetsi cislo, v b 2. nejvetsi, v c 3. nejvetsi a v d nejmensi
Cisla usporadej1(double a, double b, double c, double d)
{
	/*
	TODO
	*/
}
// max 0,2 bodu	v pripade spravneho volani z funkce main()
//______________________________________________________

// usporadejte pole od nejvetsiho po nejmensi
void usporadej2(double pole, unsigned int delka)
{
	/*
	TODO
	*/
}
// max 0,2 bodu v pripade spravneho volani z funkce main()
//______________________________________________________


// usporadejte parametry funkce podle velikosti od nejvetsiho po nejmensi pomoci ukazatelu
void usporadej3(double* a, double* b, double* c, double* d)
{
	/*
	TODO
	*/
}
// az funkce skonci v a bude ulozena nejvetsi hodnota, v 2. nejvetsi, ...
// max 0,2 bodu v pripade spravneho volani z funkce main()
//______________________________________________________


// usporadejte parametry funkce podle velikosti od nejvetsiho po nejmensi pomoci referenci (odkazu)
void usporadej4(double& a, double& b, double& c, double& d)
{
	/*
	TODO
	*/
}
// az funkce skonci v a bude ulozena nejvetsi hodnota, v 2. nejvetsi, ...
// max 0,2 bodu v pripade spravneho volani z funkce main()
//______________________________________________________

// pomocna funkce pro ukladani hodnot pres reference
void uloz(double& a1, double& b1, double& c1, double& d1, double a, double b, double c, double d)
{
	a1 = a;
	b1 = b;
	c1 = c;
	d1 = d;
}

int main()
{
	double a, b, c, d;
	/*
	TODO
	Ziskejte od uzivatele 4 realna cisla a,b,c,d.
	Pozor na spatne vstupy od uzivatele, jiz jsme si ukazovali na cv5, jak jim predejit.
	Naprogramovanou funkci z 5. cviceni doporucuji pouzit. Bude ji ovsem potreba modifikovat
	pro realna cisla. Navic ted vstup od uzivatele klidne muze byt zaporne cislo!
	*/

	/*
	TODO
	zavolejte funkci usporadej1 a nasledne vypiste vracene prvky od nejvetsiho po nejmensi
	*/

	/*
	TODO 
	vytvorte si pole o 4 prvcich {a, b, c, d} nasledne zavolejte funkci usporadej2 
	a nakonec pole vypiste
	*/

	double a1, b1, c1, d1;
	uloz(a1, b1, c1, d1, a, b, c, d);
	/*
	TODO 
	zavolejte spravnym zpusobem funkci usporadej3
	*/
	cout << a1 << ", " << b1 << ", " << c1 << ", " << d << endl;
	
	uloz(a1, b1, c1, d1, a, b, c, d);
	/*
	TODO 
	Zavolejte spravnym zpusobem funkci usporadej4
	*/
	cout << a1 << ", " << b1 << ", " << c1 << ", " << d << endl;
}