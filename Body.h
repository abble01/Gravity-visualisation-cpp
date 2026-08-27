#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

const double METRES_PER_PIXEL = 500'000'000.0;
class Body
{
	// main planet class
private:
	sf::Vector2<double> m_position;
	sf::Vector2<double> m_velocity;

	double m_mass;
	double m_radius;
	double m_visualRadius;
public:
	Body(
		sf::Vector2<double> position,
		sf::Vector2<double> velocity,
		double mass, // kg
		double radius, // metres
		double visualRadius
	)
		:
		m_position(position),
		m_velocity(velocity),
		m_mass(mass),
		m_radius(radius),
		m_visualRadius(visualRadius)
	{
	}

	void draw(sf::RenderWindow& window) // static cast to floats as we use doubles elsewhere for real world accuracy
	{
		sf::CircleShape shape(static_cast<float>(m_visualRadius));
		shape.setOrigin({ 
			static_cast<float>(m_visualRadius), 
			static_cast<float>(m_visualRadius) });

		/* Will implement real sizes soon
		shape.setOrigin(
			{ 
			static_cast<float>(m_radius / METERS_PER_PIXEL),
			static_cast<float>(m_radius / METERS_PER_PIXEL)
			}
		);
			*/

		shape.setPosition(
			{
			static_cast<float>(m_position.x / METRES_PER_PIXEL),
			static_cast<float>(m_position.y / METRES_PER_PIXEL)
			}
		);

		shape.setFillColor(sf::Color::White);

		window.draw(shape);
	}

	void update(double dt) 
	{
		m_position += m_velocity * dt;
	}

	double getVisualRadius() const
	{
		return m_visualRadius;
	}

};
