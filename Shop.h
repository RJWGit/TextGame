#pragma once
#include "Player.h"
class Shop
{
public:
	Shop(string name, double markup);
	Shop();
	
	//init item

	
	//Equipment
	void additem(Items newitem);
	bool removeitem(string name, Items &_newitem);
	void initshopitem(string name, Items &newitem);

	//Pots
	void removepot(Items pot);
	void addpot(Items pot);
	//Shop
	void printshop(char input);

	//getters
	string getname() { return _name; }
	double markup() { return _markup; }

	//setters

private:
	list<Items> _items;
	list<Items>_pots;
	string _name;
	double _markup;

};

