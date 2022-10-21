#include <iostream>
#include <cmath> // kvuli funkci pow
using namespace std;

struct Statistika
{
	int median;
	int modus;
};

// Napiste funkci na vypis pole
// Funkci jsem predepsal sablonove, aby dokazala vypsat jak celociselna tak realna pole (int pole[] i double pole[])
// ovsem vypis muzete programovat stejnym zpusobem jako kdyby to byla funkce:
// void vypis(int pole[], unsigned int delka)
template <typename T> void vypis(T pole[], unsigned int delka)
{
	
}
// max 0,1 bodu
//______________________________________________________________________


// Napiste funkci, ktera vrati aritmeticky prumer z vyberu hodnot nachazejicich se v poli 
double aritmetickyPrumer(double vyber[], unsigned int delka)
{
	
}
// max 0,2 bodu
//______________________________________________________________________

// Napiste funkci, ktera vrati geometricky prumer z vyberu hodnot nachazejicich se v poli
double geometrickyPrumer(double vyber[], unsigned int delka)
{
	// n-ta odmocnina:
	// odmocnina = pow(cislo, 1.0/delka); // umocneni na 1/n je n-ta odmocnina
}
// max 0,2 bodu
//______________________________________________________________________

// Napiste funkci, ktera overi zda-li jsou dva vektory kolme
// v pripade ze vektory kolme jsou funkce vrati hodnotu TRUE, jinak vrati FALSE
// napoveda 1: pouzijte standardni skalarni soucin
// napoveda 2: pozor pracujete s doubly pri vsech mat. operacich (+,-,*, ...) dochazi k chybam, je treba to zohlednit
bool kolmostVektoru(double v1[], double v2[], unsigned int delka)
{
	
}
// max 0,3 bodu
//______________________________________________________________________


// Napiste funkci, ktera setridi pole (int pole[]) bublinkove 
// naprogramujte jeden z pseudokodu z ceske wikipedie: 
// https://cs.wikipedia.org/wiki/Bublinkov%C3%A9_%C5%99azen%C3%AD
// napoveda ocekava se cyklus do while !
void trideniBublinkove(int pole[], unsigned int delka)
{

}
// max 0,5 bodu
//______________________________________________________________________

// Napiste funkci, ktera setridi pole (int pole[]) vkladanim 
// naprogramujte pseudokod z ceske wikipedie:
// https://cs.wikipedia.org/wiki/%C5%98azen%C3%AD_vkl%C3%A1d%C3%A1n%C3%ADm
void trideniVkladanim(int pole[], unsigned int delka)
{

}
// max 0,5 bodu
//______________________________________________________________________

// Napiste funkci, ktera setridi pole (int pole[]) razenim
// zde jsem ceskou wikipedii podrazenej, protoze tam misto pseudokodu hodili rovnou kod v C
// https://cs.wikipedia.org/wiki/%C5%98azen%C3%AD_v%C3%BDb%C4%9Brem
// porad se muzete inspirovat
// ale chci abyste razeni delali opacnym zpusobem nez na wiki: a to tak, ze budete nachazet nejvetsi prvky 
// pole, a ty budete davat postupne na konec pole
void trideniVyberem(int pole[], unsigned int delka)
{
	
}
// max 0,5 bodu za, ktera nebude totozna s tou ve wikipedii
//_______________________________________________________________________

// Napiste funkci, ktera vypocte moud a median vyberu
// obe statistiky ulozi do struktury Statistika a vrati ji pomoci return
// Napoveda: pro median i modus je pole treba nejprve setridit
// v pripade ze modus neexistuje ulozte hodnotu -1
Statistika modus_median(int vyber[], unsigned int delka)
{

}
// max 0,5 bodu
//________________________________________________________________________


int main()
{
	// pole, ktere muzete pouzit pro overeni spravnych vysledku
	const unsigned int delka = 101;
	int pole[delka] = { 54, 94, 65, 51, 39, 63, 30, 28, 23, 21, 88, 49, 83, 60, 35, 44, 29, 31, 86, 6, 95, 64, 32, 18, 72, 25, 87, 16, 33, 93, 76, 99, 22, 51, 12, 70, 51, 92, 42, 8, 38, 9, 20, 5, 41, 26, 91, 57, 69, 96, 13, 27, 61, 43, 24, 37, 78, 17, 40, 52, 59, 45, 66 ,47 ,62, 85, 4, 89, 82, 53, 74, 3, 73, 75, 100, 67, 68, 97, 71, 79, 48, 19, 84, 58, 14, 34, 80, 90, 81, 56, 46, 11, 98, 10, 55, 15, 2, 1, 36, 7, 77 };
	
	
	// vypis(pole, delka);
	// trideniBublinkove(pole, delka);
	// trideniVkladanim(pole, delka);
	// trideniVyberem(pole, delka);
	// vypis(pole, delka);
	// Statistika s = modus_median(pole, delka);
	// cout << "Median: " << s.median << ", Modus: " << s.modus << endl;

	const unsigned int n = 10;
	double cisla[]{ 86.009, 22.342, 5.768, 4.235, 62.295, 87.811, 66.136, 24.353, 67.935, 37.942 };
	// cout << "Aritmeticky prumer: " << aritmetickyPrumer(cisla, n) << ", ";
	// cout << "Geometricky prumer : " << geometrickyPrumer(cisla, n) << endl;

	double v1[]{ 4.0, 2.0, 3.0};
	double v2[]{ 0.0, -3.0, 2.0};
	double v3[]{ 2.0, 1.0, 1.5};
	// if (kolmostVektoru(v1, v2, n))
	//	 cout << "v1 a v2 jsou kolme \n";
	// else
	//	 cout << "v1 a v2 nejsou kolme \n";

	return 0;
}