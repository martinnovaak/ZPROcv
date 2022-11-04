#include <iostream>
#include "ChytrePole.h"
using namespace std;


// pomocna funkce na usporadani dvou promennych podle velikosti
void usporadej(int& a, int& b)
{
	if (a < b)
	{
		int pom = a;
		a = b;
		b = a;
	}
}

// zpusob jak vyresit priklad v du6 pres reference
void usporadej(int& a, int& b, int& c, int& d)
{
	usporadej(a, c);
	usporadej(b, d);
	usporadej(a, b);
	usporadej(c, d);
	usporadej(b, c);
}

void vypisPosun(const string& a) // funkce s konstantnim odkazem
{   
	for (int i = 0; i < a.length(); i++)
		cout << (char)(a[i] + 3); // posunuti charu o 3 do prava
	cout << endl;
}

void vypisPosun(string&& a) // funkce s odkazem na R-hodnotu
{
	for (int i = 0; i < a.length(); i++)
		cout << (char)(a[i] + 3); // posunuti charu o 3 do prava
	cout << endl;
}

void vypisPole(int pole[], unsigned int delka)
{
	for (unsigned int i = 0; i < delka; i++)
	{
		cout << pole[i] << " ";
	}
	cout << endl;
}

int main()
{
	// Dynamicke alokace
	int n;
	cin >> n;
	int* pole = new int[n];
	for (int i = 0; i < n; i++)
		pole[i] = i;
	vypisPole(pole, n);

	int* a = new int{ 8 }; // jeden z mnoznych zpusobu dynamicke alokace jedne promenne
	*a = 7;
	cout << a << endl;
	cout << *a << endl;


	vypisPosun(string{ "pic" }); // posilani R-hodnoty jako parametr

	// Nesmime zapomenout alokovanou pamet opet!!!!!!
	delete[] pole;			// uvolneni pole pres operator delete[]
	delete a;				// uvolneni dynamicke promenne pres operator delete	



	ChytrePole chp; // vytvoreni objektu chytreho pole
	alokuj(chp, 8); // inicializacni alokace
	vypisChytrePole(chp); 
	for (int i = 0; i < 9; i++)
		pridat(chp, i); // pridani cisla do chytreho pole
	vypisChytrePole(chp); 
	cout << delkaPole(chp) << endl;
	cout << pocetPrvku(chp) << endl;


	// Silenost
	// while (true)
	//	int* p = new int[100000000];
	// po chvili by nam dosla pamet na RAMce

	
	return 0;
}