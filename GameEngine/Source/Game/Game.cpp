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
        
        

        
        renderer.SetColor(0, 255, 0);
        renderer.DrawFillRect(270, 190, 200, 200);


        renderer.SetColor(255, 255, 255);

        renderer.DebugText(50, 50, "Hello World!");

        renderer.Present();
    }

    renderer.Quit();

    return 0;

}