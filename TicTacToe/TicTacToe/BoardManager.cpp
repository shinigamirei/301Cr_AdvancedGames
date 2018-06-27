#include "BoardManager.h"
#include <SFML/Graphics.hpp>


BoardManager::BoardManager()
{
}


BoardManager::~BoardManager()
{
}

void BoardManager::BoardSetup()
{
}

void BoardManager::LoadSprites()
{
	sf::Texture crossTx;
	if (!crossTx.loadFromFile("../sprites/cross.png"))
	{
		// error...
	}
	sf::Vector2f crossVeloss(1, 0);//naming is why
}
