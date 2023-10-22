#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/Engine.hpp>
#include<engine/gameplay/components/SpriteRenderer.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Player::Player()
			{
				//shapeList.load("player");
				collisionGeomId = dCreateBox(engine::Engine::getInstance().getPhysicsManager().getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				dGeomSetData(collisionGeomId, this);

				std::shared_ptr<SpriteRenderer> spriteR = std::make_shared<SpriteRenderer>();
				spriteR->SetActor(this);
				spriteR->shapeList.load("player");
				components.push_back(spriteR);
				engine::Engine::getInstance().getGraphicsManager().spriteRenderers.push_back(spriteR);
			}

			void Player::update()
			{
				justMoved = false;
				auto position = getPosition();
				float rotation = getRotation();

				if (engine::Engine::getInstance().getInputManager().isKeyJustPressed(sf::Keyboard::Left))
				{
					justMoved = true;
					position.x -= gameplay::Manager::CELL_SIZE;
					rotation = 180.f;
				}

				if (engine::Engine::getInstance().getInputManager().isKeyJustPressed(sf::Keyboard::Right))
				{
					justMoved = true;
					position.x += gameplay::Manager::CELL_SIZE;
					rotation = 0.f;
				}

				if (engine::Engine::getInstance().getInputManager().isKeyJustPressed(sf::Keyboard::Up))
				{
					justMoved = true;
					position.y -= gameplay::Manager::CELL_SIZE;
					rotation = -90.f;
				}

				if (engine::Engine::getInstance().getInputManager().isKeyJustPressed(sf::Keyboard::Down))
				{
					justMoved = true;
					position.y += gameplay::Manager::CELL_SIZE;
					rotation = 90.f;
				}

				if (justMoved)
				{
					setPosition(position);
					setRotation(rotation);

					dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
				}

				auto collisions = engine::Engine::getInstance().getPhysicsManager().getCollisionsWith(collisionGeomId);
				for (auto &geomId : collisions)
				{
					auto entity = reinterpret_cast<Actor *>(dGeomGetData(geomId));
					auto targetEntity = dynamic_cast<entities::Target *>(entity);
					if (targetEntity)
					{
						engine::Engine::getInstance().getGameplayManager().loadNextMap();
					}
				}
			}

			bool Player::hasJustMoved() const
			{
				return justMoved;
			}
		}
	}
}
