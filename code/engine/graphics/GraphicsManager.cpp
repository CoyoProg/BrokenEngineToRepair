#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/graphics/Window.h>

namespace engine
{
	namespace graphics
	{
		Manager::Manager()
		{
			window = new Window();
		}

		Manager::~Manager()
		{
		}

		void Manager::update()
		{
		}

		void Manager::clear()
		{
			window->clear();
		}

		void Manager::draw(const ShapeList &shapeList, const sf::Transform &transform)
		{
			sf::RenderStates renderStates{ transform };
			for (auto shape : shapeList.getShapes())
			{
				window->draw(*shape, renderStates);
			}
		}

		void Manager::display()
		{
			window->display();
		}
	}
}
