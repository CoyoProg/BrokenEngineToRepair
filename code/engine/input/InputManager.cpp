#include "engine/input/InputManager.hpp"
#include <iterator>
#include <iostream>

namespace engine
{
	namespace input
	{
		bool Manager::isKeyPressed(sf::Keyboard::Key key) const
		{
			if (!mIsEnable)
				return false;
		
			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::isKeyJustPressed(sf::Keyboard::Key key) const
		{
			if (!mIsEnable)
				return false;

			return justPressedKeys.find(key) != std::end(justPressedKeys);
		}

		bool Manager::isKeyJustReleased(sf::Keyboard::Key key) const
		{
			if (!mIsEnable)
				return false;

			return justReleasedKeys.find(key) != std::end(justReleasedKeys);
		}

		void Manager::clear()
		{
			justPressedKeys.clear();
			justReleasedKeys.clear();
		}

		void Manager::onKeyPressed(const sf::Event::KeyEvent& event)
		{
			justPressedKeys.insert(event.code);
		}

		void Manager::onKeyReleased(const sf::Event::KeyEvent& event)
		{
			justReleasedKeys.insert(event.code);
		}
	}
}
