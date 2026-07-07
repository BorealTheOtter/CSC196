#pragma once
#include "Vector2.h"

#include <vector>

namespace sr 
{
	class Input 
	{
	public:
		enum MouseButton
		{
			LEFT = 1,
			MIDDLE = 2,
			RIGHT = 3
		};


	public:
		bool Initialize();
		void Shutdown();

		void Update();

		bool GetKeyDown(int key) const { return m_keyStates[key]; }
		bool GetPrevKeyDown(int key) const { return m_prevKeyStates[key]; }
		bool GetKeyPressed(int key) const { return m_keyStates[key] && !m_prevKeyStates[key]; }
		bool GetKeyReleased(int key) const { return !m_keyStates[key] && m_prevKeyStates[key]; }

		sr::Vector2 GetMousePos() const { return m_mousePos; }
		bool GetMouseButtonDown(MouseButton button) const { return false; }

	private:
		//keyboard
		std::vector<bool> m_keyStates;
		std::vector<bool> m_prevKeyStates;
		
		//mouse
		uint32_t m_buttonStates = 0;
		uint32_t m_prevButtonStates = 0;

		sr::Vector2 m_mousePos;
	};

}