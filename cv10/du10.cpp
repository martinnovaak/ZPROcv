#include <fstream>
#include <string>
using namespace std;

// Napiste funkci, ktera vrati pocet radek souboru "nazev"
int pocet_radku(const string & nazev)
{
	return -1;
}
// max 0,3 bodu


// Napiste funkci, ktera "otoci" soubor: 
// slova vypise v opacnem poradi do souboru s nazvem nazev_vystup
// funkce vrati true, pokud byla operace uspesna, jinak false
// muzete vyuzit jakoukoli kontejnerovou strukturu z hodiny (napr list)
bool otoc_soubor(const string& nazev_zdroj, const string& nazev_vystup)
{
	return false;
}
// max 0,5 bodu


// v souboru english_words.txt se nachazi dataset anglickych slov
// do jineho souboru ulozte pouze slova, ktera neobsahuji specialni znaky, cisla ani velka pismena
// tedy pouze slova, ktera obsahuji pouze a jen znaky: abcdefghijklmnopqrstuvwxyz
// zaroven ukladejte pouze slova, ktere maji alespon 3 znaky a ne vice nez 14 znaku
// neni potreba vyuzivat regularnich vyrazu (nejsou soucasti tohoto kurzu)
// trida string obsahuje metody, se kterymi si vystacime 
// metody si muzete dohledat na :https://cplusplus.com/reference/string/string/
bool anglicka_slova(const string& nazev_souboru, const string& novy_soubor)
{
	return false;
}
// max 1 bod