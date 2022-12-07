#pragma once
using cislo = int;

// Struktura reprezenzujici "Chytre Pole"
struct ChytrePole
{
	cislo* pole = nullptr;		  // pole cisel
	unsigned int n = 0;		      // maximalni delka pole
	unsigned int k = 0;			  // pocet prvku - zaroven index pridavaneho prvku
};

void inicializuj(ChytrePole& chp, unsigned int delka);   // inicializacni funkce Chytreho Pole
void zrus(ChytrePole& chp);						// zruseni dynamicky alokovane pameti
void vypis(ChytrePole& chp);					// vypis pole do konzole
void pridat_na_konec(ChytrePole& chp, cislo c); // vlozeni prvku na konec Chytreho Pole
bool prazdne(ChytrePole& chp);					// funkce vracejici informaci, zda-li je Chytre Pole prazdne
int  delka(ChytrePole& chp);					// pocet prvku pole