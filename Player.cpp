#include "Player.h"



Player::Player()
{
}

//Init player
void Player::playerinit(string name)
{
	_gold = 100;
	_name = name;
	_hp = _maxhp;
	_attack = 5;
	_defense = 10;
}

//Attacks
bool Player::miss(int defense)
{
	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(1, 500);

	int miss;

	miss = (defense/5) ;
	miss -= getattack();
	if (miss > roll(randomengine))
	{
		return true;
	}

	return false;

}

//Hp
int Player::hppot(string name)
{
	Items hppot;
	list<Items>::iterator lit;

	for (lit = _hplist.begin(); lit != _hplist.end(); lit++) {
		if ((*lit).gethppotname() == name) {
			_hp += (*lit).gehppot();
		
				if ((*lit).getcount() >= 1) {
					(*lit).removeone();
				}

				if ((*lit).getcount() == 0)
				{
					_hplist.erase(lit);
				}
				
				if (_hp >= 100) {
					cout << "Your current hp is now 100\n";
					system("pause");
					return _hp;
				}

				if (_hp < 100)
				{
					cout << "Your current hp is now " << _hp << ".\n";
					system("pause");
					return _hp;
				}

		}
	} 
	return _hp;
}
void Player::addpot(Items &pot)
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
void Player::removepot(Items &pot)
{
	list<Items>::iterator lit;

	for (lit = _hplist.begin(); lit != _hplist.end(); lit++) {

		if (pot.gethppotname() == (*lit).gethppotname()) {
			if ((*lit).getcount() >= 1) {
				(*lit).removeone();
			}

			if ((*lit).getcount() == 0)
			{
				_hplist.erase(lit);
			}
		}
		

		
	}
}
void Player::takedamage(int damage)
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

//Items
void Player::addnewitem(string name, Items &_newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			_newitem = (*lit);
			return;
		}
	}
	_items.push_back(_newitem);
	_items.back().setcount(1);

}
bool Player::removeitem(string name, Items &_newitem)
{
	list<Items>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			_newitem = (*lit);
			if ((*lit).getcount() >= 1) {
				(*lit).removeone();
			}

			if((*lit).getcount()==0)
			{
				_items.erase(lit);
			}

			return true;
			
		}
	}
	return false;
}
void Player::additem(Items &_newitem)
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
void Player::unequipitem(string name)
{
	Items noweapon("No weapon equiped");
	Items nohelmet("No helmet equiped");
	Items noboots("No boots equiped");
	Items nogloves("No gloves equiped");
	Items notop("No top equiped");
	Items nobottom("No bottom equiped");	
	Items noshield("No shield equiped");


	//Weapon
	if (name == _weapon.getname())
	{
		_attack -= _weapon.getattack();
		additem(_weapon);
		_weapon = noweapon;
		return;
	}

	//Helmet
	if (name == _helmet.getname())
	{
		_defense -= _helmet.getdefense();
		additem(_helmet);
		_helmet = nohelmet;
		return;
	}


	//Boots
	if (name == _boots.getname())
	{
		_defense -= _boots.getdefense();
		additem(_boots);
		_boots = noboots;
		return;
	}

	//Gloves
	if (name == _gloves.getname())
	{
		_defense -= _gloves.getdefense();
		additem(_gloves);
		_gloves = nogloves;
		return;
	}

	//Top
	if (name == _top.getname())
	{
		_defense -= _top.getdefense();
		additem(_top);
		_top = notop;
		return;
	}

	//Bottom
	if (name == _bottom.getname())
	{
		_defense -= _bottom.getdefense();
		additem(_bottom);
		_bottom = nobottom;
		return;
	}

	//Shield
	if (name == _shield.getname())
	{
		_defense -= _shield.getdefense();
		additem(_shield);
		_shield = noshield;
		return;
	}




}

//Shopping 
bool Player::affordpot(string name, Items newitem)
{
	if (name == newitem.gethppotname()) {
		if (_gold >= newitem.getvalue())
		{
			return true;
		}

		else {
			cout << "You can't afford that.\n";
			return false;
		}
	}
	
	return false;

}
bool Player::afforditem(string name, Items newitem)
{
	if (name == newitem.getname()) {
		if (_gold >= newitem.getvalue())
		{
			return true;
		}

		else {
			cout << "You can't afford that.\n";
			return false;
		}
	}
	
	return false;

}

//Inventory
void Player::printinventory()
{
	list<Items>::iterator lit;
	list<Items>::iterator it;
	cout <<"***"<<_name<< " Inventory***\n\n";
	cout << "Gold: " << _gold <<"\n\n";
	cout << "**Items** \n";
	for (lit = _items.begin(); lit != _items.end(); lit++) {
		
		//Items
		if ((*lit).getattack() == 0 && (*lit).getdefense() == 0)
		{
			cout <<"\""<< (*lit).getname()<<"\""<<endl;
		}
		//Weapons/Armour
		else {
			cout <<"\""<< (*lit).getname() << "\"x" << (*lit).getcount() << " |Attack: " << (*lit).getattack() << "| |Defense: " << (*lit).getdefense() << "|" << " |Value: " << (*lit).getvalue() << "|\n\n";
		}
	}


	//Potions
	//iterator is "it"!!!
	cout << "\n**Potions**\n\n";
	for (it = _hplist.begin(); it != _hplist.end(); it++) {
		cout <<"\""<< (*it).gethppotname() << "\"x"<<(*it).getcount()<<" |Heals:" << (*it).gehppot() << "|\n\n";
	}
	 

}
void Player::getstats()
{
	system("cls");
	cout << "**Player Stats**\n\n";
	cout << "Player HP: " << _hp << "/" << _maxhp << endl;
	cout << "Player Attack: " << _attack << endl;
	cout << "Player Defense: " << _defense << endl<<endl ;
	system("pause");
}
int Player::addgold(int gold) {
	_gold += gold;
	return _gold;
}
int Player::subtractgold(int gold) {
	_gold -= gold;
	return _gold;
}

//Weapon functions
int Player::equipweapon(string name)
{
	list<Items>::iterator lit;
	Items baditem;
	


	for (lit = _items.begin(); lit != _items.end(); lit++) { 
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Weapon")
			{
				//Reset attack
				_attack -= _weapon.getattack();

				//Give equiped item back to player
				if (_weapon.getname()!=baditem.getname()) {
					additem(_weapon);
				}


				//Equip new weapon
				_weapon = (*lit);

				//Attack with new weapon
				_attack += (*lit).getattack();

				cout << "You equip the " << (*lit).getname() << " weapon\n";
				cout << "You're attack is " << _attack << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _attack;
			}
			
		}
	}
	return _attack;
}
void Player::getequipedweapon()
{
	cout << "Attack: " << _weapon.getattack() << " Value:" << _weapon.getvalue() << endl;
}

//Gloves Functions
int Player::equipgloves(string name)
{
	list<Items>::iterator lit;
	Items baditem;
	



	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Gloves")
			{
				//Reset defense
				_defense -= _gloves.getdefense();

				//Give equiped item back to player
				if (_gloves.getname() != baditem.getname()) {
					additem(_gloves);
				}


				//Equip new gloves
				_gloves = (*lit);

				//New Defense stat
				_defense+= (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense <<" !"<< endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}
			else {
			}
		}
	}
	return _defense;
}
void Player::getequipedgloves()
{
	cout << "Defense: " << _gloves.getdefense() << " Value:" << _gloves.getvalue() << endl;
}

//Helmet Functions
int Player::equiphelmet(string name)
{
	list<Items>::iterator lit;
	Items baditem;
	


	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Helmet")
			{
				//Reset defense
				_defense -= _helmet.getdefense();

				//Give equiped item back to player
				if (_helmet.getname() != baditem.getname()) {
					additem(_helmet);
				}


				//Equip new helmet
				_helmet = (*lit);

				//New Defense stat
				_defense += (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense << " !" << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}
			else {
			}
		}
	}
	return _defense;
}
void Player::getequipedhelmet()
{
	cout << "Defense: " << _helmet.getdefense() << " Value:" << _helmet.getvalue() << endl;
}

//Boots
int Player::equipboots(string name)
{
	list<Items>::iterator lit;
	Items baditem;



	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Boots")
			{
				//Reset defense
				_defense -= _boots.getdefense();

				//Give equiped item back to player
				if (_boots.getname() != baditem.getname()) {
					additem(_boots);
				}


				//Equip new helmet
				_boots = (*lit);

				//New Defense stat
				_defense += (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense << " !" << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}
			
		}
	}
	return _defense;
}
void Player::getequipedboots()
{
	cout << "Defense: " << _boots.getdefense() << " Value:" << _boots.getvalue() << endl;
}

//Bottom
int Player::equipbottom(string name)
{
	list<Items>::iterator lit;
	Items baditem;



	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Bottom")
			{
				//Reset defense
				_defense -= _bottom.getdefense();

				//Give equiped item back to player
				if (_bottom.getname() != baditem.getname()) {
					additem(_bottom);
				}


				//Equip new helmet
				_bottom = (*lit);

				//New Defense stat
				_defense += (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense << " !" << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}

		}
	}
	return _defense;
}
void Player::getequipedbottom()
{
	cout << "Defense: " << _bottom.getdefense() << " Value:" << _bottom.getvalue() << endl;
}

//Top
int Player::equiptop(string name)
{
	list<Items>::iterator lit;
	Items baditem;



	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Top")
			{
				//Reset defense
				_defense -= _top.getdefense();

				//Give equiped item back to player
				if (_top.getname() != baditem.getname()) {
					additem(_top);
				}


				//Equip new helmet
				_top = (*lit);

				//New Defense stat
				_defense += (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense << " !" << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}

		}
	}
	return _defense;
}
void Player::getequipedtop()
{
	cout << "Defense: " << _top.getdefense() << " Value:" << _top.getvalue() << endl;
}

//Shield
int Player::equipshield(string name)
{
	list<Items>::iterator lit;
	Items baditem;


	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getname() == name) {
			if ((*lit).gettype() == "Shield")
			{
				//Reset defense
				_defense -= _shield.getdefense();

				//Give equiped item back to player
				if (_shield.getname() != baditem.getname()) {
					additem(_shield);
				}


				//Equip new helmet
				_shield = (*lit);

				//New Defense stat
				_defense += (*lit).getdefense();

				cout << "You equip " << (*lit).getname() << "\n";
				cout << "You're defense is now " << _defense << " !" << endl;
				system("pause");


				//Remove current item
				(*lit).removeone();

				//Take last item away
				if ((*lit).getcount() == 0)
				{
					_items.erase(lit);
				}


				return _defense;
			}

		}
	}
	return _defense;
}
void Player::getequipedshield()
{
	cout << "Defense: " << _shield.getdefense() << " Value:" << _shield.getvalue() << endl;
}