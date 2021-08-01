#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	



	sf::RectangleShape r(sf::Vector2f(50,30));
	

	sf::RenderWindow window(sf::VideoMode(800,800),"MyGame");

	while (window.isOpen())
	{
		

		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
				window.close();
			
			if(event.type==sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			

		}

		window.clear(sf::Color::Black);
		window.draw(r);

		window.display();
	}


	return 0;
}


