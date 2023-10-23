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
			void startGame(std::string startMap);
			void update();

			/** Win Loose */
			void loadNextMap();
			void gameOver();

			sf::Vector2f getViewCenter() const;
			const entities::Player &getPlayer() const;

			static const float CELL_SIZE;
		private:
			std::set<std::shared_ptr<Actor>> entities;
			std::shared_ptr <entities::Player> playerEntity{};

			// Map
			std::string currentMapName;
			std::string nextMapName;
			int rows{ 0 };
			int columns{ 0 };

			bool preventMapCompletion{ false };
			bool nextMapRequested{ false };
			bool resetMapRequested{ false };

			void CheckMapCompletion();
			void loadMap(const std::string& mapName);
		};
	}
}
