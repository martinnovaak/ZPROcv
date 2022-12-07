#include "ChytrePole.h"
#include <iostream>
using namespace std;

bool prazdne(ChytrePole& chp)
{
	return chp.k == 0;
}

void inicializuj(ChytrePole& chp, unsigned int delka)
{
	if (prazdne(chp))
	{
		chp.pole = new cislo[delka];
		chp.k = 0;
		chp.n = delka;
	}
}

void zrus(ChytrePole& chp)
{
	delete[] chp.pole;
	chp.k = 0;
	chp.n = 0;
}

void vypis(ChytrePole& chp)
{
	for (int i = 0; i < chp.k; i++)
		cout << chp.pole[i] << " ";
	cout << endl;
}

// vlozi na konec chytreho pole cislo c
void pridat_na_konec(ChytrePole& chp, cislo c)
{
	if (chp.k >= chp.n) // pokud je pole plne
	{
		// vytvorime nove pole, ktere bude mit 2x tolik prvku
		chp.n *= 2; 
		cislo* nPole = new cislo[chp.n]; 
		for (int i = 0; i < chp.k; i++)
			nPole[i] = chp.pole[i]; // prekopirujeme data do noveho pole
		delete[] chp.pole; // stare pole smazeme
		chp.pole = nPole;  // ukazatel na pole zmenime na nove pole
	}
	chp.pole[chp.k] = c;   // na k-tou pozici ulozime cislo c
	chp.k++;			   // pocet prvku se zvetsil o 1
}

int delka(ChytrePole& chp)
{
	return chp.k;
}