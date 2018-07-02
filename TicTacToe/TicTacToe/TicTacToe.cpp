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
const std::string ipAdress("10.0.74.50");//hardcoded ip adress for the uni pc i did the work on, the server gives the ip when run so replace this ip with the ip that gives 
bool gameStarted = false; 

sf::TcpSocket socket;

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

		std::string chatEntry;

		boardViewManager.LoadSprites();

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

						sf::Packet packet;
						sf::Uint16 x = 1;//we use x as a flag to tell the server that the data in this packet is a chat message
						packet << x << chatEntry;
						socket.send(packet);
						
					}
					else if (event.key.code == sf::Keyboard::T && chatInput == false)
					{
						std::cout << "We Chat Bois" << std::endl;
						
						chatEntry.clear();
						chatInput = true;						
					}
					break;

				case sf::Event::TextEntered:
					if (chatInput == true)
					{
						chatEntry += static_cast<char>(event.text.unicode);
					}
					break;
					
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
						crossSp.setPosition(sf::Vector2f(30 + (x * 80.0), 30 + (x * 80.0)));
						window.draw(crossSp);
						//std::cout << "cross at " << x << y << std::endl;
					}
					else
					{
						naughtSp.setPosition(sf::Vector2f(30 + (x * 80), 30 + (x * 80)));
						window.draw(naughtSp);
					}
				}
			}
			window.clear();
			boardViewManager.Draw(window);
			window.draw(gridSp);
			gameManager.SelectorUpdate(window);
			boardViewManager.selector.setPosition(gameManager.selectorLocation);
			window.draw(selectorSp);
			window.display();
		}
	}

int players = 0;
	while (programFunction == 2)
	{
		while (players < 2)//listens for connections until both players are in
		{
			sf::TcpListener listener;
			std::cout << "the local adress of the server is:" << sf::IpAddress::getLocalAddress();

			listener.listen(port);
			listener.accept(socket);
			players += 1;
			std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl << socket.getRemoteAddress() << "is player " << players << std::endl;
		}

		//after players are in handle incoming data in a continuous loop as no other server logic yet
		sf::Packet packet;
		
		sf::Uint16 x;
		std::string s;

		socket.receive(packet);
		packet >> x >> s;
		switch (x)
		{
		case 0:
			break;
		case 1:
			std::cout << s << std::endl;
		default:
			break;
		}

	}
}