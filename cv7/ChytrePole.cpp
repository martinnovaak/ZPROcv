#include "ChytrePole.h"
#include <iostream>
using namespace std;

bool prazdne(ChytrePole& chp)
{
	return chp.pole == nullptr;
	/*
	if (chp.k == -1)
		return true;
	return false;
	*/
}

void alokuj(ChytrePole& chp, int delka)
{
	if (prazdne(chp))
	{
		chp.pole = new cislo[delka];
		chp.k = -1;
		chp.n = delka;
	}
}


void zrus(ChytrePole& chp)
{
	delete[] chp.pole;
	chp.k = -1;
	chp.n = 0;
}

void vypisChytrePole(ChytrePole& chp)
{
	for (int i = 0; i <= chp.k; i++)
		cout << chp.pole[i] << " ";
	cout << endl;
}

void pridat(ChytrePole& chp, cislo c)
{
	chp.k++;
	if (chp.k >= chp.n)
	{
		chp.n *= 2;
		cislo* nPole = new cislo[chp.n];
		for (unsigned int i = 0; i < chp.k; i++)
		{
			nPole[i] = chp.pole[i];
		}
		delete[] chp.pole;
		chp.pole = nPole;
	}
	chp.pole[chp.k] = c;
}

int pocetPrvku(ChytrePole& chp)
{
	return chp.k + 1;
}

int delkaPole(ChytrePole& chp)
{
	return chp.n;
}

//___________________________________________________________
//du7

// funkce odstrani posledni prvek z pole a upravi atribut k dle potreby
void smazPosledni(ChytrePole& chp)
{
	/*
	TODO
	*/
}
// max 0,3 bodu


// Napiste funkci, ktera smaze prvek na zadanym indexu v parametru funkce a upravi atribut k dle potreby
// Cele pole je potom nutne presunout
// tzn. mam-li ChytrePole: 0 1 2 3 4 a odstranil bych z nej cislo 3 tak po odstraneni
// bude ChytrePole vypadat: 0 1 2 4
// funkce nasledne vrati true, pokud se podarilo prvek smazat, jinak vrati false
bool smaz(ChytrePole& chp, unsigned int index)
{
	/*
	TODO
	*/
}
// max 0,7 bodu, pokud budou oreseny vsechny mozne chyby

// Napiste funkci, ktera vezme dve ChytrePole a vytvori z nich jedno nove, ktere bude obsahovat
// prvky obou poli
// mam-li jedno pole s prvky 1 2 3 4 a druhe pole 5 6 7 8
// tak funkce spoj vrati ChytrePole s prvky 1 2 3 4 5 6 7 8 
// pozor je treba krome atributu k oresit i atribut n !
ChytrePole spoj(const ChytrePole& chp1, const ChytrePole& chp2)
{
	/*
	TODO
	*/
}
// max 1 bod