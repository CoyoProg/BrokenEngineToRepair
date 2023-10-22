#include "SpriteRenderer.hpp"
#include <engine/Engine.hpp>
#include <engine/gameplay/Actor.hpp>

namespace engine
{
	SpriteRenderer::~SpriteRenderer()
	{
		engine::Engine::getInstance().getGraphicsManager().removeSprite();
	}

	void SpriteRenderer::draw()
	{
		engine::Engine::getInstance().getGraphicsManager().drawShape(shapeList, actor->getTransform());
	}
}
