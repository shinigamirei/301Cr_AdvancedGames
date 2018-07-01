#include "GameManager.h"



GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

GameManager & GameManager::getInstance()
{
		static GameManager instance;
		return instance;
}

void GameManager::VictoryCheck()
{
}

void GameManager::SelectorUpdate(sf::RenderWindow &window)
{
	mousePosition = sf::Mouse::getPosition(window);
	//all the different places in the grid
	if (mousePosition.x < 110 && mousePosition.y < 110)		//top left
	{
		selectorLocation = sf::Vector2f(32.5, 32.5);
		selectorBoardLocation = sf::Vector2i(0, 0);
	}
	else if (mousePosition.x < 110 && mousePosition.y > 190)//bottom left
	{
		selectorLocation = sf::Vector2f(32.5, 200);

		selectorBoardLocation = sf::Vector2i(0, 2);
	}
	else if (mousePosition.x < 110)							//middle left
	{
		selectorLocation = sf::Vector2f(33, 113);
		selectorBoardLocation = sf::Vector2i(0, 1);
	}
	else if (mousePosition.x > 190 && mousePosition.y < 110)//top right
	{
		selectorLocation = sf::Vector2f(194, 33);
		selectorBoardLocation = sf::Vector2i(2, 0);
	}
	else if (mousePosition.x > 190 && mousePosition.y > 190)//bottom right
	{
		selectorLocation = sf::Vector2f(194, 194);
		selectorBoardLocation = sf::Vector2i(2, 2);
	}
	else if (mousePosition.x > 190)							//middle right
	{
		selectorLocation = sf::Vector2f(194, 113);
		selectorBoardLocation = sf::Vector2i(2, 1);
	}
	else if (mousePosition.y < 110)							//top middle
	{
		selectorLocation = sf::Vector2f(113, 33);
		selectorBoardLocation = sf::Vector2i(1, 0);
	}
	else if (mousePosition.y > 190)							//bottom middle
	{
		selectorLocation = sf::Vector2f(113, 194);
		selectorBoardLocation = sf::Vector2i(1, 2);
	}
	else													//centre
	{
		selectorLocation = sf::Vector2f(113, 114);
		selectorBoardLocation = sf::Vector2i(1, 1);
	}
}

void GameManager::SpaceChosen(int &player)
{

}
