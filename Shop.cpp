#include "Shop.h"



Shop::Shop(string name,double markup)	
{
	_markup = markup;
	_name = name;
}
Shop::Shop() {  }
void Shop::additem(Items _newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == _newitem.getname()) {
			(*lit).addone();
			return;
		}
	}

	_items.push_back(_newitem);
	_items.back().getcount();

}
void Shop::printshop(char input)
{
	list<Items>::iterator lit;
	list<Items>::iterator it;
	int count=0;


	

	
	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if (input == '1') {
			if (count == 0) {
				cout << "**Shop Weapons**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Weapon") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '2') {
			if (count == 0) {
				cout << "**Shop Shields**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Shield") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '3') {
			if (count == 0) {
				cout << "**Shop Helmets**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Helmet") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '4') {
			if (count == 0) {
				cout << "**Shop Top**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Top") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '5') {
			if (count == 0) {
				cout << "**Shop Bottoms**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Bottom") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '6') {
			if (count == 0) {
				cout << "**Shop Boots**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Boots") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}
		if (input == '7') {
			if (count == 0) {
				cout << "**Shop Gloves**\n\n";
				count++;
			}

			if ((*lit).gettype() == "Gloves") {
				cout << (*lit).getname() << " x" << (*lit).getcount() << " |Cost:" << (*lit).getvalue() << "|";
				cout << "  |Attack:" << (*lit).getattack() << "| |Defense:" << (*lit).getdefense() << "|\n\n";
			}
		}

	}

		
	
	
	
	
	
	
	for (it = _pots.begin(); it != _pots.end(); it++) {
			cout << (*it).gethppotname() << " x" << (*it).getcount() << "| Heals:" << (*it).gehppot() << "|\n";
		}

}
bool Shop::removeitem(string name, Items &_newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			_newitem = (*lit);
			if ((*lit).getcount() >= 1) {
				(*lit).removeone();
			}

			if ((*lit).getcount() == 0)
			{
				_items.erase(lit);
			}

			return true;

		}
	}
	return false;
}
void Shop::addpot(Items pot)
{
	list<Items>::iterator lit;

	for (lit = _pots.begin(); lit != _pots.end(); lit++) {
		if ((*lit).gethppotname() == pot.getname()) {
			(*lit).addone();
			return;
		}
	}

	_pots.push_back(pot);
	_pots.back().getcount();


}
void Shop::removepot(Items pot)
{
	list<Items>::iterator lit;

	for (lit = _pots.begin(); lit != _pots.end(); lit++) {

		pot = (*lit);
		if ((*lit).getcount() >= 1) {
			(*lit).removeone();
		}

		if ((*lit).getcount() == 0)
		{
			_pots.erase(lit);
		}

		return;




	}
}
void Shop::initshopitem(string name, Items &newitem)
{
	list<Items>::iterator lit;
	list<Items>::iterator it;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			newitem = (*lit);
		}

	}

	for (it = _pots.begin(); it != _pots.end(); it++) {
		if ((*it).gethppotname() == name) {
			newitem = (*it);
		}
	}
}


