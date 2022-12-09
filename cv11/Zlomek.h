#pragma once

class Zlomek
{
private:
	// atributy
	unsigned int citatel;
	unsigned int jmenovatel;
public:
	// metody
	Zlomek(unsigned int citatel, unsigned int jmenovatel);
	//gettery
	unsigned int getCitatel() const { return citatel; } 
	unsigned int getJmenovatel() const { return jmenovatel; } 
	void zakladniTvar();

	// zpratelena funkce vypis
	friend void vypis(Zlomek& z);


	// DU11
	void set(unsigned int citatel, unsigned int jmenovatel); // setter
	void pricti(const Zlomek& a);  // pricte zlomek k aktualni instanci
	void vynasob(const Zlomek& a); // vynasobi aktualni instanci zlomkem 
};

void vypis(Zlomek & z);