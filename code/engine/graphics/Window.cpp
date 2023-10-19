#include "Window.h"

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/Engine.hpp>

Window::Window()
{
	init();
}

Window::~Window()
{
	window.close();
}

void Window::init()
{
	window.create(sf::VideoMode{ (unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT }, "Stealth Factor");

	window.setVerticalSyncEnabled(true);

	sf::View view(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	window.setView(view);
}

void Window::clear()
{
	window.clear(sf::Color::Black);

	sf::View view{ engine::Engine::getInstance().getGameplayManager().getViewCenter(), sf::Vector2f{(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT} };
	window.setView(view);
}

void Window::draw(sf::Shape& shape, sf::RenderStates renderStates)
{
	window.draw(shape, renderStates);
}

void Window::display()
{
	window.display();
}
