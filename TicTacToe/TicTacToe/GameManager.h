#pragma once
#include <SFML/Graphics.hpp>

class GameManager //"model" handles the logic of the game
{

public:
	~GameManager();
	static GameManager& getInstance();

	void VictoryCheck();
	void SelectorUpdate(sf::RenderWindow &window);//updates the selector location both in graphic space and board logic space dependant on cursor location
	void SpaceChosen(int &player);//handles what to do when player chooses a space

	int board[3][3];//0 is empty 1 is cross 2 is naught
	sf::Vector2f selectorLocation;
	sf::Vector2i selectorBoardLocation;
	sf::Vector2i mousePosition;
private:
	GameManager();
};

