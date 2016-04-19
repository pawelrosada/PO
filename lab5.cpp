#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

class Object
{
private:
	string name;
	int x, y;
public:
	Object(int a, int b)
	{
		x = a;
		y = b;
		char w = (rand() % 20) + 65;
		ostringstream ss;
		ss << w;
		name = ss.str() +"name";
	}
	string get_name()
	{
		return name;
	}
};
class Room
{
private:
	string description;
	int x, y;
	Room *n, *s, *e, *w;
	Object *object;
public:
	//set
	Room(){};
	Room(int a, int b)
	{
		x = a;
		y = b;
		char w = (rand() % 24) + 65;
		ostringstream ss;
		ss << w;
		description = ss.str() + "name";
		n = NULL;
		s = NULL;
		e = NULL;
		w = NULL;
		object = NULL;
	}
	void set_pointer_n(Room **a)
	{
		n = *a;
	}
	void set_pointer_s(Room **a)
	{
		s = *a;
	}
	void set_pointer_e(Room **a)
	{
		e = *a;
	}
	void set_pointer_w(Room **a)
	{
		w = *a;
	}
	void set_object(Object *a)
	{
		object = a;
	}

	//get
	string get_description()
	{

	}
	Room *get_pointer_n()
	{
		return n;
	}
	Room *get_pointer_s()
	{
		return s;
	}
	Room *get_pointer_e()
	{
		return e;
	}
	Room *get_pointer_w()
	{
		return w;
	}
	Object *get_object()
	{
		return object;
	}
	string get_object_name()
	{
		return object->get_name();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	char tab[5][9] = {' '};
	Room *rooms[3][7];
	for (unsigned int i = 0; i<3; i++)
		for (unsigned int j = 0; j<7; j++)
			rooms[i][j] = new Room(i, j);
	
	delete rooms[0][2];
	rooms[0][2] = NULL;
	delete rooms[0][4];
	rooms[0][4] = NULL;
	delete rooms[1][0];
	rooms[1][0] = NULL;
	delete rooms[1][6];
	rooms[1][6] = NULL;
	delete rooms[2][2];
	rooms[2][2] = NULL;
	delete rooms[2][4];
	rooms[2][4] = NULL;

	//ustawianie wskaŸników
	//lewa
	rooms[0][0]->set_pointer_e(&rooms[0][1]);
	rooms[0][1]->set_pointer_w(&rooms[0][0]);

	rooms[0][1]->set_pointer_s(&rooms[1][1]);
	rooms[1][1]->set_pointer_n(&rooms[0][1]);

	rooms[1][1]->set_pointer_s(&rooms[2][1]);
	rooms[2][1]->set_pointer_n(&rooms[1][1]);

	rooms[2][0]->set_pointer_e(&rooms[2][1]);
	rooms[2][1]->set_pointer_w(&rooms[2][0]);

	rooms[1][1]->set_pointer_e(&rooms[1][2]);
	rooms[1][2]->set_pointer_w(&rooms[1][1]);

	//œrodek
	rooms[1][2]->set_pointer_e(&rooms[1][3]);
	rooms[1][3]->set_pointer_w(&rooms[1][2]);

	rooms[1][2]->set_pointer_e(&rooms[1][3]);
	rooms[1][3]->set_pointer_w(&rooms[1][2]);

	rooms[1][3]->set_pointer_n(&rooms[0][3]);
	rooms[0][3]->set_pointer_s(&rooms[1][3]);

	rooms[1][3]->set_pointer_s(&rooms[2][3]);
	rooms[2][3]->set_pointer_n(&rooms[1][3]);

	rooms[1][3]->set_pointer_e(&rooms[1][4]);
	rooms[1][4]->set_pointer_w(&rooms[1][3]);

	//koniec
	rooms[1][4]->set_pointer_e(&rooms[1][5]);
	rooms[1][5]->set_pointer_w(&rooms[1][4]);

	rooms[1][5]->set_pointer_n(&rooms[0][5]);
	rooms[0][5]->set_pointer_s(&rooms[1][5]);

	rooms[0][5]->set_pointer_e(&rooms[0][6]);
	rooms[0][6]->set_pointer_w(&rooms[0][5]);

	rooms[1][5]->set_pointer_s(&rooms[2][5]);
	rooms[2][5]->set_pointer_n(&rooms[1][5]);

	rooms[2][5]->set_pointer_e(&rooms[2][6]);
	rooms[2][6]->set_pointer_w(&rooms[2][5]);

	//wyœwietlanie pomieszczenia
	cout <<"Wyswietlanie pomieszczenia" << endl<<endl;
	for (unsigned int i = 0; i<3; i++)
		for (unsigned int j = 0; j<7; j++)
		{
			if (rooms[i][j] != NULL) tab[i+1][j+1] = '#';
			if (rooms[i][j] == NULL) tab[i+1][j+1] = 'X';
			else
			{

				if (rooms[i][j]->get_pointer_e() == NULL) tab[i+1][j+2] = 'X';
				if (rooms[i][j]->get_pointer_w() == NULL) tab[i+1][j] = 'X';
				if (rooms[i][j]->get_pointer_n() == NULL) tab[i][j+1] = 'X';
				if (rooms[i][j]->get_pointer_s() == NULL) tab[i+2][j+1] = 'X';
				
			}
		}
	for (unsigned int i = 0; i < 5; i++)
	{
		for (unsigned int j = 0; j < 9; j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}

	//losowanie i tworzenie obiektów
	unsigned int x, y, z=0;
	srand(static_cast<unsigned int>(time(NULL)));
	while (z != 3)
	{
		x = rand() % 2;
		y = rand() % 6;
		if (rooms[x][y] != NULL)
		{
			if (rooms[x][y]->get_object() == NULL)
			{
				rooms[x][y]->set_object(new Object(x, y));
				z++;
			}
		}
	}

	//przejscie przez pomieszczenia
	cout <<endl<<"Przejscie przez pomieszczenie" << endl << endl;
	string way = "essweneesnnseenewsse";
	x = 0;
	y = 0;
	unsigned int i=1, j=1, a=0, b=0;
	while (x != way.length())
	{
		if (tab[i][j] != 'X' || tab[i][j] != ' ') y++;
		if (rooms[a][b]->get_object() != NULL)
		{
			string pom = rooms[a][b]->get_object_name();
			cout << "przejscie numer: " << y << " nazwa: " << pom << endl;
			tab[i][j] = pom[0];
		}
			if (way[x] == 'e') { j++; b++; }
			if (way[x] == 'w') { j--; b--; }
			if (way[x] == 's') { i++; a++; }
			if (way[x] == 'n') { i--; a--; }
			x++;
		}
	cout << "ilosc przejsc: " << y << endl;;

	//wyœwietlenie tablicy po przejœciu
	for (unsigned int i = 0; i < 5; i++)
	{
		for (unsigned int j = 0; j < 9; j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}

	//najkrótsza droga
	cout << endl << "Znajdowanie najkrotszej drogi" << endl << endl;
	y = 0;
	x = 0;
	a = 0;
	b = 0;
	i = 1;
	j = 1;
	while (x != way.length())
	{
		if (tab[i][j] != 'X' || tab[i][j] != ' ') y++;
		if (rooms[a][b]->get_object() != NULL)
		{
			string pom = rooms[a][b]->get_object_name();
			cout << "przejscie numer: " << y << " nazwa: " << pom << endl;
			tab[i][j] = pom[0];
		}
		if (a == 1 && b == 1)
		{
			if ((rooms[2][1]->get_object() == NULL) && (rooms[2][0]->get_object() == NULL))  x = 6;
		}
		if (a == 1 && b == 3)
		{
			if ((rooms[0][3]->get_object() == NULL) && (rooms[2][3]->get_object() == NULL))  x = 12;
		}
		if (a == 1 && b == 5)
		{
			if ((rooms[0][5]->get_object() == NULL) && (rooms[0][6]->get_object() == NULL))  x = 19;
		}
		if (way[x] == 'e') { j++; b++; x++; }
		else if (way[x] == 'w') { j--; b--; x++; }
		else if (way[x] == 's') { i++; a++; x++; }
		else if (way[x] == 'n') { i--; a--; x++; }
		
	}
	cout << "ilosc przejsc: " << y << endl;;


	//generowanie pomieszczenia o dwolnej dlugoœci
	cout << endl << "Generowanie pomieszczenia o dwolnej dlugosci" << endl << endl;
	int n = 21;

	Room **tab2[3];
	for (int i = 0; i < 3; i++)
		tab2[i] = new Room*[n];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == 1 && j == 0) tab2[i][j] = NULL;
			if (i == 1 && j == n-1) tab2[i][j] = NULL;
			if (i == 0 && j == 2) tab2[i][j] = NULL;
			if (j == 2)
			{
				tab2[0][j] = NULL;
				tab2[2][j] = NULL;
			}
			if ( j == n - 3)
			{
				tab2[0][j] = NULL;
				tab2[2][j] = NULL;
			}
		}

	for (int i = 0; i < n; i++)
		{
			if (i > 3 && i < n - 3)
			{
				tab2[0][i] = NULL;
				tab2[2][i] = NULL;
				i++;
			}
		}

	//wypisanie
	for (unsigned int i = 0; i<3; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (tab2[i][j] == NULL) cout << "X";
			else cout << "#";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

