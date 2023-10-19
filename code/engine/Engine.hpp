#pragma once

#include <string>
#include "graphics/GraphicsManager.hpp"
#include "physics/PhysicsManager.hpp"
#include "input/InputManager.hpp"
#include "gameplay/GameplayManager.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>

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

		std::unique_ptr<graphics::Manager> mGraphicsManager = nullptr;
		std::unique_ptr < physics::Manager> mPhysicsManager = nullptr;
		std::unique_ptr < gameplay::Manager> mGameplayManager = nullptr;
		std::unique_ptr < input::Manager> mInputManager = nullptr;

		static Engine *instance;
	};
}
