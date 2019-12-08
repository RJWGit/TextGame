#include "Quest.h"
#include<iomanip>
#include<vector>


Quest::Quest()
{
}

//Game
void Quest::playgame()
{
	//Classes
	Items newitem;
	Items itemlisteasy, itemlistcommon, itemlisthard;
	Player player;

	//Shops
	Shop basicshop("Basic",.80);
	Shop commonshop("Common", .85);
	Shop advancedshop("Advanced", .90);

	//Monsters
	Monster monstereasy, monstercommon, monsterhard, monster;

	//Game loop
	bool gameloop=true;
	
	//Init Classes
	initmonsters(monstereasy, monstercommon, monsterhard);
	inititems(itemlisteasy, itemlistcommon, itemlisthard, player, basicshop,commonshop,advancedshop);

	//example
	  monstereasy.initmonster(monster);
	//Story loops
	  bool story1=true;


	while (gameloop == true) 
	{
		//Demo
		//entershop(player, basicshop, newitem);
	//	(combat(monster, player, itemlisteasy, itemlistcommon, itemlisthard));
	

		if (story1 = true) {
			//Intro Story
			story(player, "story 1");
				while (story1 == true)
				{
					char input;
					cout<<"Sorry to ask, but could you help me fix my cart? I'm heading north and the damn thing got stuck in a ditch again, think you could help me out?\n";
					cout << "Press 1 to help\n";
					cout << "Press 2 to say no\n";
					cout << "Press 3 to look around\n";
					cin >> input;

					if (input == '1')
					{
						system("cls");
						cout<<"Thank you so much kind sir, get on that side and help me push the cart out.\n";
							for (int counter = 0; counter != 5; counter++)
							{
								string input;
								cout << "Enter 'push' to push the cart\n";
								cin >> input;

								if (input == "push")
								{
									if (counter < 3) {
										cout << "The cart doesn't budge\n";
										cout << "Keep pushing the man says.\n";
										system("pause");
										system("cls");
									}

									if (counter == 3)
									{
										cout << "The cart moves a little bit\n";
										system("pause");
										system("cls");
									}
									if (counter == 4)
									{
										cout << "The cart is almost out\n";
										system("pause");
										system("cls");
									}
								}

								else
								{
									counter--;
								}
							}
							cout << "Just as the cart is about come to free you're hit over the head, you fall unconcious onto the ground.\n";
							cout << "You wake up feeling dizzy, the man is gone and he took what little gold you had on you.\n";
							cout << "You notice the cart is still there, you stumble over there and notice a small brown bag in the cart.\nYou find it has a small crystal inside and although small you can feel it's power within.\n";

							player.subtractgold(-100);
							player.takedamage(10);
							Items crystal("Strange crystal", "other", 0, 0, 0, 0, 0);
							player.additem(crystal);
							system("pause");
							system("cls");
							story1 = false;
					}
					if (input == '2')
					{
						system("cls");

						cout << "The man looks angry about it. 'Please sir it'll take just a moment of your time, i'll even pay you.'\n";
						char input;

						cout << "Press 1 to help\n";
						cout << "Press 2 to decline\n";
						cin >> input;
						if (input == '1')
						{
							system("cls");
							cout << "Thank you so much kind sir, get on that side and help me push the cart out.\n";
							for (int counter = 0; counter != 5; counter++)
							{
								string input;
								cout << "Enter 'push' to push the cart\n";
								cin >> input;

								if (input == "push")
								{
									if (counter < 3) {
										cout << "The cart doesn't budge\n";
										cout << "Keep pushing the man says.\n";
										system("pause");
										system("cls");
									}

									if (counter == 3)
									{
										cout << "The cart moves a little bit\n";
										system("pause");
										system("cls");
									}
									if (counter == 4)
									{
										cout << "The cart is almost out\n";
										system("pause");
										system("cls");
									}
								}

								else
								{
									counter--;
								}
							}
							cout << "Just as the cart is about come to free you're hit over the head, you fall unconcious onto the ground.\n";
							cout << "You wake up feeling dizzy, the man is gone and he took what little gold you had on you.\n";
							cout << "You notice the cart is still there, you stumble over there and notice a small brown bag in the cart.\nYou find it has a small crystal inside and although small you can feel it's power within.\n";


							Items crystal("Strange crystal", "other", 0, 0, 0, 0, 0);
							player.additem(crystal);
							player.subtractgold(-100);
							player.takedamage(10);
							system("pause");
							system("cls");
							story1 = false;

						}
						if (input == '2')
						{
							system("cls");
							cout << "You decline his offer and begin to walk past him. As you walk past him, he attempts to strike you with his dagger.\n";
							cout << "Your quick reflexes allow you to dodge the attack.\n";
							system("pause");

							Monster cartman("Cartman", "Easy", 30, 10, 10, 15, 0, "Highway robber");
							if ((combat(cartman, player, itemlisteasy, itemlistcommon, itemlisthard)) == true)
							{
								cout << "After defeating him you search the cart and find it to be empty except for a small bag.\nYou find a mysterious crystal inside and although small you feel the power within.\n";
								system("pause");
								system("cls");
								Items crystal("Strange crystal","other",0,0,0,0,0);
								player.additem(crystal);


								story1 = false;
							}

							else
							{
								story1 = false;
								gameloop = false;
							}
						}
					}
					if (input == '3')
					{
						system("cls");
						cout << "The man is somewhat well dressed and appears unarmed. The cart looks to be stuck in a ditch, but facing as if it was headed south, not north.\n";
						system("pause");
						system("cls");
					}
					else
					{
						system("cls");
					}
				}
			
			//Story 2
			story(player, "story 2");
		}
	
		//First town
		bool story2 = true;
		while (story2 == true)
		{
			char input;
			//Talk to saintbarch
			static bool saintbarch = false;
			
			//True to leave town
			static bool leavetown = false;

			system("cls");


			cout << "(1)Local Shop\n";
			cout << "(2)Inventory\n";
			cout << "(3)Go downtown\n";
			cout << "(4)Go see Mick\n";
			if (leavetown == true)
			{
				cout << "(5)Leave town\n";
			}
			
			cin >> input;
			system("cls");
			if (input == '1')
			{
				entershop(player, basicshop, newitem);
			}
			if (input == '2')
			{
				equipweapon(player);
			}
			if (input == '3')
			{
				bool downtown = true;
				while (downtown == true)
				{
					char input;
					system("cls");
					cout << "(1)Talk to homeless man\n";
					cout << "(2)Leave downtone\n";
					cout << "(3)Inventory\n";
					if (saintbarch == true)
					{
						cout << "(4)Go see SaintBarch\n";
					}

					cin >> input;
					system("cls");
					//Homeless guy
					if (input == '1')
					{
						bool homlessman = true;
						static bool secret = true;
						while (homlessman == true) {
							char input;
							system("cls");
							cout << "\"Could you spare some change?\"\n";

							cout << "(1)Learn about homeless man\n";
							cout << "(2)Give him gold\n";
							cout << "(3)Leave\n";

							cin >> input;
							system("cls");
							//fight him ? laugh at him?
							if (input == '1')
							{
								
							}
							//Give item if enough gold given
							if (input == '2')
							{
								int input;
								cout << "How much would you like to give him?\n";
								cin >> input;
								cin.ignore(600, '\n');
								cin.clear();
								player.subtractgold(input);
								
								if ((input <= 100) && (player.getgold()>=input) && (input>0))
								{
									cout << "\"Thank you kind sir, maybe I'll find the couch right for me now...\"\n";
									system("pause");
									system("cls");
								}

								if ((input >= 100) && (player.getgold() >= input) && (input>0))
								{
									if (secret == true)
									{
										cout << "\"This deed shall not go unrewarded, take this as a token of my gratitude kind sir.\"\n";
										player.additem(Items("Victoriums Valor", "Weapon", 500, 50, 0, 10, 1));
										cout << "You got the item \"Victoriums Valor\"!\n";
										system("pause");
										secret = false;
									}

									else {
										cout << "\"Thank you kind sir, maybe I'll find the couch right for me...\"\n";
										system("pause");
										system("cls");
									}
								}
								
								else if(player.getgold()<input)
								{
									cout << "You don't have enough gold\n";
									system("pause");
									system("cls");
								}
							}
							if (input == '3')
							{
								homlessman = false;
							}
						}
					}

					//Leave downtown
					if (input == '2')
					{
						downtown = false;
					}
					
					//Inventory
					if (input == '3')
					{
						equipweapon(player);
					}

					//Saint Barch
					if (input == '4')
					{
						if (saintbarch == true)
						{
							bool talk = true;
							while (talk == true) {
								char input;
								system("cls");

								cout << "\"Welcome child, how may I serve you today?\"\n";

								cout << "(1)Tell him Mick sent you\n";
								cout << "(2)Learn about Saint Barch\n";
								cout << "(3)Leave\n";
								cin >> input;
								system("cls");
								if (input == '1')
								{
									cout << "\"Oh? Mick thinks I can help you, well lets see this crystal you posses.\"\n";
									cout << "\"I don't think i've seen anything quite like this. It contains great a great unholy power. I need to do some more research, wait right there.\"\n";
									system("pause");
									system("cls");
									cout << "\SaintBarch returns\n \"This is, from what I can tell, one of the three crystals lost during the destruction of the three kingdoms.\"\n";
									system("pause");

									leavetown = true;

								}
								if (input == '2')
								{
									cout << "More story\n";

								}
								if (input == '3')
								{
									talk = false;
								}
							}
						}
					}
				}
			}
			if (input == '4')
			{	
				if (leavetown == false) {
					//First visit with Mick
					static bool firstmick = true;
					if (firstmick == true) {
						while (firstmick == true)
						{
							static bool deliver = false;
							char input;
							cout << "\"How you been " << player.getname() << ", long time no see!\"\n";
							cout << "\"What can I do for you today?\"\n\n";

							cout << "(1)Deliver Item\n";
							cout << "(2)Ask about \"Strange crystal\"\n";
							cout << "(3)Learn more about Mick\n";
							if (saintbarch == true) {

								cout << "(4)Leave\n";
							}
							cin >> input;

							system("cls");

							if (input == '1')
							{
								if (deliver == false) {
									cout << "\"Ah, so you're here to deliver me somthing. Didn't take you as delivery boy, lets see what we have here...\"\n";
									cout << "\"Yes! My delivery of \"Vosco Pizza\" finally got here, thanks " << player.getname() << ".\"\n";
									cout << "\"Here is half of what I owe you, get the rest to you later.\"\n";
									cout << "You got 50gp!\n";
									player.addgold(50);
									system("pause");
									system("cls");
									deliver = true;
								}

								else
								{
									cout << "You already delivered Mick his Vosco pizza.\n";
									system("pause");
									system("cls");
								}
							}
							if (input == '2')
							{
								cout << "You show mick the strange crystal...\n";
								cout << "\"I've never seen anything like it, I know someone who might know something about it.\"\n";
								cout << "\"He lives in the downtown area, he's a priest, his name is \"Saint Barch\". Tell him I sent you.\"\n";
								system("pause");
								system("cls");
								saintbarch = true;
							}
							if (input == '3')
							{
								sleep("Mick is a young man living in the town of X, he is often mistaken as being much older due to his unruly beard\nand his receding hair line. Recenetly promoted to assistant peasant of a local business named \"Vosco\".\n#");
								system("pause");
								system("cls");
							}
							if (input == '4'&& saintbarch == true)
							{
								firstmick = false;

							}
						}
					}

					else
					{
						bool visit = true;
						while (firstmick == false&&visit==true)
						{
							system("cls");
							char input;
							cout << "\"Did you talk to Saint Barch yet?\"\n\n";

							cout << "(1)Ask about owed money\n";
							cout << "(2)Learn more about Mick\n";
							cout << "(3)Leave\n";
							cin >> input;
							system("cls");

							if (input == '1')
							{
								cout << "He promises to get you the money soon\n";
								system("pause");
							}
							if (input == '2')
							{
								sleep("Mick is a young man living in the town of X, he is often mistaken as being much older due to his unruly beard\nand his receding hair line. Recenetly promoted to assistant peasant of a local business named \"Vosco\".\n#");
								system("pause");
							}

							if (input == '3')
							{
								visit = false;
							}

						}
					}
				}

				if(leavetown==true)
				{
					
					bool visit=true;
					while (visit == true)
					{
						system("cls");

						char input;
						cout << "\"Hey, what can I do for you \"" << player.getname() <<"?\""<< endl;
						cout << "(1)Ask about money owed to you\n";
						cout << "(2)Learn more about Mick\n";
						cout << "(3)Leave\n";

						cin >> input;
						system("cls");

						if (input == '1')
						{
							static bool money = true;
								if (money == true) {
									cout << "Sorry about that, have the rest right here\n";
									cout << "You got 50gp!\n";
									player.addgold(50);
									system("pause");
										money = false;
								}
								else
								{
									cout << "\"I already paid you!\"\n";
									system("pause");
								}
						}

						if (input == '2')
						{
							sleep("Mick is a young man living in the town of X, he is often mistaken as being much older due to his unruly beard\nand his receding hair line. Recenetly promoted to assistant peasant of a local business named \"Vosco\".\n#");
							system("pause");
						}

						if (input == '3')
						{
							visit = false;
						}
					}
				}
			}
			if (input == '5' && leavetown == true)
			{
				story2 = false;
			}
		}

	}
	if (gameloop == false) {
		sleep("This is where our journey comes to an end, try again if you're brave enough to...\n#");
		system("pause");
	}

}




void Quest :: inititems(Items &itemslisteasy, Items &itemslistcommon, Items &itemslisthard, Player &player, Shop &basicshop,Shop &commonshop,Shop &advancedshop)
{

	//Items Easy

	//Value,Attack,Defense
		//Bronze set
	itemslisteasy.additem(Items("Bronze Boots", "Boots", 50, 0, 10, 10, 1));
	itemslisteasy.additem(Items("Bronze Gloves", "Gloves", 50, 0, 10, 10, 2));
	itemslisteasy.additem(Items("Bronze Helmet", "Helmet", 60,0, 15, 10, 3));
	itemslisteasy.additem(Items("Bronze Sword", "Weapon", 70, 15, 0, 10, 4));
	itemslisteasy.additem(Items("Bronze Top", "Top", 10, 70, 100, 20, 5));
	itemslisteasy.additem(Items("Bronze Bottoms", "Bottom", 70, 10, 20, 10,6));
	itemslisteasy.additem(Items("Bronze Shield", "Shield", 60, 10, 20, 10, 7));

		//Wood set
	itemslisteasy.additem(Items("Wood Sword", "Weapon", 30, 8, 0, 10, 8));
	itemslisteasy.additem(Items("Wood Boots", "Boots", 30, 0, 5, 10, 9));
	itemslisteasy.additem(Items("Wood Gloves", "Gloves", 30, 0, 5, 10, 10));
	itemslisteasy.additem(Items("Wood Top", "Top", 40, 0, 15, 5,11));
	itemslisteasy.additem(Items("Wood Bottoms", "Bottom", 40, 0, 15, 10, 12));
	itemslisteasy.additem(Items("Wood Helmet", "Helmet", 40, 0, 15, 10, 13));
	itemslisteasy.additem(Items("Wood Shield", "Shield", 40, 0, 15, 10, 14));



	
	

	//Items Common


	//Items Hard
	itemslisthard.additem(Items("Victoriums Valor", "Weapon", 500, 50, 0, 10, 1));

	//Items pot
	itemslisteasy.addpot(Items("Small Healing Pot", 10, 1, 1));
	itemslistcommon.addpot(Items("Medium Healing Pot", 10, 1,1));
	itemslisthard.addpot(Items("Large Healing Pot", 10, 1, 1));


	//Player
	player.additem(Items("G", "Weapon", 200, 250, 0, 1, 1));

	//Basic Shop	
	
	basicshop.additem(Items("Wood Sword", "Weapon", 30, 8, 0, 10, 8));
	basicshop.additem(Items("Wood Boots", "Boots", 30, 0, 5, 10, 9));
	basicshop.additem(Items("Wood Gloves", "Gloves", 30, 0, 5, 10, 10));
	basicshop.additem(Items("Wood Top", "Top", 40, 0, 15, 5, 11));
	basicshop.additem(Items("Wood Bottoms", "Bottom", 40, 0, 15, 10, 12));
	basicshop.additem(Items("Wood Helmet", "Helmet", 40, 0, 15, 10, 13));
	basicshop.additem(Items("Wood Shield", "Shield", 40, 0, 15, 10, 14));







}
void Quest :: equipweapon(Player &player)
{
	bool loop = true;
	while (loop == true) {
		string name;
		player.printinventory();
		cout << "Enter what you'd like to equip or use.\n";
		cout << "Enter Q to quit\n\n";
		cout << "Current HP:" << player.gethp() << endl;

		getline(cin, name);
		player.hppot(name);
		player.equipweapon(name);
		player.equipboots(name);
		player.equipgloves(name);
		player.equiptop(name);
		player.equipbottom(name);
		player.equipshield(name);
		player.equiphelmet(name);
		if (name == "Q" || name == "q")
		{
			loop = false;
		}

		system("cls");
	}

}
void Quest :: entershop(Player &player, Shop &shop, Items &newitem)
{
	bool loop = true;
	char input;
	while (loop == true) {
		system("cls");
		cout << "***Welcome to " << shop.getname() << " shop!***\n\n";
		cout << "What can I do for you today?\n\n";

		cout << "Press B to buy\n";
		cout << "Press S to sell\n";
		cout << "Press Q to leave shop\n";
		cout << "Press I to learn about prices\n\n";		
		cin >> input;
		

		if (input == 'B' || input == 'b')
		{
			char choice='0';
			string name;
			
			//View Items
			while (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5'&&choice != '6'&&choice != '7'&&choice!='q'&&choice != 'Q') {
				system("cls");
				cout << "What would you like to buy?\n\n";
				cout << "Press 1 to view our weapons\n";
				cout << "Press 2 to view our shields\n";
				cout << "Press 3 to view our helmets\n";
				cout << "Press 4 to view our tops\n";
				cout << "Press 5 to view our bottoms\n";
				cout << "Press 6 to view our boots\n";
				cout << "Press 7 to view our gloves\n\n";
				cout << "Press Q to go back\n";
				
				cin >> choice;
			}
			
			//Buy
			if (choice != 'q') {
				if (choice != 'Q') {
					system("cls");
					shop.printshop(choice);
					player.printinventory();
					cout << "What would you like to buy?\n";
					cout << "Press Q to go back\n";
					cin.ignore();
					getline(cin, name);

					shop.initshopitem(name, newitem);
					if (player.afforditem(name, newitem))
					{
						shop.removeitem(name, newitem);
						player.subtractgold(newitem.getvalue());
						player.additem(newitem);

					}

					if (player.affordpot(name, newitem))
					{
						shop.removepot(newitem);
						player.subtractgold(newitem.getvalue());
						player.addpot(newitem);

					}
				}
			}
		}
		if (input == 'S' || input == 's')
		{
			string name;

			system("cls");
			player.printinventory();
			cout << "What would you like to sell?\n";
			cout << "Press Q to go back\n";
			cin.ignore();
			getline(cin, name);
			if (player.removeitem(name, newitem)) {
				shop.additem(newitem);
				player.addgold((newitem.getvalue()*shop.markup()));
			}


		}
		if (input == 'Q' || input == 'q') {
			system("cls");

			loop = false;
		}
		if (input == 'I' || input == 'i')
		{
			cout << "\nWe buy items back for 80% of our sell price\n\n";
			system("pause");
		}
	}
}
void Quest :: initmonsters(Monster &monstereasy, Monster &monstercommon, Monster &monsterhard)
{
	monsterhard.addmonster(Monster("Dragon", "Hard", 100, 10, 100, 1000, 1, "A Giant dragon."));
	monstercommon.addmonster(Monster("Wolf", "Common", 100, 10, 100, 1000, 1, "A big wolf"));
	monstereasy.addmonster(Monster("Dog", "Easy", 100, 10, 100, 1000,1, "A small dog"));
}
bool Quest :: combat(Monster monster, Player &player, Items itemslisteasy, Items itemslistcommon, Items itemslisthard)
{
	Items newitem;
	Items newpot;
	bool loop = true;

	mt19937 randomengine(time(0));
	uniform_int_distribution<int> roll(0, 100);


	while (loop == true) {

		system("cls");

		int input;

		cout << "(1)Attack\n";
		cout << "(2)Inventory\n";
		cout << "(3)Stats\n";
		cout << "(4)Description\n\n";
		cout << player.getname() << " HP:" << player.gethp() << "\n\n";
		cout << monster.getname() << "HP: " << monster.gethp() << endl;
		cin >> input;
		cin.clear();
		cin.ignore(9000, '\n');

		if (input == 1)
		{
			system("cls");
			
			//Player attack
			if (player.miss(monster.getdefense()) == false)
			{
				int damagetaken;
				damagetaken = monster.gethp();

				cout << player.getname() << " attacks " << monster.getname() << "!\n";
				monster.takedamage(player.getattack());

				cout << monster.getname() << " was hit for " << damagetaken - monster.gethp() << " damage.\n\n";

				if (monster.gethp() < monster.getmaxhp() / 4 && monster.gethp()>=0 )
				{
					cout << "The " << monster.getname() << " is in critical condintion\n";
				}

				system("pause");

				//Monster dies
				if (monster.gethp() <= 0)
				{

					system("cls");
					cout << "***The " << monster.getname() << " has been slain!***\n\n";
				
					//Easy drop
				
					if (monster.getdifficulty() == "Easy")
					{
						itemslisteasy.itemdrop(newitem);
						player.additem(newitem);
					
						//Potion drop
						if (roll(randomengine) > 50) {


							itemslisteasy.potdrop(newpot);
							player.addpot(newpot);
							cout << "You got a '" << newpot.gethppotname() << "'!\n";

						}
					}

					//Common Drop

					if (monster.getdifficulty() == "Common")
					{
						itemslisteasy.itemdrop(newitem);
						player.additem(newitem);

						//Potion drop
						if (roll(randomengine) > 50) {


							itemslistcommon.potdrop(newpot);
							player.addpot(newpot);
							cout << "You got a '" << newpot.gethppotname() << "'!\n";

						}
					}

					//Hard Drop
					if (monster.getdifficulty() == "Hard")
					{
						itemslisthard.itemdrop(newitem);
						player.additem(newitem);

						//Potion drop
						if (roll(randomengine) > 50) {


							itemslisthard.potdrop(newpot);
							player.addpot(newpot);
							cout << "You got a '" << newpot.gethppotname() << "'!\n";

						}
					}

			
					//Gold
					player.addgold(monster.getgold());

					cout << "You got the item '" << newitem.getname() << "'!\n";
					cout <<monster.getname() <<" dropped " << monster.getgold() << " gold!\n";

				
					system("pause");
					system("cls");

					return true;
				}

			}
			//Player miss
			else
			{
				cout << player.getname() << " attack failed.\n\n ";
				system("pause");
			}

			system("cls");

			//Monster attack
			if (monster.miss(player.getdefense()) == false)
			{
				int damagetaken;
				damagetaken = player.gethp();

				player.takedamage(monster.getattack());
				cout << monster.getname() << " attacks " << player.getname() << "!\n";
				cout << player.getname() << " was hit for " << damagetaken - player.gethp() << " damage.\n\n";
				system("pause");

				//Player dies
				if (player.gethp() <= 0)
				{
					system("cls");

					return false;
				}

			}

			//Monster miss
			else
			{
				cout << monster.getname() << " attack failed!\n\n";
				system("pause");

			}

		}
		else if (input == 2) {
			system("cls");
			equipweapon(player);
		}
		else if (input == 3)
		{
			player.getstats();
		}
		else if (input == 4)
		{
			system("cls");
			cout << monster.getdescription() << "\n\n";
			system("pause");
		}
		input = 0;
	}
}
void Quest :: sleep(char x[])
{



	for (int i = 0; x[i] != '#'; i++)
	{
		cout << x[i];
		Sleep(50);
	}
}
void Quest :: garbage(string name)
{
	
}
void Quest :: display(Player &player,Shop &shop, Items newitem)
{
	//Display
	char input;
	cout << "Press 1 for inventory\n";
	cout << "Press 2 to go to the shop\n";
	cout << "Press 3 to go to X\n";
	cin >> input;

	if (input == 1)
	{
		equipweapon(player);
	}
	if (input == 2)
	{
		entershop(player, shop, newitem);
	}



	else
	{
		cout << "Invalid\n";
	}
}
void Quest :: story(Player &player, string storypicker)
{
	string name;


	//Story 1
	if (storypicker == "story 1") {

		//Player name
		sleep("Welcome to Xanthia, the tale of three crystlas!\n#"); 
		sleep("What will you be known as?\n#");
		getline(cin, name);
		player.playerinit(name);

		sleep("From this day forth you shall be known as #");
		cout << player.getname();
		sleep("!\nLets begin...\n#");
		system("pause");
		system("cls");

		//Open story
		sleep("Long ago, Xanthia was ruled by three powerful kingdoms. All in the pursuit of great magical power.\n#");
		sleep("Together they crafted three magical crystals, one in each kingdoms image. These crystals contained \n#");
		sleep("ungodly power, the people rejoiced as the crystals brought happiness to the people. The means used \n#");
		sleep("to make the crystals was believed to be convential magic, the truth was much darker and came at a \n#");
		sleep("terrible price. Most of what happened after was lost and forgotten, from what is known is \n#");
		sleep("all three of the kingdoms were destroyed and all that remains today are ruins, as for the crystals \n#");
		sleep("they are believed to be no more than rumors... until today... this is where your journey beings.\n#");
		system("pause");
		system("cls");
		sleep("You're currently on a delivery job and on your way to the town you're approached by a man asking for help...\n#");
		system("pause");
		system("cls");

		
			//Player background
			/*sleep("Important things to know about you:\n#");
		
			vector<string> msg = { "You lost a fight to a gerbil as a young child","People tend to avoid you"};
			

			for (int count = 0; count < 5; count++) {
				mt19937 randomengine(time(0));
				uniform_int_distribution<int> roll(0, msg.size() - 1);
				int rng = roll(randomengine);

				cout << msg[rng];
				msg.erase(msg.begin() + rng);
				system("pause");

				
			}*/
		
		

			return;
		
	}
	if (storypicker == "story 2")
	{
		
		sleep("After the ordeal with the \"Cartman\", you arrive at the town of X.\nNow you need to find a man named \"Mick\", to finish the delivery.\n#");
		system("pause");
		system("cls");
	}
}