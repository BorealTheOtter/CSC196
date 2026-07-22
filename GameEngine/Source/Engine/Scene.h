#pragma once
#include <vector>

#include "Actor.h"

namespace sr {
	class Actor;
	
	class Scene {
	public:
		void AddActor(Actor* actor);

		void Update(float dt, float width, float height);
		void Draw(const class Renderer& renderer);
	private:
		std::vector<Actor*> m_actors;
	};
}