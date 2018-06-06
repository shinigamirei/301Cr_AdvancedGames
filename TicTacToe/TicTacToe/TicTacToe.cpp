#include <iostream>
#include <SFML/Graphics.hpp>

bool chatInput = false;

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!", sf::Style::Default);//setting style gives us options of what the window has at the top
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture crossTx;
	if (!crossTx.loadFromFile("../sprites/cross.png"))
	{
		// error...
	}

	sf::Sprite crossSp;
	crossSp.setTexture(crossTx);
	sf::Vector2f crossVeloss(1, 0);//naming is why

	while (window.isOpen())
	{
		crossSp.move(crossVeloss);
		if (crossSp.getPosition().x > 100)
			crossVeloss.x = -1;
		else if (crossSp.getPosition().x < 0)
			crossVeloss.x = 1;
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
				}
				else if (event.key.code == sf::Keyboard::T && chatInput == false)
				{
					std::cout << "We Chat Bois" << std::endl;
					chatInput = true;
				}

			case sf::Event::TextEntered:
				if (event.text.unicode < 128 && chatInput == true)
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

			default:
				break;
			}
		}

		window.clear();
		window.draw(crossSp);
		window.display();
	}
}