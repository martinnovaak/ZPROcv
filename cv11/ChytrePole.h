#pragma once
using cislo = int;

// Struktura reprezenzujici "Chytre Pole"
class ChytrePole
{
private:
	cislo* pole;		  // pole cisel
	unsigned int n;		      // maximalni delka pole
	unsigned int k;			  // pocet prvku - zaroven index pridavaneho prvku

	void inicializuj(unsigned int delka);   // inicializacni funkce Chytreho Pole
	void zrus();						// zruseni dynamicky alokovane pameti
public:
	ChytrePole();
	ChytrePole(unsigned int delka);
	ChytrePole(ChytrePole& chp); // kopirovaci konstruktor
	~ChytrePole();
	
	void vypis();					// vypis pole do konzole
	void pridat_na_konec(cislo c);  // vlozeni prvku na konec Chytreho Pole
	bool prazdne();					// funkce vracejici informaci, zda-li je Chytre Pole prazdne
	int  delka();					// pocet prvku pole

	cislo get(unsigned int i) const; // get at
};

