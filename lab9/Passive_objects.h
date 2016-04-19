#pragma once
#include "game_objects.h"
class Passive_objects : public Game_objects
{
private:
	int defense;
	int size;
public:
	Passive_objects::Passive_objects(int, int, int, string);
	int get_defense();
	int get_size();
	int do_fight(int);
};

