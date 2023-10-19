#pragma once

#include <SFML/Graphics/Shape.hpp>

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

			void clear();
			void draw(const ShapeList &shapeList, const sf::Transform &transform);
			void display();

			Window& getWindow() { return *window; };

		private:
			Window* window = nullptr;
		};
	}
}
