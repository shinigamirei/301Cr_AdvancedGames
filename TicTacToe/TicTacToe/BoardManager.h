#pragma once
#include <SFML/Graphics.hpp>

class BoardManager
{
public:
	BoardManager();
	~BoardManager();
	void BoardSetup();
	void LoadSprites();

	sf::Sprite cross;
	sf::Sprite naught;
	sf::Sprite grid;
	sf::Sprite frame;
	sf::Sprite selector;
};

