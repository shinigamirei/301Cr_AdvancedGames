#pragma once
#include <SFML/Graphics.hpp>

class GameManager //"model" handles the logic of the game
{
public:
	GameManager();
	~GameManager();

	void VictoryCheck();
	void SelectorUpdate(sf::RenderWindow &window);
	void SpaceChosen(int &player);
	int board[3][3];
	sf::Vector2f selectorLocation;
	sf::Vector2i selectorBoardLocation;
	sf::Vector2i mousePosition;

};

