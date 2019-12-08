#pragma once
#include "Player.h"
#include"Monster.h"
using namespace std;
class Monster
{
public:
	Monster(string name,string type, int hp, int attack, int defense, int gold, int chance, string description);
	Monster();

	//Damage;
	int getspecialattack();
	void takedamage(int damage);
	//Add monsters
	void addmonster(Monster &newmonster);

	//Init monsters
	void initmonster(Monster &newmonster);


	//Text monster
	void attacktype();
	bool miss(int defense);


		



	//Getters
	string getname() { return _name; }
	string getdifficulty() { return _type; }
	string getdescription() { return _description; }
	int getmaxhp() { return _maxhp; }
	int getchance1() { return _chance; }
	int getgold() { return _gold; }
	int gethp() { return _hp; }
	int getattack() { return _attack; }
	int getdefense() { return _defense; }
	

private:
	string _name;
	string _type;
	string _description;
	int _gold;
	int _hp;
	int _maxhp;
	int _attack;
	int _defense;
	int _chance;
	list<Monster> _monsters;
	
	



};