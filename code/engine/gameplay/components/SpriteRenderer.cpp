#include "SpriteRenderer.hpp"
#include <engine/Engine.hpp>
#include <engine/gameplay/Actor.hpp>

namespace engine
{
	SpriteRenderer::~SpriteRenderer()
	{
		auto& renderers = engine::Engine::getInstance().getGraphicsManager().spriteRenderers;
		int spriteRenderersCount = renderers.size();
		for (int i = 0; i < spriteRenderersCount; i++)
		{
			if (renderers[i] == this) 
			{
				renderers.erase(renderers.begin() + i);
				break;
			}
		}
	}

	void SpriteRenderer::draw()
	{
		engine::Engine::getInstance().getGraphicsManager().draw(shapeList, actor->getTransform());
	}
}
