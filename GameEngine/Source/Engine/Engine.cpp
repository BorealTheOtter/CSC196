#include "pch.h"
#include "framework.h"
#include <iostream>
#include "Engine.h"

namespace sr {
	

	bool Engine::Initialize()
	{
		m_renderer.Initialize("Game Engine", (int)m_screen.x, (int)m_screen.y);
		m_input.Initialize();
		m_time.Reset();

		return true;
	}
	void Engine::Shutdown()
	{
		m_renderer.Quit();
	}
	void Engine::Update()
	{}
}