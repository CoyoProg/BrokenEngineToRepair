#pragma once

#include <engine/gameplay/Actor.hpp>


namespace engine
{
	class Component
	{
	public:
		virtual ~Component();

		void SetActor(gameplay::Actor* actor_) 
		{
			actor = actor_;
		}

	protected:
		gameplay::Actor* actor = nullptr;
	};
}
