#include "Seznam.h"
#include "ChytrePole.h"
#include <iostream>
using namespace std;

void vytvor(Seznam& s)
{
	s.hlava = s.ocas = nullptr;
}

void vloz_na_zacatek(Seznam& s, Data co)
{
	Prvek* pom = new Prvek{ co, s.hlava };
	s.hlava = pom;
	if (s.ocas == nullptr)
		s.ocas = s.hlava;
}

void vloz_na_konec(Seznam& s, Data co)
{
	if (!prazdny(s))
	{
		Prvek* pom = new Prvek{ co, nullptr };
		s.ocas->dalsi = pom;
		s.ocas = s.ocas->dalsi;
	}
	else 
	{
		vloz_na_zacatek(s, co);
	}
}

void vypis(Seznam& s)
{
	/*
	Prvek* pom = s.hlava;
	while (pom != nullptr)
	{
		cout << pom->data << ", ";
		pom = pom->dalsi;
	}
	cout << endl;
	*/

	for (Prvek* pom = s.hlava; pom != nullptr; pom = pom->dalsi)
	{
		cout << pom->data << ", ";
	}
	cout << endl;
}

void odstran_prvni(Seznam& s)
{
	if (!prazdny(s))
	{
		Prvek* pom = s.hlava;
		s.hlava = s.hlava->dalsi;
		delete pom;
	}
}

bool prazdny(Seznam& s)
{
	return s.hlava == nullptr;
}

void vyprazdni(Seznam& s)
{
	while (!prazdny(s))
	{
		odstran_prvni(s);
	}
}

void zrus(Seznam& s)
{
	vyprazdni(s);
}

Prvek* najdi(Seznam& s, Data hodnota)
{
	Prvek* pom = s.hlava;
	while (pom != nullptr && pom->data != hodnota)
	{
		//if (pom->data = hodnota)
		//	return pom;
		pom = pom->dalsi;
	}
	return pom;
}

void odstran_za(Seznam& s, Prvek* predek)
{
	Prvek* pom = predek->dalsi;
	predek->dalsi = pom->dalsi;

	if (pom == s.ocas)
		s.ocas = predek;

	delete pom;
}

void odstran(Seznam& s, Prvek* ten)
{
	if (ten == s.hlava)
		odstran_prvni(s);
	else if (ten == s.ocas)
		odstran_posledni(s);
	else
	{
		Data d = ten->dalsi->data;
		ten->dalsi->data = ten->data;
		ten->data = d;
		odstran_za(s, ten);
	}
}

void odstran_posledni(Seznam& s)
{
	if (prazdny(s))
		return;
	else if (s.hlava == s.ocas)
		odstran_prvni(s);
	else 
	{
		Prvek* pom = s.hlava;
		while (pom->dalsi != s.ocas)
			pom = pom->dalsi;
		delete pom->dalsi;
		pom->dalsi = nullptr;
	}
}

void vloz_za(Seznam& s, Data co, Prvek* predek)
{
	Prvek* pom = new Prvek{ co, predek->dalsi };
	predek->dalsi = pom;
	if (predek == s.ocas)
		s.ocas = s.ocas->dalsi;
}

Prvek* najdi_nejmensi(Seznam& s)
{
	Prvek* nejmensi = s.hlava;
	for (Prvek* pom = s.hlava->dalsi; pom != nullptr; pom = pom->dalsi)
	{
		if (nejmensi->data > pom->data)
		{
			nejmensi = pom;
		}
	}
	return nejmensi;
}

void serad(Seznam& s)
{
	if (prazdny(s) || s.hlava == s.ocas)
		return;
	Seznam us;
	vytvor(us);
	while (!prazdny(s))
	{
		Prvek* pom = najdi_nejmensi(s);
		vloz_na_konec(us, pom->data);
		odstran(s, pom);
	}
	s.hlava = us.hlava;
	s.ocas = us.ocas;
}



//_____________________________________________________
// implementujte funkci, ktera vrati pocet prvku seznamu
int velikost(const Seznam& s)
{
	int vel = 0;
	/*
	TODO	
	*/
	return vel;
}
// max 0,2 bodu

// implementujte funkci, ktera "obrati" seznam
// moznosti je vicero, muzete menit ukazatele prvku nebo pouze prohazovat hodnoty v datech, necham to na vas
// po pouziti fce bude seznam 5 ->  3 -> 4 -> 1 -> nullptr vypadat nasledovne: 1 -> 4 -> 3 -> 5 -> nullptr
void otoc_seznam(Seznam& s)
{
	/*
	TODO
	*/
}
// max 0,6 bodu

// implementujte funkci, ktera vymaze opakujici se prvky
// po pouziti fce bude seznam 5 ->  3 -> 5 -> 1 -> 1 -> 3 -> 4 -> 2 -> 1 nullptr vypadat nasledovne: 5 -> 3 -> 1 -> 4 -> 2 -> nullptr
void smaz_prvky_prvky(Seznam& s)
{
	/*
	TODO
	*/
}
// max 1 bod

// implementujte funkci, ktera z chytreho pole vytvori spojovy seznam 
// po pouziti fce na chytre pole [5,3,4,1,6] vrati funkce seznam 5 -> 3 -> 4 -> 1 -> 6 -> nullptr
Seznam prekopiruj(const ChytrePole& k)
{
	Seznam s;
	vytvor(s);
	/*
	TODO
	*/
	return s;
}
// max 0,3 bodu

// Implementujte funkci, ktera vrati kopii seznamu
Seznam prekopiruj(const Seznam& s)
{
	Seznam kopie;
	vytvor(kopie);
	/*
	TODO
	*/
	return kopie;
}
// max 0,3 bodu



// Josefuv problem 
// Vyreste Josefuv problem pres spojovy seznam
// Josefuv problem je pomerne znamy problem z diskretni matematiky viz. https://en.wikipedia.org/wiki/Josephus_problem
// Mame n lidi stojicich v kruhu 1. clovek zabije druheho, dalsi clovek na rade (tedy 3. v kruhu) zabije nasledujiciho (tedy 4. v kruhu)
// atd dokud v kruhu nezbyde posledni clovek 
// problem reprezentujte pomoci spojoveho seznamu, kazdy prvek predstavuje daneho cloveka v kruhu
// spojovy seznam muzete (ale nemusite) prevezt na kruhovy seznam - toho docilite tim ze bude hlava naslednik ocasu
// zabijeni lidi (rimskych vojaku) udelate jednoduse pomoci mazani (deletnuti) prvku ze seznamu
// funkce vrati data ulozena v prvku, ktery prezije
Data josef(const Seznam& s)
{
	Seznam joseznam = prekopiruj(s);
	joseznam.ocas->dalsi = joseznam.hlava; // uprava na kruhovy spojovy seznam
	/*
	TODO
	*/
	return -1;
}
// pozor na uniky pameti!
// max 1,2 bodu