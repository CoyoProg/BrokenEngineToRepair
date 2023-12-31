#include "Target.hpp"

#include <engine/Engine.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target()
			{			
			}

			Target::~Target()
			{
				dGeomDestroy(collisionGeomId);
			}

			void Target::init()
			{
				collisionGeomId = dCreateBox(engine::Engine::getInstance().getPhysicsManager().getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				dGeomSetData(collisionGeomId, this);

				std::shared_ptr<SpriteRenderer> spriteR = std::make_shared<SpriteRenderer>();
				spriteR->SetActor(shared_from_this());
				spriteR->shapeList.load("target");
				components.push_back(spriteR);
				engine::Engine::getInstance().getGraphicsManager().spriteRenderers.push_back(spriteR);
			}

			void Target::update()
			{
				auto &position = getPosition();
				dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
			}
		}
	}
}
