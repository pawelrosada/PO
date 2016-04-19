#include "stdafx.h"
#include <iostream>
#include "Offensive_objects.h"

Offensive_objects::Offensive_objects(int _health, string _shout, int _attack, string _object_name)
{
		health=_health;
		attack=_attack;
		shout=_shout;
		object_name=_object_name;
}
int Offensive_objects::get_damage()
{
	return attack;
}
string Offensive_objects::get_shout()
{
	return shout;
}
int Offensive_objects::get_health()
{
	return health;
}
int Offensive_objects::do_fight(int damage)
{
	std::cout<<shout<<" Iloœæ ¿ycia: "<<health<<"Attack: "<<get_damage();
	health-=damage;
	return get_damage();
}