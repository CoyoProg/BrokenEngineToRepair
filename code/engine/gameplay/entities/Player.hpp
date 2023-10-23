#pragma once

#include <engine/gameplay/entities/Character.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player : public Character
			{
			public:
				Player();

				void init() override;
				void update() override;

				bool hasJustMoved() const;

			private:
				bool justMoved{ false };

				void CheckCollisions();
				void MovePlayer(sf::Vector2f& position, float& rotation);
			};
		}
	}
}
