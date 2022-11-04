#include "Seznam.h"

void vytvorSeznam(Seznam& s)
{
	s.hlava = s.zarazka = nullptr;
}

void vlozNaZacatekSeznamu(Seznam& s, int data)
{
	/*
	Prvek* p = new Prvek;
	p->data = data;
	p->dalsi = s.hlava;
	s.hlava = p;
	*/

	s.hlava = new Prvek{ data, s.hlava };
}