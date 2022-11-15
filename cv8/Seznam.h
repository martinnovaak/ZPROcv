#pragma once

//#define Data int
using Data = int;

class ChytrePole; // Dopredna deklarace kvuli funkci Seznam prekopiruj(const ChytrePole& k);
// obecne se snazime v hlavickovych souborech nepouzivat #include ...
// pouzivaji se k tomu prave dopredne deklarace a spravny include pouzijeme az v souboru s koncovkou .cpp



// struktura predstavujici prvek seznamu
// v jednosmernym zretezenym seznamu vidi kazdy prvek seznamu vidi nasledujici prvek v seznamu
// Dale kazdy prvek uchovava nejake data
struct Prvek // Node
{
	Data data;		// ulozena data v prvku
	Prvek* dalsi;   // ukazatel na dalsi prvek v seznamu
};

// struktura predstavujici linearni spojovy seznam
// pouzijeme implementaci s ukazatelem na hlavu a ocas (na prvni a posledni prvek seznamu)
// existuje cela rada moznych implementaci seznamu: 
//		1) seznam obsahujici pouze s ukazatel na prvni prvek,       2) seznam se zarazkou misto ukazatele na posledni prvek
//		3) kruhovy spojovy seznam								    4) obousmerny seznam,  apod.
struct Seznam // anglicky linked list
{
	//Prvek* prvni;
	//Prvek* posledni;
	Prvek* hlava; // head     // ukazatel na prvni prvek v seznamu
	Prvek* ocas; // tail	  // ukazatel na posledni prvek v seznamu
};

// Funkce se seznamem:
// cv 7
void vytvor(Seznam& s);					   // Funkce pro vytvoreni noveho seznamu (inicializacni funkce)
bool prazdny(Seznam& s);				   // boolovska funkce vracejici informaci, zda-li je seznam prazdny (neobsahuje zadny prvek)
void vloz_na_zacatek(Seznam& s, Data co);  // Funkce pro vlozeni prvku na zacatek seznamu
void vloz_na_konec(Seznam& s, Data co);    // Funkce pro vlozeni prvku na konec seznamu
void vypis(Seznam& s);					   // Funkce pro vypsani jednotlivych prvku seznamu (vypsani dat v prvcich)	
void odstran_prvni(Seznam& s);			   // Funkce pro odstraneni prvniho prvku seznamu	
void odstran_posledni(Seznam& s);		   // Funkce pro odstraneni posledniho prvku ze seznamu	
void vyprazdni(Seznam& s);				   // funkce pro odstraneni vsech prvku v seznamu
void zrus(Seznam& s);					   // funkce ponechana kvuli moznosti prace se zarazkou (v pripade seznamu bez zarazky se jedna  pouze o fci vyprazdni

// cv 8

Prvek* najdi(Seznam& s, Data hodnota);	   // Funkce, ktera vrati ukazatel na prvek s atributem data == hodnota
void odstran_za(Seznam& s, Prvek* predek); // Funkce, ktera odstrani prvek ze seznamu za danym prvkem
void odstran(Seznam& s, Prvek* ten);	   // Funkce pro odstraneni daneho prvku ze seznamu	
void vloz_za(Seznam& s, Data co, Prvek* predek); // Funkce pro vlozeni prvku za dany prvek
Prvek* najdi_nejmensi(Seznam& s);		   // Funkce, ktera vrati prvek s nejmensi hodnotou	
void serad(Seznam& s);					   // Funkce pro serazeni seznamu od nejmensiho po nejvetsi	metodou razeni vyberem (selection sort)

//______________________________________________
// DU8
int velikost(const Seznam& s);
void otoc_seznam(Seznam& s);
void smaz_prvky_prvky(Seznam& s);
Seznam prekopiruj(const ChytrePole& k);
Seznam prekopiruj(const Seznam& s);
bool palindrom(const Seznam& s);
Data josef(const Seznam& s);
