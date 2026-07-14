#include "Engine.h"

using namespace sr;

int screenWidth = 1920;
int screenHeight = 1080;

int main()
{
    //INITIALIZE
    Renderer renderer;
    Input input;
    Time time;

    Actor player{ Transform{ Vector2{(float)(screenWidth / 2), (float)(screenHeight / 2)}, 0, 50 } };

    renderer.Initialize("Game Engine", screenWidth, screenHeight);
    input.Initialize();


    

    //MAIN LOOP
    bool quit = false;
    while (!quit) {

        //UPDATE
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
                quit = true;
            }
        }

        input.Update();
        time.Tick();




        //      if (input.GetKeyPressed(SDL_SCANCODE_SPACE)) { std::cout << "Pressed" << std::endl; }
        //      if (input.GetKeyDown(SDL_SCANCODE_SPACE)) { std::cout << "Down" << std::endl; }
        //      if (input.GetKeyReleased(SDL_SCANCODE_SPACE)) { std::cout << "Released" << std::endl; }

        //      if (input.GetMousePressed(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Pressed" << std::endl; }
        //      if (input.GetMouseDown(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Down" << std::endl; }
        //      if (input.GetMouseReleased(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Released" << std::endl; }






            sr::Vector2 vel{ 0.0f, 0.0f };
            if (input.GetKeyDown(SDL_SCANCODE_W)) { vel.y -= 400.0f; };
            if (input.GetKeyDown(SDL_SCANCODE_A)) { vel.x -= 400.0f; };
            if (input.GetKeyDown(SDL_SCANCODE_S)) { vel.y += 400.0f; };
            if (input.GetKeyDown(SDL_SCANCODE_D)) { vel.x += 400.0f; };

            player.setVelocity(vel);
            player.Update(time.GetDeltaTime(), (float)renderer.GetWidth(), (float)renderer.GetHeight());


            //RENDER
            renderer.SetColor(0, 0, 0);
            renderer.Clear();

            renderer.SetColor(255, 255, 255);
            

            player.Draw(renderer);


            renderer.Present();
        }
        //SHUTDOWN
        renderer.Quit();

        return 0;


    }

