// program9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "Offensive_objects.h"
#include "Passive_objects.h"

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Offensive_objects*> game;
	Offensive_objects *player=new Offensive_objects(10000, "Atak!", 1, "Gracz");
	game.push_back(player);
	Offensive_objects *monsters[5];
	for (unsigned int i=0; i<5; i++)
	{
		monsters[i]=new Offensive_objects(i+2, "Atakuje!", 3, "Potworek"+i);
		game.push_back(monsters[i]);
	}
	Passive_objects *defence[5];
	for (unsigned int i=0; i<5; i++)
	{
		defence[i]=new Passive_objects(i+2, i, i-1, "Przeszkoda");
	}
	
	while (game.size() != 0)
	{
		int i=1;
		Offensive_objects *player;
		player=game[0];
		player->do_fight(game[i]->do_fight(player->get_damage()));
		if (player->get_health()<=0) std::cout<<endl<<endl<<endl<<"gracz ginie";
		else if (game[i]->get_health()<=0) 
			{
				std::cout<<"Potworek ginie";
				i++;
			}

		system("pause");
	}
	return 0;
}

