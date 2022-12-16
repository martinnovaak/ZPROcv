#include <iostream>
#include "ChytrePole.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Zamestnanec
{
	string jmeno;
	string prijmeni;
	unsigned int vek;
};

// vlastni trida Komparator
struct Komparator
{
	bool operator()(Zamestnanec a, Zamestnanec b)
	{
		return a.vek < b.vek;
	}
};

// vlastni funkce, ktera bude slouzit jako komparator
bool porovnej(const Zamestnanec& a, const Zamestnanec b)
{
	return a.vek < b.vek;
}

// mala ukazka na dedeni
// vytvorime tridu SortedVector, bude se jednat o klasicky vector, 
// ale rozsirime jej o metodu sort_vector, ktera vector setridi
template <typename T>
class SortedVector : public vector<T>
{
public:
	using vector<T>::vector;

	void sort_vector()
	{
		sort(this->begin(), this->end());
	}
};

int main()
{
	ChytrePole<int> vi = { 8,4,3,2 }; // zavolani konstruktoru s initializer_list
	vi.setrid(); // zavolani klasicke metody setrid
	for (auto a : vi) // pouziti kontejneroveho foru na nas kontejner chytre pole - funguje diky implementaci vlastniho iteratoru
		cout << a << " ";


	ChytrePole<Zamestnanec> vz = { {"Alois", "Novotny", 45}, {"Ferda", "Mravenec", 60}, {"Antonin", "Dvorak", 34} };
	vz.setrid(porovnej); // zamestnance nemuzeme porovnavat operatorem < (i kdyz mohli bychom si operator < pretizit) a proto, posilame do metody setrid vlastni komparator (aktualne funkci porovnej)
	for (Zamestnanec z : vz)
		cout << z.jmeno << " " << z.prijmeni << " " << z.vek << " \n";
	
	ChytrePole<Zamestnanec> vz2 = { {"Alois", "Novotny", 45}, {"Ferda", "Mravenec", 60}, {"Antonin", "Dvorak", 34} };
	vz2.setrid(Komparator()); // setrizeni pomoci tridy Komparator
	for (Zamestnanec z : vz2)
		cout << z.jmeno << " " << z.prijmeni << " " << z.vek << " \n";


	vector<string> vs = { "lopata" };	
}