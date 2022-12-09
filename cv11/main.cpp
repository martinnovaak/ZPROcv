#include <iostream>
#include <string>
#include "Zlomek.h"
#include "ChytrePole.h"
#include <list>
using namespace std;

/*
class T 
{
	int a;
	friend class U;
};

class U
{
public:
	void vypis(T& t)
	{
		cout << t.a << endl;
	}
};
*/

int main()
{
	{
		ChytrePole c; // zavolani konstruktoru bez parametru
		ChytrePole ch1(8); // volani konstruktoru s parametrem
		for (int i = 0; i < 4; i++)
			ch1.pridat_na_konec(i);
		ChytrePole ch2(ch1); // kopirovaci konstruktor
		ChytrePole ch3 = ch2; // vytvoreni instance s prirazovacim operatorem = zavola kopirovaci konstruktor!!!
		// diky kopirovacimu konstruktoru nesdili instance ch2 a ch3 pole 
		// bez vlastni implementace kopirovaciho konstruktoru by sdileli stejne dynamicke promenne a navzajem by si je prepisovali
		// muzete si vyzkouset, ze kdyz smazete kopirovaci konstruktor, tak dostanete jine vysledky nez
		// s implementovanym kopirovacim konstruktorem
		ch2.pridat_na_konec(7); 
		ch3.pridat_na_konec(6);
		ch1.vypis();
		ch2.vypis();
		ch3.vypis();
	}

	string s("slovo");  // vytvareni stringu s konstruktorem
	string l(s);		// vytvoreni stringu pres kopirovaci konstruktor

	// l je novy string prepsanim hodnot ve stringu s nezmenim string l
	s[4] = 'a';	
	cout << l << endl;

	Zlomek z(15,12); //Zlomek je struktura a z je objekt struktury zlomek
	//z.setZlomek(15, 12);
	z.zakladniTvar();
	vypis(z); // volani metody
}