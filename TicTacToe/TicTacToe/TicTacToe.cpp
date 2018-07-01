#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "BoardViewManager.h"

bool chatInput = false;
BoardViewManager boardViewManager;
GameManager gameManager = GameManager::getInstance();
int programFunction; //determines if the program is being lauunched as client or server

int main(int argc, char** argv)
{
	
	std::cout << "press 1 for client, or 2 for server" << std::endl;
	while (programFunction == 0)
	{
		std::cin >> programFunction;
	}

	while (programFunction == 1)
	{
		sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!", sf::Style::Default);//setting style gives us options of what the window has at the top

		//boardManager.LoadSprites();
		//load all sprites 
		sf::Sprite crossSp;
		sf::Texture crossTx;
		
		sf::Sprite frameSp;
		sf::Texture frameTx;
		
		sf::Sprite gridSp;
		sf::Texture gridTx;

		sf::Sprite naughtSp;
		sf::Texture naughtTx;

		sf::Sprite selectorSp;
		sf::Texture selectorTx;

		if (!crossTx.loadFromFile("../sprites/cross.png"))
		{
			// error...
		}
		if (!frameTx.loadFromFile("../sprites/frame.png"))
		{
			// error...
		}
		if (!gridTx.loadFromFile("../sprites/grid.png"))
		{
			// error...
		}
		if (!naughtTx.loadFromFile("../sprites/naught.png"))
		{
			// error...
		}
		if (!selectorTx.loadFromFile("../sprites/cursor.png"))
		{
			// error...
		}
		
		crossSp.setTexture(crossTx);
		naughtSp.setTexture(naughtTx);
		frameSp.setTexture(frameTx);		
		gridSp.setTexture(gridTx);
		gridSp.setPosition(sf::Vector2f(30, 30));
		selectorSp.setTexture(selectorTx);


		sf::Vector2f crossVeloss(1, 0);//naming is why

		while (window.isOpen())
		{
			/*		crossSp.move(crossVeloss);
					if (crossSp.getPosition().x > 100)
						crossVeloss.x = -1;
					else if (crossSp.getPosition().x < 0)
						crossVeloss.x = 1; *///for movement test
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Enter && chatInput == true)
					{
						std::cout << "enter" << std::endl;
						chatInput = false;
					}
					else if (event.key.code == sf::Keyboard::T && chatInput == false)
					{
						std::cout << "We Chat Bois" << std::endl;
						chatInput = true;
					}

				case sf::Event::TextEntered:
					if (event.text.unicode < 128 && chatInput == true)
						std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

				default:
					break;
				}
			}

			window.clear();
			window.draw(crossSp); 
			window.draw(naughtSp);
			window.draw(frameSp);
			window.draw(gridSp);
			gameManager.SelectorUpdate(window);
			selectorSp.setPosition(gameManager.selectorLocation);
			window.draw(selectorSp);
			window.display();
		}
	}
}