#include <iostream>  
#include <string>	 
#include <tuple>	 // n-tice
#include <list>		 // obousmerne zretezeny seznam
#include <vector>	 // "chytre pole"
#include <array>	 // pole s kopirovacim kostruktorem
#include <map>		 // "slovnik" 
#include <algorithm> // kvuli sortu
#include <fstream>   // objektova trida pro praci s vystupnimi a vstupnimi proudy
#include <iomanip>   // knihovna pro formatovani vystupu
using namespace std;

extern int o; // externi promenna, definice se nachazi v souboru Source.cpp

// v C++ 11 byl predstaven novy zpusob psani hlavicek fci
// na zacatek dame auto, a za sipku dame return type
// je to ekvivalnce k zapisu:
// int prumer(int a, int b)
auto prumer(int a, int b) -> int
{
	return (a + b) / 2;
}

// funkce se statickou promennou, vypise "Ahoj" do konzole a vrati nam cislo, 
// kolikrat jsme danou funkci zavolali
int napisAhoj()
{
	// staticka promenna se inicializuje pouze na zacatku programu, pri dalsim volani funkce uz incializace neprobiha!
	static int pocet = 0; // na zacatku programu se pocet inicializuje na 0
	pocet++;			  // pocet volani funkce zvetsime o 1
	cout << "Ahoj" << endl;
	return pocet;		  // vrat hodnotu staticke promenne
}

// rekurzivni fibonacci se statickym pocitadlem
int fibonacci(int a)
{
	static int pocitadlo = 0;
	pocitadlo++;
	cout << pocitadlo << endl;
	return (a == 1 || a == 2) ? 1 : fibonacci(a - 1) + fibonacci(a - 2);
}

unsigned int nsd(unsigned int a, unsigned int b)
{
	return (b == 0) ? a : nsd(b, a % b);
}

// vraceni vice promennych pomoci n-tice tupple
tuple<unsigned int, unsigned int> zakladni_tvar(unsigned int cit, unsigned int jme)
{
	auto del = nsd(cit, jme); 
	//return make_tuple(cit / del, jme / del);
	return tuple{ cit / del, jme / del };
}

// vraceni vice promennych pres vraceni struktury
auto deleni(unsigned int delenec, unsigned int delitel)
{
	struct del { unsigned int podil; unsigned int zbytek; };
	return del{ delenec / delitel, delenec % delitel };
}

// posilani proudu jako parametru fce
void zapis_caru(ofstream& soubor)
{
	soubor << "_____________________________________________________" << endl;
}

// funkce na zapsani cisel od 1 do 100 do souboru cesta
bool zapis(const string & cesta)
{
	//fstream
	ofstream soubor; // vystupni proud
	soubor.open(cesta);
	if (soubor.is_open()) // je-li proud uspesne otevren
	{
		for (int i = 1; i < 100; i++)
		{
			if (i % 10 == 0) // po kazdych deseti cislech zapiseme "caru" (podtrzitka na radek)
				zapis_caru(soubor);
			soubor << i << endl; // na aktualni radek cislo i
		}
		soubor.close();
		return true; // vracime true - povedlo se zapsat do souboru
	}
	return false; // vracime false - nepovedlo se zapsat do souboru
}

// funkce pro precteni souboru a vypsani jeho radek do konzole
bool precti(const string& cesta)
{
	ifstream soubor; // proud pro cteni 
	soubor.open(cesta); // soubor ktery chceme precist
	if (soubor.is_open())
	{
		//string slovo;
		string radek;
		while (soubor.good())
		{
			getline(soubor, radek);
			//soubor >> radek;
			cout << radek << endl;
		}
		soubor.close();
		return true;
	}
	return false;
}

// priklad na manipulatory v knihovne iomanip:  right, left, setw, setfill, setprecision
void napis_pi(const string& cesta)
{
	ofstream soubor(cesta); // vytvoreni instance a volani metody open pomoci konstruktoru
	if (soubor.is_open())
	{
		double pi = 3.14159265;
		soubor << pi << endl << endl;
		soubor << right << setw(10) << setfill('_') << setprecision(3) << pi << endl << endl;
		soubor << left << setw(10) << setfill('_') << setprecision(3) << pi << endl << endl;
		soubor.close();
	}
}

auto main() -> int
{
	cout << o << endl;		// vypis externi promennou

	//ukazka automatickych promennych
	auto a = 5;
	cout << prumer(2, 4);

	// bacha nasledujici funkce dost zadela konzoli, dejte si pri pousteni kdyztak
	// mensi cislo do fibonacciho, jedna se o ukazku jak neefektivni rekurzivni fibonacci je
	int p = fibonacci(20);  // zavolej fibonacciho rekurzivni fci

	for (int i = 0; i < 10; i++)
		a = napisAhoj();    // zavolej 10x funkci napisAhoj

	cout << a << endl;		// vypis vracenou statickou promennou
	

	// vraceni vice promennych
	unsigned int citatel, jmenovatel;
	tie(citatel, jmenovatel) = zakladni_tvar(15, 12); // zpusob pres tuple ve verzi C++ 11
	auto [cit, jme] = zakladni_tvar(25, 15); // zpusob od verze C++ 17

	auto [podil, zbytek] = deleni(15, 4);    // od verze C++ 17 muzeme pristoupit k atributum struktury pres operator []
	cout << 15 << " / " << 4 << " = " << podil << "  " << 15
		<< " % " << 4 << " = " << zbytek << endl;

	cout << cit << " / " << jme << endl;

	cout << citatel << " / " << jmenovatel;


	// STL datove struktury (kontejnery)
	// array - "chytre staticke pole"
	array<int, 7> pole{ 8,6,1,7,3,4,8 }; // pole intu o 7 prvcich
	sort(pole.begin(), pole.end()); // STL kontejnery jdou sortit pomoci iteratoru
	for (int l : pole)	// muzeme pouzivat kontejnerovy for pro prochazeni
		cout << l << ", ";
	cout << endl;
	array<int, 7> p2 = pole; // array umi prekopirovat data do noveho pole 
	//obe pole maji stejne hodnoty, ale kazde pole je v pameti jinde
	p2[3] = 99; // prepisu-li hodnotu 4. prvku pole
	cout << p2[3] << "  " << pole[3] << endl; // tak se prvek v puvodnim neprepise

	// obousmerny spojovy seznam
	list<int> l;
	l.push_back(7); // vloz na konec
	l.push_front(5); // vloz na zacatek
	l.push_front(9);
	for (const auto& ii : l) // kontejnerovy for cyklu
		cout << ii << ", ";
	cout << endl;

	// chytre dynamicke pole
	vector<int> v; // pole intu
	for (int i = 0; i < 5; i++)
		v.push_back(i); // vloz na konec
	v[4] = 9;

	// vektor nemuze vkladat na zacatek
	// v pripade potreby vektoru, ktery umi vkladat na zacatek i konec vyuzijte deque

	for (const auto& ii : v) 
		cout << ii << ", ";
	cout << endl;

	// mapa - slovnik
	map<int, string> m; // klic bude typu int a ulozena hodnota pod klicem typu string
	m[4] = "ahoj";	// pod klicem 4 ulozim string "ahoj"
	m[7] = "pic";
	m[10] = "cau";
	cout << m[4] << endl; // vypisu prvek ulozeny pod klicem 4

	map<string, string> ms; // slovnik, kde klic je take string
	ms["prvek"] = "pic";	// pod klicem "prvek" ulozim string "pic"
	cout << ms["prvek"] << endl;

	zapis("text.txt");
	precti("text.txt");
	napis_pi("pi.txt");	

	return 0;
}