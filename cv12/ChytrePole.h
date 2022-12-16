#pragma once
#include <initializer_list>
#include <assert.h>
#include <algorithm>
using namespace std;

// Trida reprezenzujici Chytre Pole
template <typename T>
class ChytrePole
{
private:
	T* pole;		  // pole cisel
	unsigned int n;		      // maximalni delka pole
	unsigned int k;			  // pocet prvku - zaroven index pridavaneho prvku

	void inicializuj(unsigned int delka) // inicializacni funkce Chytreho Pole
	{
		pole = new T[delka];
		k = 0;
		n = delka;
	}   
	void zrus() // zruseni dynamicky alokovane pameti
	{
		delete[] pole;
		k = n = 0;
	}						
	void zvetsi_se() // grow()
	{
		// vytvorime nove pole, ktere bude mit 2x tolik prvku
		n *= 2;
		T* nPole = new T[n];
		for (unsigned int i = 0; i < k; i++)
			nPole[i] = pole[i]; // prekopirujeme data do noveho pole
		delete[] pole; // stare pole smazeme
		pole = nPole;  // ukazatel na pole zmenime na nove pole
	}

	// Pokud je delka pole podstatne mensi nez alokovane velikosti 
	// (tradicne 1/4, ale necham na vas, co povazujete za podstatne mensi velikost)
	// tak zmensi alokovanou velikost na polovinu (pripadne si opet muzete sami upravit velikost)
	void zmensi_se()  // tzv shrink metoda
	{
		/*
		TODO
		*/
	}
	// 1 bod

public:
	ChytrePole() { inicializuj(4); } // konstruktor
	
	ChytrePole(unsigned int delka)   { inicializuj(delka); } // konstruktor s parametrem
	
	ChytrePole(ChytrePole& chp) : ChytrePole(chp.n) // kopirovaci konstruktor
	{
		this->k = chp.k;
		for (unsigned int i = 0; i < chp.k; i++)
			this->pole[i] = chp.pole[i];
	} 
	// konstruktor s initializer_listem 
	ChytrePole(std::initializer_list<T> ilist) : ChytrePole(ilist.size() * 1.5)
	{   
		for (T c : ilist) pridat_na_konec(c);
	}
	
	~ChytrePole(){ zrus();} // destruktor

	void pridat_na_konec(T c) // vlozeni prvku na konec Chytreho Pole
	{
		if (k >= n)      // pokud je pole plne
			zvetsi_se(); // zvetsi pole
		pole[k] = c;     // na k-tou pozici ulozime promennou c
		k++;			 // pocet prvku se zvetsil o 1
	}  
	
	// DU 12
	void pridat_na_konec(std::initializer_list<T> ilist)
	{
		/*
		TODO
		*/
	}
	// 1 bod

	bool prazdne() { return k == 0;}	// funkce vracejici informaci, zda-li je Chytre Pole prazdne
	int  delka() { return k; }			// pocet prvku pole

	T& get(unsigned int i) const // get at
	{
		assert(i < k); // aserce - pokud je i >= k tak vyhodime vyjimku
		return this->pole[i];
	}
	T& operator[](unsigned int i) { return get(i); }

	// vyuziti funkce sort v knihovne algorithm za pouziti naseho iteratoru
	// bez komparatoru, pouzije se automaticky operator < 
	void setrid()
	{
		sort(pole, pole + k); // zavolani funkce sort za vyuziti pole
	}

	// vyuziti funkce sort v knihovne algorithm za pouziti naseho iteratoru
	// za pouziti vlastniho komparatoru (ukazatele na funkci pro porovnani)
	void setrid(bool (*porovnej)(T, T))
	{
		sort(pole, pole + k, porovnej); // zavolani funke sort za vyuziti iteratoru a komparatoru
	}

	// Ukazka vyuziti tridy komparator
	// ukazka je neefektivni implementoval jsem pouze jednoduchy selection sort
	// chtel jsem jen ukazat, kde se nas specialni komparator pouzije
	template <typename Komparator> 
	void setrid(Komparator porovnej)
	{
		sort(pole, pole + k, porovnej);
		/*
		unsigned int i, j, min_idx;
		for (i = 0; i < k - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < k; j++)
				if (porovnej(pole[j],pole[min_idx])) // zde se vyuziva nas vlastni komparator
					min_idx = j;
			if (min_idx != i)
			{
				T t = pole[min_idx];
				pole[min_idx] = pole[i];
				pole[i] = t;
			}
		}
		*/
	}

	// vloz na i-tou pozici prvek t
	void vloz(T t, unsigned int i) // insert
	{
		/*
		TODO
		*/
	}
	// 1 bod

	// Otoc poradi prvku pole
	void otoc_pole() // reverse
	{
		/*
		TODO
		*/
	}
	// 0,5 bodu

	// funkce, ktera vyjme i-ty prvek z ChytrehoPole
	void odstran(unsigned int index)
	{
		assert(index < k); // ujisti se, ze i lezi v delce pole

		// posun prvky pole o 1 doleva za i-tym prvkem
		for (unsigned int i = index; i < k - 1; i++)
			pole[i] = pole[i + 1];

		k--; // delka Chytreho Pole se zmensila

		zmensi_se(); // shrink
	}

	void odstran_posledni() 
	{
		assert(k > 0); // ujisti se, ze chytre pole obsahuje alespon 1 prvek
		k--;		   // zmensi velikost pole o 1
		zmensi_se();   // zavola metodu shrink
	}

	// najdi a vrat index, na kterem se nachazi prvek t v poli
	// za vyuziti komparatoru
	template <typename Komparator>
	int najdi(T t, Komparator komp)
	{
		/*
		TODO
		*/
		return -1; // return -1 v pripade ze se v poli prvek t nenachazi
	}
	// 1 bod

	// uvolni pamet v poli a alokuje nove pole o zakladni velikosti
	void vycisti()
	{
		/*
		TODO
		*/
	}
	// 0,5 bodu

	private: 
	class Iterator
	{
	private:
		T* pole; // ukazatel na nejaky prvek pole (vyuzivame aritmetiky ukazatelu)
	public:
		Iterator(T* pole) : pole(pole) {};
		bool operator!=(const Iterator& I) const { return this->pole != I.pole; }  // operator na porovnani dvou iteratoru
		Iterator& operator++() { pole++; return *this; } // vyuziti aritmetiky ukazatelu pro posun po poli
		T& operator*() { return *pole; }
	};
	public:
	Iterator begin() { return Iterator(pole); }  // begin vrati iterator s ukazatelem na prvni prvek pole
	Iterator end() { return Iterator(pole + k); }// end vrati iterator s ukazatelem na prvek za poslednim prvkem pole
};

