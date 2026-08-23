#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
class Body
{
	// hiughshdhsifow
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	float m_mass;
	float m_radius;

public:
	Body(
		sf::Vector2f position,
		sf::Vector2f velocity,
		float mass,
		float radius
	)
		:
		m_position(position),
		m_velocity(velocity),
		m_mass(mass),
		m_radius(radius)
	{
	}

	void draw(sf::RenderWindow& window)
	{
		sf::CircleShape shape(m_radius);

		shape.setOrigin(sf::Vector2f({ m_radius, m_radius }));
		shape.setPosition(m_position);
		shape.setFillColor(sf::Color::White);

		window.draw(shape);
	}


};
