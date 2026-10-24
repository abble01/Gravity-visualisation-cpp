#pragma once

#include <SFML/Graphics.hpp>
#include <string>


struct Button
{
	sf::RectangleShape background;
	sf::Text label;


	Button(const sf::Font& font, const std::string& text, sf::Vector2f position)
		: background({ 180.f, 48.f }),
		label(font, text)
	{
		background.setFillColor(sf::Color(25, 45, 65));
		background.setOutlineThickness(2.f);
		background.setOutlineColor(sf::Color(60, 190, 220));

		label.setCharacterSize(20);
		label.setFillColor(sf::Color::White);

		background.setPosition(position);
		label.setPosition(position);
		const auto bounds = label.getLocalBounds();
		label.setOrigin({ bounds.position.x + bounds.size.x / 2.f,
				 bounds.position.y + bounds.size.y / 2.f });
	}

	void draw(sf::RenderWindow& window) const
	{
		window.draw(background);
		window.draw(label);
	}
	bool contains(sf::Vector2f point) const
	{
		return background.getGlobalBounds().contains(point);
	}

};



struct UI
{
	
	sf::Font font;
	Button addBodyButton;

	UI()
		: font("assets/Orbitron.ttf"),
		addBodyButton(font, "Add Body", sf::Vector2f(20.f, 700.f))
	{

	}
};