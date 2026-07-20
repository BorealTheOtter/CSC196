#include "pch.h"
#include "Scene.h"

namespace sr {
	void Scene::Update(float dt,float width, float height)
	{
		for (Actor* actor : m_actors)
		{
			actor->Update(dt, width, height);
		}
	}

	void Scene::Draw(const Renderer& renderer)
	{
		for (Actor* actor : m_actors)
		{
			actor->Draw(renderer);
		}
	}
}
