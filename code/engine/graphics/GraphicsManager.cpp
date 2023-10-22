#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/graphics/Window.h>
#include <engine/gameplay/components/SpriteRenderer.hpp>

namespace engine
{
	namespace graphics
	{
		Manager::Manager()
		{
			window = std::make_unique<Window>();
		}

		Manager::~Manager()
		{
		}

		void Manager::update()
		{
		}

		void Manager::draw() 
		{
			window->clear();
			int spriteCount = spriteRenderers.size();
			for (int i = 0; i < spriteCount; i++)
			{
				spriteRenderers[i].lock()->draw();
			}
		}

		// TODO : make a better system
		void Manager::removeSprite()
		{
			int spriteCount = spriteRenderers.size();
			for (int i = 0; i < spriteCount; i++)
			{
				if (spriteRenderers[i].expired())
				{
					spriteRenderers.erase(spriteRenderers.begin() + i);
					break;
				}
			}
		}

		void Manager::drawShape(const ShapeList &shapeList, const sf::Transform &transform)
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
