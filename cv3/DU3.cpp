#include <string>
using namespace std;

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
		ch -= 'a';
		ch += 'A';
	}
	return ch;
}

// Prevedte vsechny male pismena ve stringu slovo na velka
// uzijte vhodne funkce char naVelke(char ch);
string naVelka(string slovo)
{
	/*
	TODO
	*/
	return slovo;
}

// najdete index (i-tou pozici), na ktere se nachazi znak ch ve stringu slovo
// v pripade ze se znak ch ve slove nenachazi vratte hodnotu -1
int najdiZnak(string slovo, char ch)
{
	int i = 0; 
	/*
	TODO
	*/
	return i;
}