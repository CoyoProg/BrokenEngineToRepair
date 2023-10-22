#pragma once

#include <SFML/Graphics/Transform.hpp>
#include <vector>
#include <memory>

namespace engine
{
	class Component;
	namespace gameplay
	{
		class Actor : public std::enable_shared_from_this<Actor>
		{
		public:
			virtual ~Actor();

			virtual void init() = 0;
			virtual void update() = 0;

			const sf::Vector2f& getPosition() const;
			void setPosition(const sf::Vector2f& newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform& getTransform() const;
			std::vector<std::shared_ptr<Component>> components;

		private:
			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;

			void updateTransform();
		};
	}
}
