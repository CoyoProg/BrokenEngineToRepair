#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

class Window
{
public:
	Window();
	~Window();
	void init();
	void clear();
	void draw(sf::Shape& shape, sf::RenderStates renderStates);
	void display();
	sf::RenderWindow& getWindow() { return window; }
private:
	sf::RenderWindow window;

	static const sf::Int16 WINDOW_WIDTH = 800;
	static const sf::Int16 WINDOW_HEIGHT = 600;
};

