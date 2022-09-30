#include <iostream>
#include "funkce.h"
using namespace std;

// sablony - JAK SE NEOPAKOVAT
// sablonova funkce pro nalezeni maxima dvou promennych (Jedna se pouze o ukazku. Sablony se budou poradne probirat na predmetu 18PRC1)
template <typename T>
T Maximum(T a, T b)
{
	return (a >= b) ? a : b; // podmineny vyraz pomoci operatoru ?:
}

int main()
{
	cout << "Zadejte dve cela cisla: ";
	int a, b; // lze libovolne zamenit za double nebo float
	cin >> a >> b;
	cout << "Ze zadanych cisel je vetsi: " << maximum(a, b) << endl; // zavola funkci maximum(int, int)


	cout << "Zadejte polomer kruhu: ";
	double r; 
	cin >> r;
	cout << "Obsah kruhu o polomeru: " << r << " je " << obsahKruhu(r) << endl;
	cout << "Obvod kruhu o polomeru: " << r << " je " << obvodKruhu(r) << endl;

	cout << "Zadejte cislo, ktereho chcete vypocitat faktorial: ";
	int n;
	cin >> n;

	if (!cin) // kontrola korektniho datoveho typu vstupu uzivatele
	{	// zkraceny zapis ifu alternativne by slo napsat if(cin == false) nebo take if(!cin == true)
		// ! je operator negace
		cin.clear(); // vycisteni chybovych hlaseni u vstupu
		cin.ignore(256, '\n'); // ignorovani vstupu uzivatele na radce (maximalne muze ignorovat az 256 znaku (pocet znaku si muzeme upravit v pripade potreby))
		cout << "Zadejte cele cislo";
	}
	else if ((n < 0) || (n > 13)) // pokud je zadane cislo n mensi nez 0 (zaporne) nebo vetsi nez 13
	{
		cout << "Nespravny vstup. Faktorial zaporneho cisla neexistuje nebo dochazi k preteceni" << endl;
	}
	else 
		cout << faktorial(n) << endl; // v pripade ze za prikazy typu while, if, else nasleduje pouze jeden prikaz, pak neni potreba psat blokove zavorky {}
	
	return 0;
}