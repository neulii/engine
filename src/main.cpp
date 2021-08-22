#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include <string>
#include <iostream>

void render();
void update(sf::Int64 loopDuration);




sf::Font font;
sf::RenderWindow window(sf::VideoMode(800,800),"MyGame");
sf::Text fps_Label("FPS:" , font, 20);
sf::Text text("Hello sfml",font,30);


int main()
{
	sf::Clock loopTime;


	sf::Int64 loopStartTime;
	sf::Int64 loopEndTime;
	sf::Int64 loopDuration;

	int fps = 0;



	
	if(!font.loadFromFile("../resources/fonts/arial.ttf"))
		std::cout << "font not found" << std::endl;

	
		
	
	
	fps_Label.setPosition(10,10);
	
	text.setFillColor(sf::Color::Red);
	text.setPosition(300,300);



	sf::RectangleShape r(sf::Vector2f(50,30));
	

	sf::Time timer;
	loopStartTime = 0;
	sf::Time superTime;
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		superTime = loopTime.getElapsedTime();
		loopTime.restart();


		//loopEndTime = loopStartTime;
		//loopStartTime = timer.asMicroseconds();
	//	loopDuration = loopEndTime - loopStartTime;
		loopDuration = superTime.asMicroseconds();
		fps = 1000000/loopDuration;
			
		fps_Label.setString("FPS: " + std::to_string(fps));
		//std::cout << fps << std::endl;
		for (int i = 0; i<10000; i++)
		{
			;
		}		
		
		
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
		update(loopDuration);
		render();

	}

	


	return 0;
}


void render()
{

		window.clear(sf::Color::Black);
		//	window.draw(r);
 		window.draw(text);
		window.draw(fps_Label);

		window.display();
}
void update(sf::Int64 loopDuration)
{


}


