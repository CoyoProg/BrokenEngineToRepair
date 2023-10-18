#pragma once

#include <string>
#include "graphics/GraphicsManager.hpp"
#include "physics/PhysicsManager.hpp"
#include "input/InputManager.hpp"
#include "gameplay/GameplayManager.hpp"

class Manager;

namespace engine
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		void init();
		void loadConfiguration();

		void run();
		void Update(sf::Clock& clock);
		float getDeltaTime() const;

		void exit();

		graphics::Manager& getGraphicsManager() { return *mGraphicsManager; }
		gameplay::Manager& getGameplayManager() { return *mGameplayManager; }
		input::Manager& getInputManager() { return *mInputManager; }
		physics::Manager& getPhysicsManager() { return *mPhysicsManager; }

		static Engine &getInstance();

	private:
		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;

		graphics::Manager* mGraphicsManager;
		physics::Manager* mPhysicsManager;
		gameplay::Manager* mGameplayManager;
		input::Manager* mInputManager;

		static Engine *instance;
	};
}
