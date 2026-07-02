#pragma once
#include <SDL3/SDL.h>

namespace sr
{
	class Renderer
	{
	public:
		bool Initialize(const char* name, int width, int height);
		void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
		void Clear();
		void DrawPoint(float x, float y);
		void DrawFillRect(float x, float y, float width, float height); 
		void DrawRect(float x, float y, float width, float height);
		void DrawLine(float x1, float y1, float x2, float y2);
		void Present();
		void DebugText(float x, float y, const char* text);
		void Quit();

	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	};
}

