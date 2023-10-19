#pragma once

#include <set>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <engine/gameplay/Actor.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player;
		}

		class Manager
		{
		public:
			void update();

			void gameOver();

			sf::Vector2f getViewCenter() const;

			void loadMap(const std::string &mapName);
			void loadNextMap();

			const entities::Player &getPlayer() const;

			static const float CELL_SIZE;
		private:
			std::set<Actor *> entities;
			entities::Player *playerEntity{};

			// Map
			std::string currentMapName;
			std::string nextMapName;
			int rows{ 0 };
			int columns{ 0 };

			bool preventMapCompletion{ false };
			bool nextMapRequested{ false };
			bool resetMapRequested{ false };
		};
	}
}
