#include "Zlomek.h"
#include <iostream>
using namespace std;


unsigned int nsd(unsigned int a, unsigned int b)
{
	return (b == 0) ? a : nsd(b, a % b);
}


// konstruktor prirazeni hodnot atributum zpusobem pres : za deklaraci metody
Zlomek::Zlomek(unsigned int citatel, unsigned int jmenovatel) 
	: citatel(citatel), jmenovatel(jmenovatel)
{}

// zakladni tvar zlomku
void Zlomek::zakladniTvar()
{
	unsigned int nd = nsd(citatel, jmenovatel);
	citatel /= nd;
	jmenovatel /= nd;
}

void vypis(Zlomek& z)
{
	//cout << z.getCitatel() << "/" << z.getJmenovatel() << endl;
	cout << z.citatel << "/" << z.jmenovatel << endl;
}

// Setter pro zlomek
void Zlomek::set(unsigned int citatel, unsigned int jmenovatel)
{
	/*
	TODO
	*/
}
// 0,2 bodu

// metoda, ktera pricte k aktualni instanci zlomek a
// a nasledne prevede zlomek do zakladniho tvaru
void Zlomek::pricti(const Zlomek& a)
{
	/*
	TODO
	*/
}
// max 0,5 bodu

// metoda, ktera vynasobi aktualni instanci zlomkem a
// a nasledne prevede zlomek do zakladniho tvaru
void Zlomek::vynasob(const Zlomek& a)
{
	/*
	TODO
	*/
}
// max 0,4 bodu