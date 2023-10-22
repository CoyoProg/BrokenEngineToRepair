#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <engine/gameplay/components/SpriteRenderer.hpp>
#include <memory>

class Window;

namespace engine
{
	namespace graphics
	{
		class ShapeList;

		class Manager
		{
		public:
			Manager();
			~Manager();

			void update();

			void removeSprite();
			void drawShape(const ShapeList &shapeList, const sf::Transform &transform);
			void display();
			void draw();

			Window& getWindow() { return *window; };
			std::vector<std::weak_ptr<SpriteRenderer>> spriteRenderers;

		private:
			std::unique_ptr<Window> window = nullptr;
		};
	}
}
