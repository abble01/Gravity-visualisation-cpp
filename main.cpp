#include <SFML/Graphics.hpp>
#include <optional>
#include "UI.h"
#include "Body.h"  


int main() {
	
	sf::RenderWindow window(
		sf::VideoMode({1366,768}),
		"Gravity Visualisation Project"
		);

	//USER INTERFACE
	UI ui;

	//temp objects-------------
	sf::CircleShape preview;

	preview.setRadius(25.f);
	preview.setFillColor(sf::Color::Magenta);
	preview.setOrigin({ 25.f, 25.f });
	//---------------------------

	bool placing = false;
	while (window.isOpen())
	{

		//EVENTS
		while (const std::optional event = window.pollEvent())
		{

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}

			if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
			{
				if (placing && mouseButtonPressed->button == sf::Mouse::Button::Left)
				{
					placing = false;
				}

				if (mouseButtonPressed->button == sf::Mouse::Button::Left &&
					ui.earthButton.getGlobalBounds().contains(
						sf::Vector2f(mouseButtonPressed->position)))
				{
					placing = true; 
				}

			}
		};

		//PLACING LOGIC
		if (placing) 
		{
			sf::Vector2f m_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			preview.setPosition(m_pos);
		}


		window.clear(); // can go at top of parent while

		if (placing) {
			window.draw(preview);
		}
		
		window.draw(ui.hud);
		window.draw(ui.earthButton);
		window.display();


	}


	return 0;
}