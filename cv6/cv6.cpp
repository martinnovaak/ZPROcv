#include <iostream>
using namespace std;

// struktura pouzivana k ukazce, jak vratit vice hodnot z funkce
struct MinMax
{
	int min;
	int max;
};


/* tohle v c++ nejde
*  v ruznych programovacich jazycich jako napr. c# nebo golang existuji
* funkce s vicero navratovyma hodnotama (v c++ ovsem ne)
(int, int) udelej(int a, int b)
{
	return maximum(a, b);
}
*/

// klasicka funkce pro vraceni vetsi ze dvou promennych
int maximum(int a, int b)
{
	return a > b ? a : b;
}

// 1) jeden ze zpusobu vraceni vice promennych je pres pole
void serad(int pole[])
{
	int mx = maximum(pole[0], pole[1]);
	int mn = -maximum(-pole[0], -pole[1]);
	pole[0] = mn;
	pole[1] = mx;
}

// 2) dalsi mozny zpusob jak vratit vice promennych je vytvorit si pomocnou strukturu,
// ktera bude obsahovat v atributech nase promenne, ktere chceme z fce vratit
MinMax serad2(int a, int b)
{
	// return MinMax{maximum(-a, -b), maximum(a,b)};
	//MinMax mm2;
	//mm2.min = maximum(-a, -b);
	//mm2.max = maximum(a, b);
	MinMax mm = { -maximum(-a, -b), maximum(a,b) };
	return mm;
}

// 3) zpusob pres ukazatele
// je lepsi nez metody 1) pres pole a 2) pres struktury, protoze nemusime vytvaret zadne pomocne
// pole respektive struktury
void poradnejSerad(int* a, int* b)
{
	// v promennych a a b se nyni nachazi ukazatel na adresu, ktera byla predana 
	// jako parametr pri volani funkce 
	int mx = maximum(*a, *b); // k ziskani hodnoty na adrese a a b musime dereferencovat
	int mn = -maximum(-( * a), -( * b)); // minimum
	*a = mn; // do hodnoty na adrese a ulozime minimum
	*b = mx; // do hodnoty na adrese b ulozime maximum
}

// tento zpusob promennym hodnotu nezmeni
void neserad(int a, int b)
{
	a = 4;
	b = 3;
}

// funkce na prohozeni hodnot v promennych pres ukazatele
void prohod(int* p1, int* p2)
{
	int pom = *p1;
	*p1 = *p2;
	*p2 = pom;
}

// vypis pole
// void vypisPole(int pole[], int n) // stejna moznost zapisu
void vypisPole(int* pole, int n) 
{
	// pole se predava jako ukazatel na adresu prvniho prvku pole! 
	for (int i = 0; i < n; i++)
		cout << *(pole + i) << endl; 
		//cout << pole[i] << endl;
	// kdyz ve funkci, kde jsme predali pole jako parametr zapiseme klasicky pole[i]
	// tak prekladac sam implicitne posune ukazatel pole o i jednotek: (pole + i) a nasledne 
	// jej dereferencuje aby pristoupil k jeho hodnote: *(pole + i)
	// cele to funguje diky tomu, ze vsechny prvky pole, jak jiz vime z hodiny, jsou usporadany
	// v pameti za sebou!
}

// posleme-li ukazatel jako parametr funkce
// muzeme natvrdo napsat, ze se jedna o pole i kdyz se jedna jen o obycejny jeden int
// prekladac to nebude vedet, protoze si mysli ze obdrzel ukazatel na 1. prvek pole
// tim padem muzeme psat pole[0], protoze se proste jedna jen o obycejnou derefenci ukazele
void coPrekladacNevi(int pole[])
{
	cout << pole[0] << endl;
}
// tato funkce je pouze pro zajimavost. V programech to nepouzivejte.

void prohodPresReference(int& a, int& b)
{
	int pom = a;
	a = b;
	b = pom;
}

// Nasledujici cast je predelani prace se zlomkem z minuleho cviceni (cv5)

// strutkura predstavujici zlomek
struct Zlomek
{
	unsigned int citatel;
	unsigned int jmenovatel;
};

// nejvetsi spolecny delitel pres rekurzi
int nsd(unsigned int a, unsigned int b)
{
	return (b == 0) ? a : nsd(b, a % b);
}

// funkce, ktera prevede zlomek na jeho zakladni tvar
// zakladni tvar zlomku se ziska tak, že citatel i jmenovatel vydelime nejvetsim spolecnym delitelem
// zlomek predame referenci
void zakladniTvar(Zlomek& z)
{
	int nd = nsd(z.citatel, z.jmenovatel);
	z.citatel /= nd;
	z.jmenovatel /= nd;
}

int main()
{
	int a = 7, b = 2; // mame celociselne promenne a, b
	// hodnoty v promennych chci usporadat tak, ze v a bude mensi hodnota v b vetsi
	neserad(a, b); // timto zpusobem se nam, ale hodnota v promennych a a b nezmeni!
	cout << a << "  " << b << endl;

	// Tento problem umime vyresit celkem 3 ruznymi zpusoby
	
	// pres volani vicero funkci
	int mx = maximum(a, b);
	int mn = -maximum(-a, -b);
	a = mn;
	b = mx;
	cout << a << "  " << b << endl;

	// pres struktury:
	a = 7, b = 2;
	MinMax mm = serad2(a, b);
	a = mm.min;
	b = mm.max;
	cout << a << "  " << b << endl;

	// pres pole
	a = 7, b = 2;
	int pole[]{ a, b };
	serad(pole);
	a = pole[0]; b = pole[1];
	cout << a << "  " << b << endl;


	// UVODNI AHA priklad na ukazatele
	int c = 0;		 // na zacatek inicializujeme celociselnou promennou c a ulozime do ni hodnotu 0
	int* uka = &c;	 // vytvorime ukazatel uka, ktery bude ukazovat na adresu, na ktere se nachazi promenna c
	*uka = 5;        // derefencovanim ukazatele pristoupime k hodnote ulozene na adrese (na kterou ukazuje) a prepiseme ji na 5
	cout << c << endl;  // hodnota ulozena v promenne c
	cout << &c << endl; // adresa, na ktere se promenna c nachazi
	cout << uka << endl;// vypis adresy, na kterou ukazuje ukazatel uka

	// 4. zpusob pres ukazatele
	poradnejSerad(&a, &b); // do funkce poradnejSerad posleme jako parametr adresy promennych a a b
	cout << a << "  " << b << endl;
	prohod(&a, &b);
	cout << a << "  " << b << endl;

	// VOID UKAZATELE - ukazatele bez datoveho typu
	int o = 5;
	char ch = 'a';
	void* vuka = &o; // void ukazatel muze ukazovat na adresu libovolneho datoveho typu
	cout << vuka << endl;
	//cout << *vuka << endl; // nelze vsak pristupovat k hodnote na adrese, na kterou ukazuje
	cout << *(int*)vuka << endl; // pro hodnotu na adrese musime void ukazatel pretypovat na ukazatel spravneho datoveho typu
	vuka = &ch;
	cout << *(char*)vuka << endl;

	// NULLPOINTERY
	int* neco = nullptr; // ukazatel na "nikam" - nullpointer - prozatim neukazuje na zadnou adresu 
	// cout << *neco << endl; // behova chyba
	if (neco) // pokud je ukazuje ukazatel na nullpointer, tak se aumaticky prevadi v podmince na false
		cout << *neco << endl;
	else      // pokud ukazatel ukazuje na nejakou adresu v pameti, tak se automaticky prevadi v podmince na true
		cout << "Jedna se o nullpointer \n";

	// OPERATOR SIPKA -> u ukazatelu na struktury
	MinMax mmm{ 1, 5 };
	MinMax* muka = &mmm; // ukazatel na adresu struktury mmm
	cout << (*muka).min << endl;  // pro pristup k hodnotam ve starem jazyce C v atributech musime pole nejprve derefencovat a pote az pristupovat k hodnotam
	cout << muka->min << endl;	  // c++ jiz nabizi operator sipka, ktery sam ukazatel dereferencuje a rovnou k hodnotam pristupuje

	// ADRESOVA ARITMETIKA - jen pro zajimavost, abyste vedeli, jak c++ pracuje s poli 
	int pole[]{ 1,2,3,4 };
	vypisPole(pole, 4); // kdyz volam vypis pole, tak posilame pole jako parametr. Prekladac ovsem posila pouze adresu 1. prvku pole!
	//vypisPole(&pole[0], 4); // uplne stejny zpusob, jak prekladac posila pole jako parametr
	int t = 5;
	coPrekladacNevi(&t);
	
	// vypis pole pres adresovou aritmetiku
	int* ukaNaPole = &pole[0];
	for (int i = 0; i < 4; i++)
		cout << *ukaNaPole++ << endl;


	// REFERENCE - ODKAZY
	// takove "chytrejsi ukazatele"
	int cislo1 = 18;
	int cislo2 = 10;
	int& ref = cislo1; // int* ref = &cislo;
	cout << ref << endl; // prekladac sam pozna, ze se jedna o odkaz (referenci) a pri praci s promennou ref automaticky pristupuje k hodnote
	// uzivateli se pak promenna jevi jako regulerni promenna
	// reference jsou jednoduse receno nove jmeno pro existujici promennou!

	// 5. zpusob pres reference
	prohodPresReference(cislo1, cislo2);
	cout << cislo1 << ", " << cislo2 << endl;

	// Zakladni tvar zlomku pres reference (odkazy)
	Zlomek z{ 15,12 };
	zakladniTvar(z);
	cout << z.citatel << " / " << z.jmenovatel << endl;

	return 0;
}