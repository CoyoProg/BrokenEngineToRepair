#include "Enemy.hpp"

#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <engine/gameplay/entities/Player.hpp>
#include  <engine/Engine.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Enemy::Enemy(const std::string &archetypeName_)
			{
				archetypeName = archetypeName_;
				
			}

			void Enemy::init()
			{
				loadArchetype();
			}

			void Enemy::update()
			{
				CheckPlayerPosition();

				if(isPlayerOnSighet)
					ShootPlayer();
			}

			void Enemy::CheckPlayerPosition()
			{
				auto& player = engine::Engine::getInstance().getGameplayManager().getPlayer();

				if (player.hasJustMoved())
				{
					auto& playerPosition = player.getPosition();
					auto& myPosition = getPosition();

					auto offset = myPosition - playerPosition;
					offset /= gameplay::Manager::CELL_SIZE;
					float distance2 = offset.x * offset.x + offset.y * offset.y;

					if (distance2 <= visionRadius * visionRadius)
					{
						isPlayerOnSighet = true;
					}
					else
					{
						isPlayerOnSighet = false;
						shootDelayCounter = 0;
					}
				}
			}

			void Enemy::ShootPlayer()
			{
				if (shootDelayCounter < shootDelay)
				{
					++shootDelayCounter;
				}
				else
				{
					engine::Engine::getInstance().getGameplayManager().gameOver();
				}
			}

			void Enemy::loadArchetype()
			{
				std::shared_ptr<SpriteRenderer> spriteR = std::make_shared<SpriteRenderer>();
				spriteR->SetActor(shared_from_this());
				components.push_back(spriteR);
				engine::Engine::getInstance().getGraphicsManager().spriteRenderers.push_back(spriteR);

				std::stringstream filename;
				filename << "archetypes/" << archetypeName << ".xml";

				pugi::xml_document doc;
				pugi::xml_parse_result result = doc.load_file(filename.str().c_str());

				if (result)
				{
					assert(!doc.empty());
					auto xmlArchetype = doc.first_child();

					std::string shapeListName = xmlArchetype.child_value("shapelist");

					assert(spriteR->shapeList.load(shapeListName));

					visionRadius = std::stof(xmlArchetype.child_value("vision_radius"));
					assert(visionRadius > 0.f);

					shootDelay = std::stoi(xmlArchetype.child_value("shoot_delay"));
					assert(shootDelay >= 0);
				}
				else
				{
					std::cerr << "Archetype [" << archetypeName << "] parsed with errors." << std::endl;
					std::cerr << "Error description: " << result.description() << std::endl;
					std::cerr << "Error offset: " << result.offset << std::endl;
				}
			}
		}
	}
}
