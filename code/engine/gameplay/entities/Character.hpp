#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Actor.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Character : public Actor
			{
			public:
				Character();
				virtual ~Character();

			protected:
				//graphics::ShapeList shapeList;
				dGeomID collisionGeomId;

				bool isWalking{ false };
			};
		}
	}
}
