#include <iostream>
#include <string>
using namespace std;

void vypisIndexy(string slovo, char ch)
{
	int index = 0;
	while (index < slovo.length())
	{
		if (slovo[index] == ch)
			cout << index;
		index++;
	}
	cout << endl;
}

void vypis(string s)
{
	int i = 0; 
	while (i < s.length())
		cout << s[i++];
	cout << endl;
}

bool zmen(string s)
{
	if (s.length())
	{
		s[0] = 'A';
		return true;
	}
	return false;
}

void vypis(int pole[], int n)
{
	/*
	int i = 0;
	while (i < n)
	{
		cout << pole[i];
		i++;
	}
	*/

	for (int i = 0; i < n; i++)
	{
		cout << pole[i];
	}
	cout << endl;
}

// pole p ma 3 prvky - koeficienty: a, b, c
void kvadraticka(double p[])
{
	double eps = 0.001;
	double determinant = p[1] * p[1] - 4 * p[0] * p[2];
	if (abs(determinant) < eps)
	{
		cout << -p[1] / (2 * p[0]) << endl;
	}
	else if (determinant > 0)
	{
		cout << ( -p[1] + sqrt(determinant)) / (2 * p[0]) << endl;
		cout << ( -p[1] - sqrt(determinant)) / (2 * p[0]) << endl;
	}
	else
		cout << "rovnice nema realne reseni. \n";
}

// funkce pro nalezeni nejvetsiho prvku pole
int nejvetsiPrvekPole(int data[], int n)
{
	int nejvetsi; // promenna, do ktere ulozim nejvetsi prvek pole
	if (n > 0) // pokud ma pole alespon jeden prvek
	{
		nejvetsi = data[0]; // do promenne nejvetsi ulozim prvni prvek pole
		int i = 1;
		while (i < n) // v cyklu projdu prvky pole s porovnam je docasnym nejvetsim prvkem, naleznu-li vetsi prvek ulozim jej do promenne nejvetsi
		{
			if (data[i] > nejvetsi)
				nejvetsi = data[i];
			i++;
		}
		// po skonceni cyklu se v promenne nejvetsi nachazi nejvetsi prvek pole
	} 
	else 
	{
		cout << "Prazdne pole";
		nejvetsi = INT_MIN;
	}
	return nejvetsi;
}

// pouziti prazdneho vyrazu
void najdiPrvniNulu(int pole[])
{
	int i = 0;
	while (pole[i++] != 0)
		; // prazdny vyraz
	cout << i - 1 << endl;
}

void vypisChybu(int chyba)
{
	switch (chyba)
	{
	case -1:
		cout << "Zadali jste zaporne cislo \n";
		break;
	case -2:
		cout << "Doslo k preteceni \n";
	default:
		cout << "Neznama chyba \n";
		break;
	}
}

int faktorial(int n)
{
	if (n < 0)
	{
		vypisChybu(-1);
		return -1;
	}
	else if(n == 0 || n == 1)
	{
		return 1;
	}
	else 
	{
		int fakt = 1;
		for (int i = 2; i <= n; i++)
		{
			fakt *= i;
		}
		return fakt;
	}
}

int main()
{
	//for pro rozsahy
	int A[3] = { 1,2,3 };
	for (auto prvek : A)
	{
		cout << prvek;
	}


	cout << faktorial(5) << endl;
	cout << faktorial(-5) << endl;
	vypisChybu(-2);
	//string text = "abe4ceda";
	//cout << isdigit(text[3]) << isdigit(text[1]);
	int data[] = { 14,48,7,32,12 };
	cout << nejvetsiPrvekPole(data, 5) << endl;
	int doplnenePole[20] = { 1,2,3,4,5,6 };
	najdiPrvniNulu(doplnenePole);

	double parametry[3] = { 1.0,0,0 };
	kvadraticka(parametry);


	int a[5] = { 1,2,3 };
	bool poleboolu[100] = { 0 };
	vypis(a, 5);

	/*int pole[100];
	int i = 0;
	while (i < 100)
	{
		pole[i] = i + 1;
		i++;
	}*/
	string s = "222";
	int cislo = stoi(s);
	char ch = 'a';
	cout << isdigit(s[1]);
	//vypisIndexy(s, ch);
	zmen(s);
	vypis(s);
}