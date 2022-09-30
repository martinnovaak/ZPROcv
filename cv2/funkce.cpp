#include "funkce.h"

const double pi = 3.14159265; // Globalni promenna

int maximum(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
	// return (a >= b) ? a : b;  // podmineny vyraz
}

float maximum(float a, float b)
{
	return (a >= b) ? a : b;
}

// stejnojmenna funkce s vice parametry
double maximum(double a, double b, double c)
{
	return maximum(maximum(a,b), c); // vyuziti toho ze jiz mam naprogramovanou funkci maximum pro dve promenne
}

double maximum(double a, double b)
{
	return (a >= b) ? a : b;
}

double obvodKruhu(double r)
{
	return 2 * r * pi;
}

double obsahKruhu(double r) // definice funkce
{
	return r * r * pi;
}

int faktorial(int n)
{
	int krok = 2, fakt = 1;
	while (krok <= n)
		fakt *= krok++;
	return fakt;
}