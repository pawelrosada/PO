#pragma once
#include <string>
using namespace std;
class Game_objects
{
protected:
	int health;
	string object_name;
public:
	virtual int do_fight(){return 1;};
};

