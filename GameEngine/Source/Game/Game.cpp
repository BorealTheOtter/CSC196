#include "SDL3/SDL.h"
#include "Engine.h"

#include <iostream>


int main()
{
    sr::Renderer renderer;
    
    renderer.Initialize("Game Engine", 1920, 1080);

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

		renderer.SetColor(0, 0, 0);
		renderer.Clear();
        
        

        
      
        


        for (int i = 0; i < 10; ++i) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
			renderer.DrawLine(rand() % 1920, rand() % 1080, rand() % 1920, rand() % 1080);
        }

        for (int i = 0; i < 20; ++i) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
            renderer.DrawPoint(rand() % 1920, rand() % 1080);
        }

        for (int i = 0; i < 5; ++i) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
            renderer.DrawFillRect(rand() % 1920, rand() % 1080, rand() % 960, rand() % 540);
        }

        renderer.Present();
    }

    renderer.Quit();

    return 0;

}