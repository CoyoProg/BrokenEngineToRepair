#pragma once

#include <engine/gameplay/Component.hpp>
#include <engine/graphics/ShapeList.hpp>

namespace engine
{
	class SpriteRenderer : public Component
	{
	public:
		virtual ~SpriteRenderer();
		void draw();
		graphics::ShapeList shapeList;
	private:
	};
}
