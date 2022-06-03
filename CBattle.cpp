#include "CBattle.h"
#include <string>

CBattle::CBattle(): BotDec(0), MapDec(0) {}
void CBattle::RunGame() {
	RenderWindow window(sf::VideoMode(1280, 720), "C Battle");
	while (true)
	{
		GameMenu(window);
		GameBody(window);
	}
}
void CBattle::GameMenu(RenderWindow& window) {
	Texture Menutext;
	Menutext.loadFromFile("img/WPA.png");
	Sprite border, menu1, menu2, menu3, menu4;
	border.setTexture(Menutext);
	menu1.setTexture(Menutext);
	menu2.setTexture(Menutext);
	menu3.setTexture(Menutext);
	menu4.setTexture(Menutext);
	border.setTextureRect(IntRect(449, 640, 94, 95));	
	border.setScale(6, 6);
	border.setPosition(358, 40);
	menu1.setTextureRect(IntRect(417, 1056, 94, 32));
	menu2.setTextureRect(IntRect(417, 1056, 94, 32));
	menu3.setTextureRect(IntRect(417, 1056, 94, 32));
	menu4.setTextureRect(IntRect(417, 1056, 94, 32));
	menu1.setScale(3, 3);
	menu2.setScale(3, 3);
	menu3.setScale(3, 3);
	menu4.setScale(3, 3);
	//menu1.setPosition(499, 100);

	Font mfont;//шрифт 
	mfont.loadFromFile("img/NB.ttf");
	Text tname("", mfont, 30);
	tname.setStyle(sf::Text::Bold);	
	
	int stage = 0;
	int select = 0;
	int showMenu = 1;
	Clock clock; 
	float pauseTimer = 2020;

	while (window.isOpen())
	{
		float timer = clock.getElapsedTime().asMicroseconds(); 
		clock.restart(); 
		timer = timer / 800; 
		pauseTimer += timer;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (pauseTimer > 3000) {
			switch (stage) {
			case 0:
				showMenu = 1;
				select = 0;
				//showMenu = true;				
				if (IntRect(499, 170, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); select = 1; }
				if (IntRect(499, 320, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); select = 2; }
				if (Mouse::isButtonPressed(Mouse::Left)) {
					switch (select) {
					case 1:
						stage++;
						pauseTimer = 2800;
						std::cout << " START \n";
						break;
					case 2:
						std::cout << "EXIT\n";
						//return;
						break;
					}
				}
				break;
			case 1:
				showMenu = 2;
				select = 0;
				//showMenu = true;				
				if (IntRect(499, 120, 94*3, 32*3).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); select = 1; }
				if (IntRect(499, 229, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); select = 2; }
				if (IntRect(499, 338, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); select = 3; }
				if (IntRect(499, 447, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Yellow); select = 4; }
				if (Mouse::isButtonPressed(Mouse::Left)) {
					switch (select) {
					case 1:
						//stage = 5;
						return; //
						pauseTimer = 2800;
						std::cout << "PLAY \n";
						break;
					case 2:						
						pauseTimer = 2800;
						std::cout << "CHOOSE MAP \n";
						break;
					case 3:
						stage++;
						pauseTimer = 2800;
						std::cout << "CHOOSE BOT \n";
						break;
					case 4:
						stage--;
						pauseTimer = 2800;
						std::cout << "BACK \n";
					}
				}
				break;
			case 2:
				showMenu = 3;
				select = 0;
				//showMenu = true;				
				if (IntRect(499, 170, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); select = 1; }
				if (IntRect(499, 320, 94 * 3, 32 * 3).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); select = 2; }
				if (Mouse::isButtonPressed(Mouse::Left)) {
					switch (select) {
					case 1:
						//Botdif = 0;
						BotDec = 0;
						stage--;
						pauseTimer = 2800;
						std::cout << "BOT 0 \n";
						break;
					case 2:
						//Botdif = 1;
						BotDec = 1;
						stage--;
						pauseTimer = 2800;
						std::cout << "BOT 1 \n";
						break;
					}
				}
				break;
			}
		}

		window.clear();

		window.draw(border);		
	/*	menu1.setPosition(499, 120);
		window.draw(menu1);
		menu2.setPosition(499, 229);
		window.draw(menu2);
		menu1.setPosition(499, 338);
		window.draw(menu1);
		menu2.setPosition(499, 447);
		window.draw(menu2);

		menu1.setPosition(499, 170);
		window.draw(menu1);
		menu2.setPosition(499, 320);
		window.draw(menu2);*/

		switch (showMenu) {
		case 1:			
			menu1.setPosition(499, 170);
			window.draw(menu1);
			tname.setString("START");
			tname.setPosition(525+60, 190);
			window.draw(tname);
			menu2.setPosition(499, 320);
			window.draw(menu2);
			tname.setString("EXIT");
			tname.setPosition(525+75, 340);
			window.draw(tname);
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			break;
		case 2:
			menu1.setPosition(499, 120);
			window.draw(menu1);
			tname.setString("NEW GAME");
			tname.setPosition(525 + 20, 140);
			window.draw(tname);
			menu2.setPosition(499, 229);
			window.draw(menu2);
			tname.setString("     CHOOSE\n"
				            "BACKGROUND");
			tname.setPosition(525-15, 230);
			window.draw(tname);
			menu3.setPosition(499, 338);
			window.draw(menu3);
			tname.setString("  CHOOSE\n"
			                "DIFFICULTY");
			tname.setPosition(525+20, 339);
			window.draw(tname);
			menu4.setPosition(499, 447);
			window.draw(menu4);
			tname.setString("BACK");
			tname.setPosition(525 + 70, 470);
			window.draw(tname);
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			menu3.setColor(Color::White);
			menu4.setColor(Color::White);
			break;
		case 3:
			menu1.setPosition(499, 170);
			window.draw(menu1);
			tname.setString("TRAINING");
			tname.setPosition(525 + 30, 190);
			window.draw(tname);
			menu2.setPosition(499, 320);
			window.draw(menu2);
			tname.setString("NORMAL");
			tname.setPosition(525 + 40, 340);
			window.draw(tname);
			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			break;
		}
		
		window.display();
	}
}
void CBattle::GameBody(RenderWindow& window) {
	Texture fieldtexture;
	//fieldtexture.loadFromFile("img/m.png");
	fieldtexture.loadFromFile("img/IN.png");

	Sprite fieldsprite;
	fieldsprite.setTexture(fieldtexture);
	fieldsprite.setTextureRect(IntRect(0, 0, 64, 64));
	fieldsprite.setScale(0.7, 0.7);
	//fieldsprite.setPosition(0, 0);

	Texture shiptexture;	
	shiptexture.loadFromFile("img/SingleFile1.png");
	Sprite shipsprite;
	shipsprite.setTexture(shiptexture);
	//shipsprite.setTextureRect(IntRect(8, 100, 124, 117));
	shipsprite.setScale(1.3, 1.3);
	shipsprite.setOrigin(15, 15);
	shipsprite.setPosition(0+15, 0+15);		
	/////////////////////////////////
	Texture pointexture;
	pointexture.loadFromFile("img/C.png");

	Sprite pointsprite;
	pointsprite.setTexture(pointexture);
	pointsprite.setTextureRect(IntRect(0, 0, 32, 32));
	pointsprite.setPosition(532, 0);
	
	/////////////////////////////////
	/////////////////////////////////
	Texture bdtexture;
	bdtexture.loadFromFile("img/n.jpg");

	Sprite bdsprite;
	bdsprite.setTexture(bdtexture);
	bdsprite.setScale(1.3, 1.3);
	//bdsprite.setTextureRect(IntRect(0, 0, 1056, 648));
	bdsprite.setPosition(0, 0);	

	Font font;//шрифт 
	font.loadFromFile("img/NB.ttf");
	Text Fl("", font, 30), Mstk("", font, 20);
	//text.setFillColor(Color::Yellow);	
	Fl.setStyle(sf::Text::Bold);
	Mstk.setStyle(sf::Text::Bold);
	Mstk.setFillColor(Color::Red);	
	Mstk.setPosition(0, 410);

	//Bot* nBot;
	Bot nBot(BotDec); //crating new bot		
	std::cout << nBot.ReturnDif() << " Bots dif \n";
	Field MainField; //creating new field
	Field BotField; //creating bot's field	
	Ship fleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }; // 0..3 = "1", 4..6 = "2", 7..8 = "3, 9 = "4"  -  creating new fleet  
	Ship BotFleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };  //creating bot's field
	int stage = 5;
	int xс = 0, yс = 0;
	int fi = 160, la = 100;	
	int n = 0;
	int rd = 0;
	int wid = 0;	
	std::string dr = "";
	bool pnt = false, shipnt = false;
	bool rot = false;	
	int r = 0;	
	int Botdif = 0;	
	int mstkT = 0;
	Clock clock;
	float pauseTimer = 2020;

	while (window.isOpen())
	{
		float timer = clock.getElapsedTime().asMicroseconds(); 
		clock.restart(); 
		timer = timer / 800; 
		pauseTimer += timer;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////GAME///////////	

		
		if (pauseTimer > 2990) {
			switch (stage) {					
			case 5:				
				/*srand(time(0));
				nBot.BotPutShip(MainField, fleet);
				stage++;
				pauseTimer = 0;*/
				pauseTimer = 2920;
				shipnt = true;
				//rot = false;
				rd = fleet[n].ReturnDecks();
				wid = 31 * rd;
				dr = fleet[n].ReturnDirection();				
				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
					if ("LEFT" == dr) {
						if (yс - rd >= 0) {
							yс--;
							fi -= 40;
						}
					} else if (yс > 0) {
						yс--;
						fi -= 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
					if ("RIGHT" == dr) {
						if (yс + rd <= 9) {
							yс++;
							fi += 40;
						}
					}
					else if (yс < 9) {
						yс++;
						fi += 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
					if ("UP" == dr) {
						if (xс - rd >= 0) {
							xс--;
							la -= 40;
						}
					}
					else if (xс > 0) {
						xс--;
						la -= 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
					if ("DOWN" == dr) {
						if (xс + rd <= 9) {
							xс++;
							la += 40;
						}
					}
					else if (xс < 9) {
						xс++;
						la += 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::N))) {
					int puts = MainField.PutShip(xс, yс, fleet, n);
					if (puts) {
						n++;
						fi = 160;
						la = 100;
						xс = yс = 0;
						r = 0;
						pauseTimer = 2700;
					}
					else
						mstkT = 1;
					if (MainField.ReturnSCount() == LEN) {
						stage++;
						shipnt = false;
						pauseTimer = 2000;
					}					
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::R))) {					
					pauseTimer = 2800;
					switch (dr[0]) {
					case 'R':
						if (xс + rd <= 10) {							
							fleet[n].SetDirection("DOWN");
							rot = true;
							r = 1;
						}
						break;
					case 'D':
						if (yс - rd + 1 >= 0) {							
							fleet[n].SetDirection("LEFT");
							rot = true;
							r = 2;
						}
						break;
					case 'L':
						if (xс - rd + 1 >= 0) {							
							fleet[n].SetDirection("UP");
							rot = true;
							r = 3;
						}
						break;
					case 'U':
						if (yс + rd <= 10) {							
							fleet[n].SetDirection("RIGHT");
							rot = true;
							r = 0;
						}
						break;
					}
					break;
				}
				break;
			case 6:	
				//shipnt = false;
				srand(time(0));
				nBot.BotPutShip(BotField, BotFleet);
				stage++;
				fi = 730;
				la = 100;
				pauseTimer = 1500;	
				xс = 0, yс = 0;
				break;
			case 7:
				//pnt = true;
				//la = 0;		
				pnt = true;
				pauseTimer = 2920;				
				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
					if (yс > 0) {
						yс--;
						fi -= 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
					if (yс < 9) {
						yс++;
						fi += 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
					if (xс > 0) {
						xс--;
						la -= 40;
					}
					break;
				}
				if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
					if (xс < 9) {
						xс++;
						la += 40;
					}
					break;
				}				
				if ((Keyboard::isKeyPressed(Keyboard::N))) {
					int strk = BotField.StrikeCages(xс, yс, BotFleet);
					if (strk == 1) {
						stage++;
						pauseTimer = 2000;
						pnt = false;
					}
					else
						if (strk == 0)
							mstkT = 2;
					if (!BotField.ReturnSCount()) {
						return;
					}
						//return;
					///////////////
					break;
				}
				break;
			case 8:				
				//pauseTimer = 2000;
				int strb = nBot.BotStrikeField(MainField, fleet);
				switch (strb) {
				case 1:
					stage--;
					pauseTimer = 1500;
					break;
				case 2:
					pauseTimer = 1500;
					if (!MainField.ReturnSCount())
						return;
					/////////////////
					break;
				}				
				break;
			}			
			//pauseTimer = 0;
		}

		window.clear();
		window.draw(bdsprite);		
				
        //////////////////OUR FIELD/////////		
		
			int f = 150, l = 100;
			Fl.setString("YOUR FIELD");
			Fl.setPosition(f, l+430);
			window.draw(Fl);
			char sym = ' ';
			std::string stt = "";
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					fieldsprite.setPosition(f, l);
					stt = MainField.ReturnCStat(i, j);
					sym = stt[0];
					switch (sym) {
					case 'I':
						fieldsprite.setTextureRect(IntRect(0, 0, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					case 'A':
						fieldsprite.setTextureRect(IntRect(64, 0, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					case 'D':
						fieldsprite.setTextureRect(IntRect(64, 64, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					case 'M':
						fieldsprite.setTextureRect(IntRect(0, 64, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					case 'E':
						fieldsprite.setTextureRect(IntRect(128, 0, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					case 'N':
						fieldsprite.setTextureRect(IntRect(128, 0, 64, 64));//получили нужный нам прямоугольник с котом
						break;
					}

					window.draw(fieldsprite);

					f += 40;
				}
				f = 150;
				l += 40;
			}
			/////////////////////////ENEMY'S FIELD
			
			f = 730;
			l = 100;
			Fl.setString("ENEMY'S FIELD");
			Fl.setPosition(f, l+430);
			window.draw(Fl);
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					fieldsprite.setPosition(f, l);
					stt = BotField.ReturnCStat(i, j);
					sym = stt[0];
					switch (sym) {
					case 'I':
						fieldsprite.setTextureRect(IntRect(0, 0, 64, 64));
						break;
					case 'A':
						fieldsprite.setTextureRect(IntRect(64, 0, 64, 64));
						break;
					case 'D':
						fieldsprite.setTextureRect(IntRect(64, 64, 64, 64));
						break;
					case 'M':
						fieldsprite.setTextureRect(IntRect(0, 64, 64, 64));
						break;
					case 'E':
						fieldsprite.setTextureRect(IntRect(128, 0, 64, 64));
						break;
					case 'N':
						fieldsprite.setTextureRect(IntRect(0, 64, 64, 64));
						break;
					}
					window.draw(fieldsprite);

					f += 40;
				}
				f = 730;
				l += 40;
			}		
		
		if (shipnt) {
			shipsprite.setPosition(fi + 10, la + 20);
			shipsprite.setRotation(90 * r);
			shipsprite.setTextureRect(IntRect(9, 193, wid, 30));			
			window.draw(shipsprite);
		}		
		if (pnt) {
			pointsprite.setPosition(fi+16, la+16);
			window.draw(pointsprite);
			//pnt = false;
		}		

		if (mstkT) {
			switch (mstkT) {
			case 1:
				Mstk.setString("Area is already busy!");
				break;
			case 2:
				Mstk.setString("The spot has already been striked!");
				break;
			}
			window.draw(Mstk);
		}

		window.display();		

		///////////////////GAME///////////
	}
}
void CBattle::NewGame() {	
	
}

void CBattle::PrintF(Field& _fld, int c) {
	
}
