#pragma once
#include <iostream>
#include <string>	
#include <list>
#include "Items.h"
#include <cstdlib>
#include"Shop.h"
#include"Monster.h"
using namespace std;
class Player
{
public:
	Player();

	//init player
	void playerinit(string name);
	string getname() { return _name; }

	//Attacks
	bool miss(int defense);


	//HP
	void maxhp() { _hp = _maxhp; }
	void takedamage(int damage);
	void removepot(Items &pot);
	void addpot(Items &pot);
	int hppot(string name);

	//Getter
	int gethp() { if (_hp > _maxhp) { _hp = _maxhp; }return _hp; }
	void getstats();

	//Shop
	bool afforditem(string name, Items newitem);
	bool affordpot(string name, Items newitem);

	//Items
	void addnewitem(string name, Items &_newitem);
	void additem(Items &_newitem);
	bool removeitem(string name, Items &_newitem);
	int getgold() { return _gold; }
		void printinventory();
		int addgold(int gold);
		int subtractgold(int gold);
		void unequipitem(string name);

	//Stats
		//Weapon
		int equipweapon(string name);
		void getequipedweapon();
		//Gloves
		int equipgloves(string name);
		void getequipedgloves();
		//Helmet
		int equiphelmet(string name);
		void getequipedhelmet();
		//Boots
		int equipboots(string name);
		void getequipedboots();
		//Bottom
		int equipbottom(string name);
		void getequipedbottom();
		//Top
		int equiptop(string name);
		void getequipedtop();
		//Shield
		int equipshield(string name);
		void getequipedshield();

	
	//Getter
	int getattack() { return _attack; }
	int getdefense() { return _defense; }

		//Setter
			

private:
	int _hp;
	int _maxhp=100;
	int _attack;
	int _defense;
	int _gold;
	int _count;
	string _name;
	list<Items> _items;
	list<Items>_hplist;
	
	//currently equiped
	Items _weapon;
	Items _helmet;
	Items _boots;
	Items _gloves;
	Items _top;
	Items _bottom;
	Items _shield;
};

