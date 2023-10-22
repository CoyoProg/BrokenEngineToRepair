#pragma once

#include <ode/collision.h>
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

				void init() override;
				void update() override;

			private:
				dGeomID collisionGeomId;
			};
		}
	}
}
