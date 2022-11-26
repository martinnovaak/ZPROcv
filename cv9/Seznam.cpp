#include "Seznam.h"
#include "ChytrePole.h"
#include <iostream>
using namespace std;

void vytvor(Seznam& s)
{
	s.hlava = s.ocas = nullptr; // po vytvoreni je seznam prazdny -> hlava i ocas ukazuji na nullptr
}


// seznam je prazdny prave tehdy ukazuje-li hlava na nullptr
bool prazdny(Seznam& s)
{
	return s.hlava == nullptr; 
}


// Pri vlozeni na zacatek dochazi ke trem krocim:
// 1) Vytvorime novy prvek, ktery pujde na zacatek seznamu => jeho nasledovnik musi byt aktualne prvni prvek
// 2) Novy prvek je nova hlava (novy prvni prvek)
// 3) byl-li predtim seznam prazdny (ocas ukazuje na nullptr) je novy prvek novy posledni prvek 
void vloz_na_zacatek(Seznam& s, Data co)
{
	// 1)
	/*  Druhy pristup inicializace noveho prvku pomoci operatoru ->
	Prvek* pom = new Prvek;
	pom->data = co;
	pom->dalsi = s.hlava;
	*/
	Prvek* pom = new Prvek{ co, s.hlava }; 
	// 2)
	s.hlava = pom;
	// 3)
	if (s.ocas == nullptr)
		s.ocas = s.hlava; // s.ocas = pom;
}


// Vkladani na konec:
// 1a) Je-li na zacatku seznam prazdny je vkladani na konec to same jako vkladani na zacatek => zavolame tedy jiz nami implementovanou funkci
// 1b) Jinak:
//		2) Vytvorime novy posledni prvek (jeho naslednik je nullptr)
//		3) novy prvek je novym ocasem (je naslednik aktualne posledniho prvku a zaroven na nej ukazuje ocas)
void vloz_na_konec(Seznam& s, Data co)
{
	if (prazdny(s)) // 1a)
	{
		vloz_na_zacatek(s, co);
	}
	else //1b)
	{
		// 2)
		Prvek* pom = new Prvek{ co, nullptr };
		// 3)
		s.ocas->dalsi = pom;
		s.ocas = s.ocas->dalsi;
	}
}


// Vypis seznamu:
// iteruju od prvniho prvku (hlava) az po posledni prvek seznamu (ocas) a u kazdeho prvku vypisi jeho data
void vypis(Seznam& s)
{
	// Zpusob pres prikaz while
	/*
	Prvek* pom = s.hlava;
	while (pom != nullptr)
	{
		cout << pom->data << ", ";
		pom = pom->dalsi;
	}
	cout << endl;
	*/

	// Zpusob pres cyklus for
	for (Prvek* pom = s.hlava; pom != nullptr; pom = pom->dalsi)
	{
		cout << pom->data << ", ";
	}
	cout << endl;
}

// Odstraneni prvniho prkvu seznamu
// 1) Prvek odstranuji pouze tehdy neni-li seznam prazdny
// 2) ulozim si ukazatel na novy prvni prvek (naslednika hlavy)
// 3) tento prvek je nove hlavou
// 4) smazu "byvaly" prvni prvek 
// 5) je-li nyni seznam prazdny, nastav ocas na nullptr
void odstran_prvni(Seznam& s)
{
	if (!prazdny(s)) // 1)
	{
		// 2)
		Prvek* pom = s.hlava;
		// 3)
		s.hlava = s.hlava->dalsi;
		// 4)
		delete pom;
		// 5) 
		if (s.hlava == nullptr)
			s.ocas = nullptr;
	}
}

// Odstran posledni prvek seznamu:
// 1) Je-li seznam prazdny => skonci (neni co mazat)
// 2) Ma-li seznam pouze jeden prvek (tedy hlava i ocas ukazuji na stejny prvek) => odstran prvni prvek a skonci
// 3) Jinak:
//	   a) do pomocne promenne uloz predposledni prvek seznamu (predka ocasu), je potreba k nemu doiterovat
//     b) smaz posledni prvek (naslednika predposledniho)
//     c) predposledni prvek je nove poslednim (ocasem)
void odstran_posledni(Seznam& s)
{
	if (prazdny(s)) // 1)
		return;
	else if (s.hlava == s.ocas) // 2)
		odstran_prvni(s);
	else // 3)
	{
		// a
		Prvek* pom = s.hlava;
		while (pom->dalsi != s.ocas)
			pom = pom->dalsi;
		// b)
		delete pom->dalsi;
		pom->dalsi = nullptr;
		// c)
		s.ocas = pom;
	}
}


// Seznam vyprazdnim tak, ze budu ze seznamu odstranovat prvni prvek, dokud nebude seznam prazdny
void vyprazdni(Seznam& s)
{
	while (!prazdny(s))
	{
		odstran_prvni(s);
	}
}

// v pripade seznamu bez zarazky splyva zruseni seznamu s vyprazdnenim
// (pokud bychom meli seznam se zarazkou, ve fci zrus bychom navic museli odstranit zarazku, ktera se ve fci vyprazdni nemaze)
void zrus(Seznam& s)
{
	vyprazdni(s);
}

// Najdi prvek s danou hodnotou:
// 1) do pomocneho ukazatele uloz prvni prvek
// 2) koukej na data v prvcich seznamu, dokud nejsi a) na konci seznamu nebo b) nenajdes prvek s hledanou hodnotou
// 3) vrat pomocny ukazatel (v pripade, ze se prvek s hledanou hodnotou v seznamu nenachazi vrati fce nullptr)
Prvek* najdi(Seznam& s, Data hodnota)
{
	// 1)
	Prvek* pom = s.hlava;
	// 2)
	while (pom != nullptr && pom->data != hodnota)
	{
		//if (pom->data == hodnota)
		//	return pom;
		pom = pom->dalsi;
	}
	// 3)
	return pom;
}


// Odstran prvek za prvkem predek:
// 1) Je-li mazany prvek (naslednik predka) poslednim prvkem => odstran posledni prvek a skonci
// Jinak:
// 2) uloz si do pomocne promenne ukazatel na mazany prvek (naslednika predka)
// 3) novy naslednik predka je naslednik mazaneho prvku (naslednik naslednika predka)
// 4) odstran mazany prvek
void odstran_za(Seznam& s, Prvek* predek)
{
	// 1)
	if (predek->dalsi == s.ocas)
	{
		odstran_posledni(s);
		return; // skonci
	}

	// 2)
	Prvek* pom = predek->dalsi;
	// 3)
	predek->dalsi = pom->dalsi;
	// 4)
	delete pom;
}

// odstran dany prvek:
// 1) Je-li mazany prvek prvnim prvkem seznamu (hlavou) => smaz prvni prvek a skonci
// 2) Je-li mazany prvek poslednim prvkem seznamu (ocasem) => smaz posledni prvek a skonci
// 3) Jinak:
//	   a) vymen data v mazanym prvku za data v naslednikovi mazanyho prvku (tedy nove mazany prvek je naslednikem puvodne mazaneho prvku)
//	   b) odstran naslednika puvodne mazaneho prvku
void odstran(Seznam& s, Prvek* ten)
{
	if (ten == s.hlava) // 1)
		odstran_prvni(s);
	else if (ten == s.ocas) // 2)
		odstran_posledni(s);
	else  // 3)
	{
		// a)
		Data d = ten->dalsi->data;
		ten->dalsi->data = ten->data;
		ten->data = d;
		// b)
		odstran_za(s, ten);
	}
}

// Vloz novy prvek za dany prvek (predka):
// 1) Vytvor novy prvek (naslednik noveho prvku je aktualni naslednik predka)
// 2) novy prvek je novym naslednikem predka
// 3) byl-li puvodne predek poslednim prvkem, je novy prvkem nove poslednim prvkem (ocasem)
void vloz_za(Seznam& s, Data co, Prvek* predek)
{
	// 1)
	Prvek* pom = new Prvek{ co, predek->dalsi };
	// 2)
	predek->dalsi = pom;
	// 3)
	if (predek == s.ocas)
		s.ocas = s.ocas->dalsi;
}

// Najdi prvek s nejmensi hodnotou v seznamu:
// 1) Vytvor si pomocny prvek predstavvujici nejmensi prvek a uloz do nej prvni prvek seznamu (hlavu)
// 2) Iteruj skrz vsechny prvky seznamu (od 2. prvku)
// 3) Je-li prvek v dane iteraci mensi nez dosavadni nejmensi => je dany prvek novy nejmensi prvek
// 4) Po skonceni cyklu vrat nejmensi prvek seznamu
Prvek* najdi_nejmensi(Seznam& s)
{
	// 1) 
	Prvek* nejmensi = s.hlava;
	// 2)
	for (Prvek* pom = s.hlava->dalsi; pom != nullptr; pom = pom->dalsi)
	{
		if (nejmensi->data > pom->data) // 3)
		{
			nejmensi = pom;
		}
	}
	// 4)
	return nejmensi;
}

// Seznam budeme serazovat nasledujicim zpusobem:
// 1) Nema cenu serazovat prazdny seznam, nebo seznam s jednim prvkem
// 2) Vytvorime si pomocny novy pomocny seznam
// 3) Dokud nebude puvodni seznam prazdny tak:
//		a) Vzdy najdeme nejmensi prvek v puvodnim seznamu
//	    b) ten vlozime na konec noveho usporadaneho seznamu
//      c) a nasledne ho z puvodniho seznamu smazeme (tim zabranime zacykleni)
// 4) Po skonceni cyklu je puvodni seznam prazdny a pomocny seznam je usporadany od nejmensiho po nejvetsi zmenime tedy ukazatele
//		puvodniho seznamu na pomocny usporadany seznam
void serad(Seznam& s)
{
	if (prazdny(s) || s.hlava == s.ocas) // 1)
		return;
	// 2)
	Seznam us;
	vytvor(us);
	// 3)
	while (!prazdny(s)) 
	{
		// a)
		Prvek* pom = najdi_nejmensi(s);
		// b)
		vloz_na_konec(us, pom->data);
		// c)
		odstran(s, pom);
	}
	// 4) 
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
void smaz_opakovane_prvky(Seznam& s)
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


// Implementujte funkci, ktera zkontroluje zda-li seznam neni palindrom
// Vhodne vyuzijte jiz naprogramovanych predchozich funkci z ukolu
bool palindrom(const Seznam& s)
{
	return false;
}
// max 0,4 bodu


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