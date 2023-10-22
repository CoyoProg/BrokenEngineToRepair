#pragma once

#include <engine/gameplay/Actor.hpp>


namespace engine
{
	class Component
	{
	public:
		virtual ~Component();

		void SetActor(std::shared_ptr<gameplay::Actor> actor_) 
		{
			actor = actor_;
		}

	protected:
		std::shared_ptr <gameplay::Actor> actor = nullptr;
	};
}
