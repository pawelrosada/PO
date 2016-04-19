#include "stdafx.h"
#include <iostream>
#include "Passive_objects.h"

Passive_objects::Passive_objects(int _health, int _size, int _defense, string _object_name)
{
	health=_health;
	size=_size;
	defense=_defense;
	object_name=_object_name;
}
int Passive_objects::get_size()
{
	return size;
}
int Passive_objects::get_defense()
{
	return defense;
}
int Passive_objects::do_fight(int damage)
{
	defense-=damage;
	return size;
}