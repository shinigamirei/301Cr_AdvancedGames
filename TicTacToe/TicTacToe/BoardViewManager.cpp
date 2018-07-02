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
	crossTx.loadFromFile("../sprites/cross.png");
	frameTx.loadFromFile("../sprites/frame.png");
	gridTx.loadFromFile("../sprites/grid.png");
	naughtTx.loadFromFile("../sprites/naught.png");
	selectorTx.loadFromFile("../sprites/cursor.png");

	cross.setTexture(crossTx);//bind textures to sprites
	naught.setTexture(naughtTx);
	frame.setTexture(frameTx);
	grid.setTexture(gridTx);
	grid.setPosition(sf::Vector2f(30, 30));//puts grid in correct position
	selector.setTexture(selectorTx);

	toDraw.insert(toDraw.end(), cross);
	toDraw.insert(toDraw.end(), grid);
	toDraw.insert(toDraw.end(), frame);
}

void BoardViewManager::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < toDraw.size(); i++)
		window.draw(toDraw[i]);

	window.draw(selector);// things in the toDraw vector wont move to position correctly, so anyhting that moves has to be outside the vector
}

void BoardViewManager::NewChoice()
{

}