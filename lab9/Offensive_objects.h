#pragma once
#include "game_objects.h"
class Offensive_objects : public Game_objects
{
private:
	int attack;
	string shout;
public:
	Offensive_objects(int, string, int, string);
	int get_damage();
	string get_shout();
	int do_fight(int);
	int get_health();
};

