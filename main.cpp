#include <SFML/Graphics.hpp>
#include <optional>
#include "UI.h"
#include "Body.h"  
#include <vector>
#include "Physics.h"

// PROJECT CONSTS AND CONFIGS
//const double METRES_PER_PIXEL = 500'000'000.0;
const double G = 6.6743e-11;

double gameSpeed = 86'400;

int main() {
	
	sf::RenderWindow window(
		sf::VideoMode({1366,768}),
		"Gravity Visualisation Project"
		);
	sf::Clock clock;

	//OBJECTS
	UI ui;
	std::vector<Body> bodies;
	Physics physics;

	//temp objects-------------
	sf::CircleShape preview;

	preview.setRadius(25.f);
	preview.setFillColor(sf::Color::Magenta);
	preview.setOrigin({ 25.f, 25.f });
	//---------------------------

	bool placing = false;
	while (window.isOpen())
	{
		double dt = clock.restart().asSeconds() * gameSpeed;
		//EVENTS /
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
					sf::Vector2<double> position = {
						static_cast<double>(mouseButtonPressed->position.x) * METRES_PER_PIXEL,
						static_cast<double>(mouseButtonPressed->position.y) * METRES_PER_PIXEL
					};

					placing = false;
					Body newBody(
						"Test",
						position,
						{ 100'000.0, 0.0 },
						1.f,          // temporary values
						67e6,
						15
					);
					bodies.push_back(newBody);

					preview.setRadius(static_cast<float>(bodies.back().getVisualRadius()));
					preview.setOrigin({
							static_cast<float>(bodies.back().getVisualRadius()),
							static_cast<float>(bodies.back().getVisualRadius())
						});
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

		for (Body& body : bodies)
		{
			body.updatePosition(dt);
			body.draw(window);
		}

		
		physics.update(bodies, dt);
		window.draw(ui.hud);
		window.draw(ui.earthButton);
		window.display();


	}


	return 0;
}