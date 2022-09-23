#include <iostream>
#include <string>
using namespace std;

int main()
{ 
	// Faktorial
	int vstup;
	cin >> vstup;
	int faktorial = 1;
	while (vstup > 1)
	{
		faktorial *= vstup;
		vstup--;
	}
	cout << faktorial << endl;

	//cout << "Hello world" << endl;
	//cout << "Dalsi radek";

	/*
	 vyuziti bloku pro vytvoreni nove
	 stejnojmenne promenne 
	 */

	// jednoduchy cyklus vypise hodnoty od 5 az po 1
	int i = 5;
	// nekonecny cyklus
	/*while (i > 0)
	{
		cout << i << endl;
	}*/

	int        _cislo = 5;
	cout << _cislo << endl;
	{ // blok kodu
		int _cislo = 9;
		cout << _cislo << endl;
	}
	//cout << _cislo << endl;

	/* povolene nazvy identifikatoru
	int ident;
	int _ident;
	int i1dent;
	int 1ident; cislo nesmi byt 1.
	*/
 
	//logicke operatory
	bool boolean = 0 != 5; // operator == 
	bool boolean2 = 5 < 5; // false
	bool boolean3 = 5 <= 5; // true
	cout << boolean << endl;

	int a = 5, b = 7; // int a; int b;
	//binarni aritmeticke operatory
	cout << a + b << endl; // operator + scitani
	cout << a - b << endl; // operator - odecitani
	cout << a * b << endl; // operator * nasobeni
	cout << a / b << endl; // operator / celociselne deleni
	cout << a % b << endl; // operator % zbytek po celociselnem deleni

	//unarni -||-
	cout << a++ << endl; // 5
	cout << ++a << endl; // 7
	// stejne operator --
	
	a += 7; // a = a + 7;



int c = a * b;

	int vek;
	string jmeno;
	cout << "Jak se jmenujete: ";
	cin >> jmeno;
	cout << "Kolik je vam let: ";
	cin >> vek;
	cout << "Jmenujete se " << jmeno << " a je vám  " << vek << " let.";

	//vicevstupu od uzivatele
	cin >> jmeno >> vek;
	cout << jmeno << " " << vek;

	

	return 0;
}