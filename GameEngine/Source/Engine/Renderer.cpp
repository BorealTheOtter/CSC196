#include "pch.h"
#include "Renderer.h"
#include <SDL3/SDL.h>

#include <iostream>

namespace sr
{
    bool Renderer::Initialize(const char* name, int width, int height)
    {
        SDL_Init(SDL_INIT_VIDEO);

        m_window = SDL_CreateWindow(name, width, height, 0);
        if (m_window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, NULL);
        if (m_renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        return true;
    }

    void Renderer::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    }

	void Renderer::Clear()
	{
		SDL_RenderClear(m_renderer);
	}

    void Renderer::DrawPoint(float x, float y)
    {
        SDL_RenderPoint(m_renderer, x, y);
    }

    void Renderer::DrawFillRect(float x, float y, float width, float height)
    {
        SDL_FRect rect{ x, y, width, height };
        SDL_RenderFillRect(m_renderer, &rect);
    }

    void Renderer::DrawRect(float x, float y, float width, float height)
    {
		SDL_FRect rect{ x, y, width, height };
		SDL_RenderRect(m_renderer, &rect);
	
    }

    void Renderer::DrawLine(float x1, float y1, float x2, float y2)
    {
		SDL_RenderLine( m_renderer, x1, y1, x2, y2 );
    }

    void Renderer::Present()
    {
        SDL_RenderPresent(m_renderer);
    }

    void Renderer::DebugText(float x, float y, const char* text)
    {
        SDL_RenderDebugText(m_renderer, x, y, text);
    }

    void Renderer::Quit()
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }
   
}
