#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class BoardViewManager//class for handling the "view"
{
public:
	BoardViewManager();
	~BoardViewManager();
	void LoadSprites();
	void Draw(sf::RenderWindow &window);
	void NewChoice();

	std::vector<sf::Sprite> toDraw;

	sf::Sprite cross;
	sf::Sprite naught;
	sf::Sprite grid;
	sf::Sprite frame;
	sf::Sprite selector;

	sf::Texture crossTx;
	sf::Texture naughtTx;
	sf::Texture gridTx;
	sf::Texture frameTx;
	sf::Texture selectorTx;
};

