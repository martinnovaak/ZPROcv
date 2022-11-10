#pragma once

//#define Data int
using Data = int;
class ChytrePole;

struct Prvek // Node
{
	Data data;
	Prvek* dalsi;
};

struct Seznam
{
	//Prvek* prvni;
	//Prvek* posledni;
	Prvek* hlava; // head
	Prvek* ocas; // tail
};


void vytvor(Seznam& s);
void vloz_na_zacatek(Seznam& s, Data co);
void vloz_na_konec(Seznam& s, Data co);
void vypis(Seznam& s);
void odstran_prvni(Seznam& s);
bool prazdny(Seznam& s);
void vyprazdni(Seznam& s);
void zrus(Seznam& s);
//___________________________________________
Prvek* najdi(Seznam& s, Data hodnota);
void odstran_za(Seznam& s, Prvek* predek);
void odstran(Seznam& s, Prvek* ten);
void odstran_posledni(Seznam& s);
void vloz_za(Seznam& s, Data co, Prvek* predek);
Prvek* najdi_nejmensi(Seznam& s);
void serad(Seznam& s);

//______________________________________________
// DU8
int velikost(const Seznam& s);
void otoc_seznam(Seznam& s);
void smaz_prvky_prvky(Seznam& s);
Seznam prekopiruj(const ChytrePole& k);
Seznam prekopiruj(const Seznam& s);
Data josef(const Seznam& s);
