#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>
#include "graphics/Window.h"

namespace engine
{
	std::unique_ptr <Engine> Engine::instance = nullptr;

	Engine::Engine()
	{
		init();
	}

	Engine::~Engine()
	{

	}

	void Engine::init()
	{
		mGraphicsManager = std::make_unique<graphics::Manager>();
		mPhysicsManager = std::make_unique<physics::Manager>();
		mGameplayManager = std::make_unique<gameplay::Manager>();
		mInputManager = std::make_unique<input::Manager>();
	}

	void Engine::loadConfiguration()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("configuration.xml");

		if (result)
		{
			assert(!doc.empty());
			auto configuration = doc.first_child();
			startMap = configuration.child_value("start_map");
		}
		else
		{
			std::cerr << "Configuration parsed with errors." << std::endl;
			std::cerr << "Error description: " << result.description() << std::endl;
			std::cerr << "Error offset: " << result.offset << std::endl;
		}
	}

	void Engine::run()
	{
		running = true;

		engine::Engine::getInstance().getGameplayManager().loadMap(startMap);

		sf::Clock clock;
		while (running)
		{
			Update(clock);
		}
	}

	void Engine::Update(sf::Clock& clock)
	{
		mInputManager->clear();

		sf::Event event;
		while (mGraphicsManager->getWindow().getWindow().pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Engine::getInstance().exit();
				break;

			case sf::Event::LostFocus:
				mInputManager->setIsEnable(false);
				break;

			case sf::Event::GainedFocus:
				mInputManager->setIsEnable(true);
				break;

			case sf::Event::KeyPressed:
				mInputManager->onKeyPressed(event.key);
				break;

			case sf::Event::KeyReleased:
				mInputManager->onKeyReleased(event.key);
				break;

			default:
				break;
			}
		}

		/** TO DO :
		* 2- KILL DEPENDANCE
		* (create interface ?)
		*
		* 3- Single Responsability principle
		* (graphics manager ne doit pas gerer les inputs)
		*/

		deltaTime = clock.restart().asSeconds();

		mPhysicsManager->update();
		mGameplayManager->update();
		mGraphicsManager->update();

		mGraphicsManager->draw();

		mGraphicsManager->display();
	}

	float Engine::getDeltaTime() const
	{
		return deltaTime;
	}

	void Engine::exit()
	{
		running = false;
	}

	Engine &Engine::getInstance()
	{
		if (!instance)
			instance = std::make_unique<Engine>();

		return *instance;
	}
}
