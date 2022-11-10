#include <iostream>
#include "ChytrePole.h"
#include "Seznam.h"
using namespace std;



int main()
{
	Seznam sez;
	vytvor(sez);
	for (int i = 1; i < 11; i++)
	{
		vloz_na_konec(sez, i);
	}
	cout << josef(sez) << endl;


	ChytrePole ch;
	alokuj(ch, 8);
	for (int i = 0; i < 10; i++)
		pridat(ch, i);
	Seznam ss = prekopiruj(ch);
	vypis(ss);

	Seznam s;
	vytvor(s);
	vypis(s);
	vloz_na_zacatek(s, 5);
	vypis(s);
	vloz_na_konec(s, 1);
	vypis(s);
	Prvek* pom = najdi(s, 1);
	vloz_za(s, 2, pom);
	vypis(s);
	serad(s);
	vypis(s);
	zrus(s);

	/*
	unsigned int p = 0;
	int l = -1;
	if (p < l)
	{
		cout << (unsigned int)l;
	}
	*/

	return 0;
}