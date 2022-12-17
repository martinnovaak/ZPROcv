#pragma once
#include <initializer_list>
#include <assert.h>
#include <algorithm>
#include <memory>


// Trida reprezenzujici Chytre Pole
template <typename T>
class ChytrePole
{
private:
	std::unique_ptr<T[]> pole; //  pole cisel
	unsigned int n;		       //  maximalni delka pole
	unsigned int k;			   //  pocet prvku - zaroven index pridavaneho prvku
	
	void zvetsi_se() // grow()
	{
		// vytvorime nove pole, ktere bude mit 2x tolik prvku
		n *= 2;
		std::unique_ptr<T[]> nPole = std::make_unique<T[]>(n); // vytvor chytry ukazatel na pole delky n
		for (unsigned int i = 0; i < k; i++)
			nPole[i] = pole[i]; // prekopirujeme data do noveho pole
		pole = std::move(nPole);  // ukazatel na pole zmenime na nove pole
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
	ChytrePole() : pole(std::make_unique<T[]>(4)), n(4), k(0) { } // konstruktor
	
	ChytrePole(unsigned int delka) : pole(std::make_unique<T[]>(delka)), n(delka), k(0)  { } // konstruktor s parametrem
	
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
	
	~ChytrePole() = default; // destruktor s klicovym slovem default - nechame implementaci na prekladaci
		// tedy nechame na prekladaci, aby uvolnil pamet v unique_ptr

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
		std::sort(pole.get(), pole.get() + k); // zavolani funkce sort za vyuziti pole
	}

	// vyuziti funkce sort v knihovne algorithm za pouziti naseho iteratoru
	// za pouziti vlastniho komparatoru (ukazatele na funkci pro porovnani)
	void setrid(bool (*porovnej)(T, T)) 
	{
		std::sort(pole.get(), pole.get() + k, porovnej); // zavolani funke sort za vyuziti iteratoru a komparatoru
	}

	// Ukazka vyuziti tridy komparator
	// ukazka je neefektivni implementoval jsem pouze jednoduchy selection sort
	// chtel jsem jen ukazat, kde se nas specialni komparator pouzije
	template <typename Komparator> 
	void setrid(Komparator porovnej) 
	{
		std::sort(pole.get(), pole.get() + k, porovnej);
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
	class Iterator			   //  trida Iterator je private, aby uzivatel sam nemohl vytvaret instance
	{
	private:
		T* pole; // ukazatel na nejaky prvek pole (vyuzivame aritmetiky ukazatelu)
	public:
		Iterator(T* p) : pole(p) {}

		bool operator!=(const Iterator& I) const  // operator na porovnani dvou iteratoru
		{
			return this->pole != I.pole;
		}

		Iterator& operator++() // posunuti operatoru
		{
			pole++;  // vyuziti aritmetiky ukazatelu pro posun po poli
			return *this;
		}

		T& operator*()   // dereference ukazatele - vratime hodnotu, na kterou iterator ukazuje
		{
			return *pole;
		}
	};
public:
	// Metody pro volani Iteratoru:
	Iterator begin() 
	{ // begin vrati iterator s ukazatelem na prvni prvek pole
		return Iterator(pole.get()); // k prvku ulozenymu v unique pointeru pristupujeme pres metodu get (getter)
	}  

	Iterator end() 
	{ // end vrati iterator s ukazatelem na prvek za poslednim prvkem pole
		return Iterator(pole.get() + k); // k prvku ulozenymu v unique pointeru pristupujeme pres metodu get (getter)
	}
};