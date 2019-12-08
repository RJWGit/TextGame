#include "Monster.h"



Monster::Monster(string name,string type, int hp, int attack, int defense, int gold,int chance, string description)
{
	_description = description;
	_name = name;
	_chance = chance;
	_hp = hp;
	_attack = attack;
	_defense = defense;
	_gold = gold;
	_type = type;
	_maxhp = hp;


}
Monster::Monster()
{}

//Damage
void Monster::takedamage(int damage)
{
	damage = damage - (_defense / 5);
	if (damage < 0) {
		_hp;
		return;
	}
	if (damage > 0) {
		_hp -= damage;
		return;
	}

}
int Monster::getspecialattack()
{
	int special;

	special = (_attack / 5)+_attack;
	return special;
	
}

//Add monsters
void Monster::addmonster(Monster &newmonster)
{

	_monsters.push_back(newmonster);
	return;

}
void Monster::initmonster(Monster &newmonster)
{
	list<Monster>::iterator lit;

	//Rng
	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(1,_monsters.size());
	int rng = roll(randomengine);
	
	for (lit = _monsters.begin(); lit != _monsters.end(); lit++) {
		if ((*lit).getchance1() == rng) {
			newmonster = (*lit);
			
			return;
		}
	}
}


//Attacks
bool Monster::miss (int defense)
{
	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(1, 500);
	
	int miss;

	miss = (defense/5);
	miss -= getattack();

	if (miss > roll(randomengine))
	{
		return true;
	}

	return false;

}

void Monster::attacktype ()
{

}






