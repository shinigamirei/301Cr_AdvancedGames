#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "GameManager.h"
#include "BoardViewManager.h"

bool chatInput = false;
BoardViewManager boardViewManager;
GameManager gameManager = GameManager::getInstance();
int programFunction; //determines if the program is being lauunched as client or server

const unsigned short port = 53000;
const std::string ipAdress("10.0.74.50");//change to suit your needs
std::string msgSend;

sf::TcpSocket socket;
sf::Mutex globalMutex;


bool Client(void)
{
	if (socket.connect(ipAdress, port) == sf::Socket::Done)
	{
		std::cout << "Connected\n";
		return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	std::cout << "press 1 for client, or 2 for server" << std::endl;
	while (programFunction == 0)
	{
		std::cin >> programFunction;
	}

	while (programFunction == 1)
	{
		int playerNumber = 1; //default to 1, will be given by server upon connection
		sf::RenderWindow window(sf::VideoMode(600, 400), "SFML kinda works but in slightly unexpected ways, also tictactoe!", sf::Style::Default);//setting style gives us options of what the window has at the top
		
		sf::Socket::Status status = socket.connect(ipAdress, port);
		if (status != sf::Socket::Done)
		{
			// error...
		}

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

		sf::String chatEntry;

		while (window.isOpen())
		{
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				gameManager.SpaceChosen(playerNumber);
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					if (gameManager.board[x][y] == 1)
					{
						crossSp.setPosition(sf::Vector2f(30 + (x * 80), 30 + (x * 80)));
						window.draw(crossSp);
					}
					else
					{
						naughtSp.setPosition(sf::Vector2f(30 + (x * 80), 30 + (x * 80)));
					}
				}
			}
			window.clear();
			window.draw(frameSp);
			window.draw(gridSp);
			gameManager.SelectorUpdate(window);
			selectorSp.setPosition(gameManager.selectorLocation);
			window.draw(selectorSp);
			window.display();
		}
	}

	while (programFunction == 2)
	{
		int players = 0;
		while (players < 2)//listens for connections untill both players are in
		{
			sf::TcpListener listener;
			std::cout << "the local adress of the server is:" << sf::IpAddress::getLocalAddress();

			listener.listen(port);
			listener.accept(socket);
			players += 1;
			std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl << socket.getRemoteAddress() << "is player " << players << std::endl;

		}
	}
}