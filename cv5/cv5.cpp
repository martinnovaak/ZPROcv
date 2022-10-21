#include <iostream>
using namespace std;

// enumy predstavujici obor
enum Obor {JCF, AIPV, JIB, MM, JCH}; // v JCF je ulozena hodnota 0, v AIPV 1, atd. ...

// struktura predstavujici studenta
// student ma 4 atributy: jmeno, prijmeni, rocnik a obor
struct Student
{
	string jmeno;			// jmeno studenta
	string prijmeni;		// prijmeni studenta	
	unsigned int rocnik;    // rocnik studenta
	Obor obor;				// obor studenta
};

// struktura predstavujici zlomek 
// obsahuje dva atributy: citatel a jmenovatel
struct Zlomek
{
	unsigned int citatel;
	unsigned int jmenovatel;
};

// funkce na nejmensi spolecny delitel napsana jednoradkove pomoci rekurze
// rekurzi jsme jeste nebrali!
int nsd(int a, int b)
{
	return (b == 0) ? a : nsd(b, a % b);
}

//
Zlomek zakladniTvar(Zlomek zlomek)
{
	int nd = nsd(zlomek.citatel, zlomek.jmenovatel);
	return Zlomek{ zlomek.citatel / nd , zlomek.jmenovatel / nd }; // vratime zlomek, kteremu citatel i jmenovatel vydelime nejvetsim spolecnym delitelem

	// alternativne by slo misto jednoradkoveho returnu napsat toto:
	/*
	Zlomek zt;
	zt.citatel = zlomek.citatel / nd;
	zt.jmenovatel = zlomek.jmenovatel / nd;
	return zt;
	*/
}

enum svetovaStrana {SEVER, JIH, ZAPAD, VYCHOD};
// to stejne bychom bez enumu vytvareli nasledovne:
//const unsigned int SEVER = 0;
//const unsigned int JIH = 1;
//const unsigned int ZAPAD = 2;
//const unsigned int VYCHOD = 3;


// funkce, ktera otoci retezec 
// ma na vstupu pole znaku (charu) a delku pole
// ve funkci vyuzijeme cyklus for s vicenasobnou inicializici (2 promenne) a vicenasobnym krokem (2 kroky najednou)
void otoc_retezec(char a[], int delka) // pole a je ukazatel
{
	char pom; // pomocna promenna
	for (int i = 0, j = delka - 1; i < j; i++, j--) 
	{
		pom = a[i];  // do pomocne promenne si docasne ulozime hodnotu i-teho prvku
		a[i] = a[j]; // do i-teho prvku ulozime hodnotu j-teho prvku
		a[j] = pom;  // do j-teho prvku ulozime hodnotu i-teho prvku (nyni ulozena v promenne pom)
	}

	// to same bychom pomoci cyklu while napsali nasledovne:
	/*
	char pom;
	int i = 0;
	int j = delka - 1;
	while(i < j)
	{
		pom = a[i];
		a[i] = a[j];
		a[j] = pom;
		i++;
		j--;
	}
	*/
}

// Funkce si zadane promenne, ktere ji posilame v parametrech na zacatku vytvari sama znovu nove. 
// Pokud jim tedy zmenime hodnotu, zmenime ji pouze uvnitr funkce, ale parametr, kterym jsme funkci volali 
// zustane nezmenen. POZOR VYJIMKOU JSOU POLE !!! (pokud tem zmenime hodnoty, zmeni se v celem programu)
void zmen(int a)
{
	a = 5;
}

//funkce na nacteni nezaporneho cisla
//ve funkci bezi nekonecny cyklus, ve kterem nejprve vyzveme uzivatele k zadani nezaporneho cisla
//a) po jeho zadani nejprve zkontrolujeme zdali nedoslo k zablokovani vstupu - cin (uzivatel nezadal cislo)
//		pokud uzivatel cislo nezadal uvolnime vstupni proud cin, vycistime buffer od vsech hodnot zadanych uzivatelem
//		a pokracujeme na zacatek nekonecneho cyklu
//b) uzivatel zadal zaporne cislo
//		v tomto pripade nedoslo k zablokovani vstupniho proudu cin, informujeme uzivatele o jeho chybe a vratime se na zacatek cyklu
//c) uzivatel zadal nezaporne cislo -> funkce vrati zadane cislo uzivatelem
int nacti_nezaporne()
{
	int n; // promena, do ktere ulozime vstup od uzivatele
	for (;;) // nekonecny cyklus pres prikaz for - pouzivana alternativa: while(true)
	{
		// Zacatek cyklu
		// vyzveme uzivatele k zadani nezaporneho cisla
		cout << "Zadejte nezaporne cislo: ";
		cin >> n;

		if (!cin) // a) Kontrola, zda-li nedoslo k zablokovani vstupniho proudu nespravnym vstupem
		{
			cout << "Nezadali jste cislo" << endl; // informujeme uzivatele
			cin.clear();						   // uvolneni vstupniho proudu
			cin.ignore(256, '\n');				   // vycisteni bufferu (v bufferu se totiz porad nachazi vstup, ktery nam zablokoval vstupni proud.
			//    Pokud bychom znovu zavolali cin >> n. Znovu by se nacetla tento stary vstup a opet by doslo k chybe. (vysledkem by byl nekonecny cyklus ...)
			continue; // vrat se na zacatek cyklu
		}
		if (n < 0) // b) Kontrola zda-li uzivatel nezadal zaporne cislo 
		{
			cout << "Zadali jste zaporne cislo" << endl; // informujeme uzivatele
			continue;									 // vrat se na zacatek cyklu
		}
		// (Az sem se dostaneme pouze v pripade, ze uzivatel zadal korektni nezaporny cislo na vstupu) 
		return n;  // v promenne n se nachazi nezaporne cislo -> vrat toto cislo 
		// return ukoncuje funkci tedy i zaroven nekonecny cyklus, v kterem se nachazi
	}
}

// funkce vypise 
void vypisSvetovouStranu(svetovaStrana strana)
{// konstanty enumu jsou automaticky pretypovany na unsigned inty, daji se proto pouzit ve switchi
	switch (strana) { 	
	case SEVER: // 0
		cout << "SEVER"<<endl;
		break;
	case JIH:	// 1
		cout << "JIH" << endl;
		break;
	case ZAPAD:	// 2
		cout << "ZAPAD" << endl;
		break;
	case VYCHOD://3
		cout << "VYCHOD" << endl;
		break;
	default:
		cout << "CHYBA";
	}
}

// funkce, ktera do koznole vypise matici
void vypisMatici(int a[][3]) // pozor prekladaci musime natvrdo rict, kolik sloupcu matice ma (pokud ji predavame jako parametr)
{
	for (int i = 0; i < 3; i++) // i-ty radek
	{
		cout << " ";
		for (int j = 0; j < 3; j++) // j-ty sloupec
		{
			cout << a[i][j] << " "; // vypis i-ty radek a j-ty sloupec matice
		}
		cout << endl; // po vypsani vsech sloupcu na i-tym radku ODRADKUJ (budem pokracovat dalsim radkem)
	}
}

// funkce vrati velikost zadaneho pole charu
int pocetPismen(char l[])
{
	int i = 0;
	while (l[i]) // pole charu jsou ukoncena znakem '\0', jakmile cyklus na tento znak dojde -> skonci
		i++;
	return i;    // promenna i dojela na konec retezce -> nachazi se v ni tedy delka retezce
}

int main()
{
	Zlomek z{ 15,25 };		// zlomek 15/25
	z = zakladniTvar(z);	// do zlomku z ulozime zlomek v zakladnim tvaru
	cout << z.citatel << "/" << z.jmenovatel << endl; // vypis zlomku

	// 1. mozna inicializace struktury pomoci mnozinovych zavorek ve stylu pole
	// atributy zadavame v poradi, v jakem jsou implementovane v definici struktury
	Student Martin = { "Martin", "Novak", 4, AIPV };
	// 2. mozna definice pomoci pristupu k atributum pres tecku .
	Student Jirka;
	Jirka.jmeno = "Jiri";
	Jirka.prijmeni = "Pospisil";
	Jirka.obor = JCH;
	Jirka.rocnik = 2;

	Student studenti[5]; // pole struktur
	studenti[0] = Martin;
	studenti[1] = Jirka;

	cout << studenti[0].jmeno;

	char l[] = "jaderka";
	cout << pocetPismen(l) << endl;

	int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // incializace matice
	int b[3][3] = { {9,8,7}, {6,5,4}, {3,2,1} };
	int c[3][3];

	// soucet matic 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];

	vypisMatici(c);

	svetovaStrana strana = JIH;
	vypisSvetovouStranu(strana);
	string pole[] = {"SEVER", "JIH", "ZAPAD", "VYCHOD"};
	cout << pole[SEVER] <<endl;// konstanty v enumu muzeme pouzivat k indexovani pole

	int nezaporne = nacti_nezaporne();
	cout << nezaporne <<endl;

	char slovo[] = "karelopicka";
	otoc_retezec(slovo, 11);
	cout << slovo << endl;

	//int a = 4;
	//zmen(a);
	//cout << a;

	//int pole[] = { 1,2,3,4 };
	//cout << pole;
}