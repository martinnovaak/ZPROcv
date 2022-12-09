#include "ChytrePole.h"
#include <iostream>
using namespace std;

bool ChytrePole::prazdne()
{
	return k == 0;
}

void ChytrePole::inicializuj(unsigned int delka)
{
	if (prazdne())
	{
		pole = new cislo[delka];
		k = 0;
		n = delka;
	}
}

void ChytrePole::zrus()
{
	delete[] pole;
	k = 0;
	n = 0;
}

// konstruktor
ChytrePole::ChytrePole()
{
	inicializuj(4);
}

// konstruktor s parametrem
ChytrePole::ChytrePole(unsigned int delka)
{
	inicializuj(delka);
}

// kopirovaci konstruktor
ChytrePole::ChytrePole(ChytrePole& chp) : ChytrePole(chp.n)
{
	this->k = chp.k;
	for (unsigned int i = 0; i < chp.k; i++)
	{
		this->pole[i] = chp.pole[i];
	}
}

// destruktor
ChytrePole::~ChytrePole()
{
	zrus();
}

// vypis chytreho pole
void ChytrePole::vypis()
{
	for (int i = 0; i < k; i++)
		cout << pole[i] << " ";
	cout << endl;
}

// vlozi na konec chytreho pole cislo c
void ChytrePole::pridat_na_konec(cislo c)
{
	if (k >= n) // pokud je pole plne
	{
		// vytvorime nove pole, ktere bude mit 2x tolik prvku
		n *= 2;
		cislo* nPole = new cislo[n];
		for (int i = 0; i < k; i++)
			nPole[i] = pole[i]; // prekopirujeme data do noveho pole
		delete[] pole; // stare pole smazeme
		pole = nPole;  // ukazatel na pole zmenime na nove pole
	}
	pole[k] = c;   // na k-tou pozici ulozime cislo c
	k++;			   // pocet prvku se zvetsil o 1
}

int ChytrePole::delka()
{
	return k;
}

// getter i-teho prvku
cislo ChytrePole::get(unsigned int i) const
{
	if(i < k)
		return this->pole[i];
	return -1;
}
