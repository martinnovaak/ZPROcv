#include <iostream>
#include "ChytrePole.h"
#include "Seznam.h"
#include <cstdarg> // knihovna s implementaci vypustky
#include <string>
using namespace std;

//DU9
// Napiste sablonovou funkci max pres vypustku
template<typename T> T maximum(unsigned int pocet, ...)
{
	return (T) -1; // jen aby funkce nezpusobovala errory
}
// 0,3 bodu

// V du8 jste resili nekteri josefuv problem pres spojovy seznam
// pro pripomenuti si muzete precist na wikipedii https://en.wikipedia.org/wiki/Josephus_problem
// v predmetu DIM2 si odvodit (pokud si predmet pristi semestr zapisete) nasledujici
// rekurentni vzorec, ktery resi josefuv problem:
// J(1) = 1  //  podminka ukonceni rekurze
// J(2m) = 2J(m) - 1   // tedy Josef sudeho cisla
// J(2m+1) = 2J(m) + 1 // tedy Josef licheho cisla
// kdybyste mi nekdo rekurentni vzorec neverili tak se muzete podivat do skript :)
// https://people.fjfi.cvut.cz/masakzuz/dim_soubory/dim2.pdf
// samozrejme vzorec se da lepe dal odvodit do iterativni verze, ale to bychom si neprocvicili rekurzi
int josef_rekurzivne(unsigned int n)
{
	return -1;
}
// 0,3 bodu


// zkuste vymyslet rekurzivni funkci na vypocet prvociselneho rozkladu cisla n
// kdyz zadam napr cislo n = 30 tak funkce vrati string ve tvaru "2*3*5"
string prvociselny_rozklad(int n)
{
	return "";
}
//_______________________________________________________

/*
double mocnina(double a)
{
	return a * a;
}
*/

// Funkce s implicitni hodnotou pro n
double mocnina(double a, int n = 2)
{
	double pom = 1;
	for (int i = 0; i < n; i++)
		pom *= a;
	return pom;
}

// aritmeticky prumer pres vypustku
double prumer(int pocet, ...)
{
	double pr = 0.0;
	// Vypustka
	va_list list; // promenna typu va_list je ukazatel na misto, kde jsou ulozenyhodnoty parametru predanych vypustkou
	va_start(list, pocet); // inicializace vypustky 1. argument je ukazatel na parametry druhy parametr pocet parametru
	// va_start je makro (funkce s prototypem) (makro s prototypem jsou dale i va_arg a va_end)
	for (int i = 0; i < pocet; i++)
		pr += va_arg(list, double); // makro va_arg - vrati prvek daneho typu, ktery je na rade
	va_end(list); // makro va_end zabezpeci uklid

	return pr / pocet;
}

// pridej prvky do seznamu uzitim vypustky
void pridejDoSeznamu(Seznam& s, int pocet, ...)
{
	va_list list;
	va_start(list, pocet);
	for (int i = 0; i < pocet; i++)
		vloz_na_konec(s,va_arg(list, int));
	va_end(list);
}


// vypis hodnot fce 
// funkce, ktera ma jako parametr jinou fci - pouziva ukazatel na danou fci
void vypisFci(double (*f)(double), double from, double to, double step, const char * jmeno)
{
	while (to > from)
	{
		cout << jmeno <<"(" << from << ") = " << f(from) << endl;
		from += step;
	}
}

// faktorial rekurzivne
// fak(n) = n! = n * (n-1)! = n * fak(n-1)
unsigned int faktorial_rekurzivne(unsigned int n)
{
	if (n == 0 || n == 1) return 1;
	return n * faktorial_rekurzivne(n - 1);
}

// fibonacci rekurzivne 
// rekurentni vztah: fib(n) = fib(n-1) + fib(n-2)
unsigned int fibonacci_rek(unsigned int n)
{
	// podminky ukonceni - fibonacci potrebuje dve podminky ukonceni 
	if (n == 0) return 0; 
	if (n == 1) return 1;
	return fibonacci_rek(n - 1) + fibonacci_rek(n - 2); 
}

//nejmensi spolecny delitel pres rekurzivni euklidovu metodu
// rekurentni vztah: nsd(a,b) = nsd(b, a % b)
unsigned int nsd_rek(unsigned int a, unsigned int b)
{
	if (b == 0) return a; // podminka ukonceni
	return nsd_rek(b, a % b); // rekurentni vztah
}

// pomocna funkce pro rekurzivni funkci serad_pole
// funkce vrati index nejmensiho prvku pole
unsigned int index_nejmensiho_prvku(int* pole, unsigned int delka)
{
	unsigned int nejmensi = 0;
	for (unsigned int i = 1; i < delka; i++)
		if (pole[nejmensi] > pole[i])
			nejmensi = i;
	return nejmensi;
}

// serad pole rekurzivne
void serad_pole(int* pole, unsigned int delka)
{
	// podminka ukonceni rekurze
	if (delka <= 1) return; // je-li pole delky 1, tak neni co serazovat
	// prohod 1. prvek s nejmensim prvkem pole:
	swap(pole[0], pole[index_nejmensiho_prvku(pole, delka)]); 
	// uz je potreba setridit jen pole o 1 mensi (od indexu 2 az n)
	serad_pole(++pole, delka - 1); // vyuziju ukazatelove aritmetiky a zavolam rekurzivni fci

	// jiny mozna jednodussi zpusob je hledat nejvetsi prvek pole a dat ho na posledni misto pole
	// a pak neni potreba pouzivat aritmetiku ukazatelu a stacilo by zavolat:
	// serad_pole(pole, delka-1);
}

int main()
{
	cout << prvociselny_rozklad(30) << endl;
	//cout << maximum<int>(5, 1, 2, 4, 3, 7, 6 ,5) << endl; // muzete pouzit pro testovani vasi fce v du
	
	// testy implicitni funkce
	double a_na_n = mocnina(2, 4);
	cout << a_na_n << endl;
	double a_na_d = mocnina(2);
	// double a_na_d = mocnina(2,2); // stejne jako mocnina(2) diky implicitni hodnote pro n

	// Vypustka
	Seznam s;
	vytvor(s);
	// vlozeni prvku do seznamu pres vypustku
	pridejDoSeznamu(s, 5, 1, 6, 4, 3, 2);
	vypis(s);

	// test vypustky
	cout << prumer(5, 1.0, 2.0, 3.0, 4.0, 5.0) << endl;
	cout << prumer(7, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0) << endl;

	// Pretizeni operatoru
	// Trida string ma pretizeny operator + pro spojovani dvou rezezcu
	string as = "slo";
	string bs = "vo";
	cout << as + bs << endl; // zavola se pretizeny operator+ ve tride string

	ChytrePole a,b;
	alokuj(a,4);
	pridat(a, 1);
	alokuj(b, 4);
	pridat(b, 2);
	pridat(b, 3);
	//ChytrePole c = spoj(a, b);
	ChytrePole c = a + b; //zavolame vlastni pretizeny operator+
	// ukazka pretizeni operatoru
	// bylo by lepsi jeste pretizit operator = a udelat tzv. tunelovaci prirazovaci operator
	// jedna se vsak o latku predmetu 18PRC1
	vypisChytrePole(c);

	// Rekurze

	cout << nsd_rek(18, 12) << endl;

	// priklad na nevhodne pouziti rekurze
	cout << fibonacci_rek(15) << endl; 

	cout << faktorial_rekurzivne(6) << endl;

	int pole[]{ 1,5,3,4,2 };
	serad_pole(pole, 5);
	for (auto a : pole)
		cout << a << ", ";
	cout << endl;

	// Ukazatele na funkce
	// double (*f)(double) = &sin; // u ukazatelu na funkce neni potreba davat znak & (referenci) pred funkci
	double (*f)(double) = sin;
	cout << f(3.14159265) << endl;
	f = cos;
	cout << f(3.14159265) << endl;

	double (*v)(int, ...) = &prumer; // muzeme delat ukazatele na funkce s vypustkou
	cout << v(5, 1.0, 2.0, 3.0, 4.0, 5.0) << endl; 

	// predani funkce jako parametru funkce
	vypisFci(sin, 0.0, 3.14159265, 0.1, "sin"); 
	vypisFci(cos, 0.0, 3.14159265, 0.1, "cos");

	return 0;
}