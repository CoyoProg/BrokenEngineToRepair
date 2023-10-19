#include "Actor.hpp"
#include <engine/gameplay/Component.hpp>

namespace engine
{
	namespace gameplay
	{
		Actor::~Actor()
		{
			int componentCount = components.size();
			for (int i = 0; i < componentCount; i++)
			{
				delete components[i];
			}
			components.clear();
		}

		const sf::Vector2f & Actor::getPosition() const
		{
			return _position;
		}

		void Actor::setPosition(const sf::Vector2f &newPosition)
		{
			_position = newPosition;
			updateTransform();
		}

		float Actor::getRotation() const
		{
			return _rotation;
		}

		void Actor::setRotation(float newRotation)
		{
			_rotation = newRotation;
			updateTransform();
		}

		const sf::Transform & Actor::getTransform() const
		{
			return _transform;
		}

		void Actor::updateTransform()
		{
			_transform = sf::Transform::Identity;
			_transform.translate(_position);
			_transform.rotate(_rotation);
		}
	}
}
