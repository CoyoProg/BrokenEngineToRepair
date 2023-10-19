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
			class Target : public Actor
			{
			public:
				Target();
				~Target();

				virtual void update() override;

			private:
				dGeomID collisionGeomId;
			};
		}
	}
}
