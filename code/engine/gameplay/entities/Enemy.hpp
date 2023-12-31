#pragma once

#include <string>
#include <engine/gameplay/entities/Character.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Enemy : public Character
			{
			public:
				Enemy(const std::string &archetypeName);

				void init() override;
				void update() override;

				void CheckPlayerPosition();

				void ShootPlayer();

			private:
				float visionRadius{ 0 };
				int shootDelay{ 0 };
				int shootDelayCounter{ 0 };
				bool isPlayerOnSighet{ false };

				std::string archetypeName = "";
				void loadArchetype();
			};
		}
	}
}
