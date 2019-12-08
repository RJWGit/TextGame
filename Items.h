#pragma once
#include <string>
#include<list>
#include<iostream>
#include<random>
#include<ctime>
using namespace std;
class Items
{
public:
	Items (string name,string type,int value,int attack,int defense,int count,int chance1);
	Items(string name, int hp, int count,int chance1);
	Items(string name);
	Items();
	void additem(Items &_newitem);
	bool copyitem(string name,Items &_newitem);
	void addone();
	void removeone();
	void itemdrop(Items &_newitem);
	void potdrop(Items &pot);
	void addpot(Items &pot);
	//Getter
	string getname() { return _name; }
	string gettype() { return _type; } 
	string gethppotname() { return _hppotname; }
	int gehppot() { return _hppot; }
	int getvalue() { return _value; }
	int getattack() { return _attack; }
	int getdefense() { return _defense; }
	int getcount() { return _count; }
	int getchance1() { return _chance1; }


	//Setter
	void setcount(int count) { _count = count; }
private:
	string _name;
	string _type;
	string _trash;
	string _hppotname;
	int _hppot;
	int _chance1;
	int _value;
	int _attack;
	int _defense;
	int _count;
	list<Items> _items;
	list<Items> _hplist;
};

