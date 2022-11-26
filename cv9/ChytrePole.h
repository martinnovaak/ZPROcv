#pragma once
#define cislo int

// Struktura reprezenzujici "Chytre Pole"
struct ChytrePole
{
	cislo* pole = nullptr; // pole cisel
	int n = 0;		   // maximalni delka pole
	int k = -1;			   // index posledniho pole
};

void alokuj(ChytrePole& chp, int delka); 
void zrus(ChytrePole& chp);
void vypisChytrePole(ChytrePole& chp);
void pridat(ChytrePole& chp, cislo c);
bool prazdne(ChytrePole& chp);
int pocetPrvku(ChytrePole& chp);
int delkaPole(ChytrePole& chp);

//DU
void smazPosledni(ChytrePole& chp);
bool smaz(ChytrePole& chp, unsigned int index);
ChytrePole spoj(const ChytrePole& chp1, const ChytrePole& chp2);
ChytrePole operator+(const ChytrePole& chp1, const ChytrePole& chp2);