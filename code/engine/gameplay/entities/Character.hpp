#pragma once

#include <ode/collision.h>
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
				dGeomID collisionGeomId;

				bool isWalking{ false };
			};
		}
	}
}
