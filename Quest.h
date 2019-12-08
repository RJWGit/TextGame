#pragma once
#include "Player.h"
#include <Windows.h>
class Quest
{
public:
	Quest();

	void playgame();


	void inititems(Items &itemslisteasy, Items &itemslistcommon, Items &itemslisthard, Player &player, Shop &basicshop, Shop &commonshop, Shop &advancedshop);
	void equipweapon(Player &player);
	void entershop(Player &player, Shop &shop, Items &newitem);
	void initmonsters(Monster &monstereasy, Monster &monstercommon, Monster &monsterhard);
	void sleep(char x[]);
	bool combat(Monster monster, Player &player, Items itemslisteasy, Items itemslistcommon, Items itemslisthard);
	void garbage(string name);
	void story(Player &player, string story);
	void display(Player &player, Shop &shop, Items newitem);



private:


};

