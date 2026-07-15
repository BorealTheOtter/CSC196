#include "Engine.h"
#include "Player.h"

using namespace sr;

int screenWidth = 1920;
int screenHeight = 1080;

int main()
{
    //INITIALIZE
    engine.Initialize();

    Mesh mesh = { {Vector2 {1.5f,0}, Vector2{-1.5f,2}, Vector2 {-0.5f,0}, Vector2{-1.5f,-2}, Vector2 {1.5f,0}}, Color{1.0f,1.0f,1.0f} };
 
    Player player{ Transform{ Vector2{(float)(screenWidth / 2), (float)(screenHeight / 2)}, 0, 20 }, std::vector<Mesh> {mesh}, 400.0f };
    //MAIN LOOP
    bool quit = false;
    while (!quit) {

        //UPDATE
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            if (engine.GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
                quit = true;
            }
        }

        engine.GetInput().Update();
        engine.GetTime().Tick();

        player.SetRotation(player.GetTransform().rotation + (90.0f * engine.GetTime().GetDeltaTime()));

        player.Update(engine.GetTime().GetDeltaTime(), engine.GetScreen().x, engine.GetScreen().y);

            //RENDER
            engine.GetRenderer().SetColor(0.0f, 0.0f, 0.0f);
            engine.GetRenderer().Clear();

            engine.GetRenderer().SetColor(1.0f, 1.0f, 1.0f);
            

            player.Draw(engine.GetRenderer());


            engine.GetRenderer().Present();
        }
        //SHUTDOWN
    engine.Shutdown();

        return 0;


    }

