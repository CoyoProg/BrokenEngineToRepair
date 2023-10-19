#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <engine/gameplay/components/SpriteRenderer.hpp>

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

			void draw(const ShapeList &shapeList, const sf::Transform &transform);
			void display();
			void draw();

			Window& getWindow() { return *window; };
			std::vector<SpriteRenderer*> spriteRenderers;

		private:
			Window* window = nullptr;
		};
	}
}
