#pragma once

#include <SFML/Graphics.hpp>

struct UI
{
	sf::Color hudGrey;

	sf::RectangleShape hud;
	sf::RectangleShape earthButton;

	sf::Font font;
	UI()
	{
		//font.openFromFile()
		hudGrey = sf::Color(30, 30, 30);
		hud.setSize({ 1366.f, 75.f });
		hud.setPosition({ 0.f, 692.f });
		hud.setFillColor(hudGrey);

		earthButton.setSize({ 150.f, 50.f });
		earthButton.setPosition({ 25.f, 705.f });
		earthButton.setFillColor(sf::Color::Blue);
	}
};