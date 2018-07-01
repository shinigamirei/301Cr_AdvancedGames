#pragma once
#include <SFML/Graphics.hpp>

class BoardViewManager//class for handling the "view"
{
public:
	BoardViewManager();
	~BoardViewManager();
	void LoadSprites();

	sf::Sprite cross;
	sf::Sprite naught;
	sf::Sprite grid;
	sf::Sprite frame;
	sf::Sprite selector;
};

