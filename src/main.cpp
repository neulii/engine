#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	

	sf::Font font;
	if(!font.loadFromFile("../resources/fonts/arial.ttf"))
		std::cout << "font not found" << std::endl;

	sf::Text text("Hello sfml",font,50);


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
 		window.draw(text);

		window.display();
	}


	return 0;
}



