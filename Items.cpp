#include "Items.h"



Items::Items(string name,string type, int value, int attack, int defense, int count, int chance1)
{
	_type = type;
	_chance1 = chance1;
	_name = name;
	_count = count;
	_attack = attack;
	_defense = defense;
	_value = value;
}
Items::Items(string name, int hp, int count,int chance1)
{	
	_chance1 = chance1;
	_hppotname = name;
	_hppot = hp;
	_count = count;
}
Items::Items(string name){}
Items::Items()
{};
void Items::addone()
{
	_count++;
}
void Items::removeone()
{
	if (_count > 0) {
		_count--;
	}
}
void Items::additem(Items &_newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == _newitem.getname()) {
			(*lit).addone();
			return;
		}
	}

	_items.push_back(_newitem);
	_items.back().setcount(1);

}
bool Items::copyitem(string name, Items &_newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			_newitem = (*lit);
			return true;
		}
	}
	return false;
}
void Items::itemdrop(Items &_newitem)
{
	list<Items>::iterator lit;
	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(1, _items.size());
	
	int rng = roll(randomengine);
	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getchance1() == rng) {
			_newitem = (*lit);

			return;
		}
	}
	return;
	}
void Items::potdrop(Items &pot)
{

	list<Items>::iterator lit;
	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(1, _hplist.size());

	int rng = roll(randomengine);
	for (lit = _hplist.begin(); lit != _hplist.end(); lit++) {
		if (((*lit).getchance1() == rng)) {
			pot = (*lit);
			return;
		}


	}
}
void Items::addpot(Items &pot)
{
	list<Items>::iterator lit;

	for (lit = _hplist.begin(); lit != _hplist.end(); lit++) {
		if ((*lit).gethppotname() == pot.gethppotname()) {
			(*lit).addone();
			return;
		}
	}

	_hplist.push_back(pot);
	_hplist.back().setcount(1);


}



