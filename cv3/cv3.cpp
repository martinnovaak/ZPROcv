#include <iostream>
#include "Header.h"
#include <limits.h> // knihovna obsahujici makra INT_MAX SHRT_MIN apod.
#include <limits>   // knihovna obsahujici tridu numeric_limits
#include <string>
using namespace std;

typedef int cislo; // alternativni nazev pro typ int

int nsd(int x, int y)
{
	//int delitel = 1; // promenna, do ktere ulozime nejvetsi spolecny delitel cisel x a y
	int mensi = (x < y) ? x : y;
	int i = mensi;
	while ((x % i != 0) || (y % i != 0))
	{
		i--;
	}
	return i;
}

// nejmensi spolecny delitel pres Eukliduv algoritmus
int euklid(int u, int w)
{
	int r;
	while (w != 0)
	{
		r = u % w;
		u = w;
		w = r;
	}
	return u;
}

int nsn(int x, int y)
{
	return x * y / euklid(x, y);
}

bool fibanocci(int x)
{
	if (x == 1 || x == 0)
		return true;
	else if (x < 0)
		return false;
	int f = 2, f_prev = 1, pom;
	while (f < x) {
		pom = f;
		f += f_prev;
		f_prev = pom;
	}
	return x == f; // stejne jako return (x == f) ? true : false;
}

int maximum(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
	//return (x >= y) ? x : y;
}

int maximum(int a, int b, int c, int d)
{
	/*
	int max1 = maximum(a, b);
	int max2 = maximum(c, d);
	return maximum(max1, max2);
	*/

	return maximum(maximum(a, b), maximum(c, d));
}

bool jeMale(char ch)
{
	/*if ('a' <= ch && ch <= 'z')
		return true;
	return false;*/
	return 'a' <= ch && ch <= 'z';
}

// fce, ktera prevede maly znak na velky
char naVelke(char ch)
{
	if (jeMale(ch))
	{
		ch -= 'u';
		ch += 'U';
	}
	return ch;
}


int main()
{
	cout << '\n'; // charakter pro novy radek


	// prace se stringem
	string slovo = "slovo";
	cout << slovo.length();
	//cout << slovo.at(2);
	int j = 0;
	char ch;
	while (j < slovo.length())
	{
		//cout << slovo.at(j++)<<endl;
		//cout << slovo[j++] << endl;
		ch = slovo[j];
		cout << ch << endl;
		slovo[j] = 'O';
		j++;
	}

	cout << slovo << endl;
	

	//preteceni intu
	int l = INT_MAX;
	cout << ++l; 

	// testovani charu
	cout << naVelke('o') << endl;
	/*
	char ch = 'a';
	cout << ch << endl;
	ch = 97;
	cout << ch << endl;
	cout << +ch << endl;
	*/


	// testovani <limits.h> a <limits>
	cout << INT_MAX << endl;
	cout << SHRT_MIN << endl;
	cout << numeric_limits<int>::epsilon() << endl;

	double i = 0.1;

	/* Nekonecny cyklus
	while (i != 1)
	{
		 i += 0.1;
		 cout << i << endl;
	}*/

	double a = 7.456698;
	int b = (int)a; // pretypovani promenne double na int
	cout << 5 / 7.0 << endl; // int / double
	return 0;
}
