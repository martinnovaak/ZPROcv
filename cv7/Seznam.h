#pragma once


struct Prvek // Node
{
	int data;
	Prvek* dalsi;
};

struct Seznam
{
	Prvek* hlava; // head
	Prvek* zarazka; // tail
};

void vytvorSeznam(Seznam& s);
void vlozNaZacatekSeznamu(Seznam& s, int data);
void vlozNaKonecSeznamu(Seznam& s);
void odstranPrvni(Seznam& s);
void vypisSeznam(Seznam& s);
bool jeSeznamPrazdny(Seznam& s);
