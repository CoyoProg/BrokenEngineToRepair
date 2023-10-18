#include "Character.hpp"

#include <engine/Engine.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character()
			{
				collisionGeomId = dCreateBox(engine::Engine::getInstance().getPhysicsManager().getSpaceId(), 0.f, 0.f, 0.f);
				dGeomSetData(collisionGeomId, this);
			}

			Character::~Character()
			{
				dGeomDestroy(collisionGeomId);
			}

			void Character::draw()
			{
				engine::Engine::getInstance().getGraphicsManager().draw(shapeList, getTransform());
			}
		}
	}
}
