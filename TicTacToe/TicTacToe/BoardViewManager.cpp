#include "BoardViewManager.h"
#include <SFML/Graphics.hpp>


BoardViewManager::BoardViewManager()
{
}


BoardViewManager::~BoardViewManager()
{
}

void BoardViewManager::LoadSprites()
{
	sf::Texture crossTx;
	if (!crossTx.loadFromFile("../sprites/cross.png"))
	{
		// error...
	}
	sf::Vector2f crossVeloss(1, 0);//naming is why
}
