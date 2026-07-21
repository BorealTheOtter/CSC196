#include "Engine.h"
#include "Player.h"
#include "Enemy.h"

#include <fmod.hpp>

using namespace sr;


int main()
{
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    //INITIALIZE
    engine.Initialize();

    Scene scene{};

    

    Mesh mesh = { {Vector2 {0,1}, Vector2{0,-1}, Vector2 {-1.5f,-2}, Vector2{-0.5f,0}, Vector2 {-1.5f,2}, Vector2 {0,1}}, Color{1.0f,1.0f,1.0f} };

    std::vector<Mesh> playerMeshes = { mesh, Mesh{ {Vector2{1.5f, 0}, Vector2 {0,1}, Vector2{0,-1}, Vector2{1.5f, 0}}, Color{0.0f,1.0f,1.0f}} };

    std::vector<Mesh> enemyMeshes = { mesh, Mesh{ {Vector2{1.5f, 0}, Vector2 {0,1}, Vector2{0,-1}, Vector2{1.5f, 0}}, Color{1.0f,0.0f,0.0f}} };

    Model playerModel = playerMeshes;
    Model enemyModel = enemyMeshes;

    PlayerDesc pd;
    pd.name = "Player";
    pd.model = playerModel;
    pd.transform = Transform{ Vector2{(float)(engine.GetScreen().x / 2), (float)(engine.GetScreen().y / 2)}, 0, 20 };
    pd.speed = 400.0f;
 
    Player* player = new Player{pd};

    EnemyDesc ed;
    ed.name = "Enemy";
    ed.model = enemyModel;
    ed.transform = Transform{ Vector2{RandomFloat(engine.GetScreen().x), RandomFloat(engine.GetScreen().y)}, 0, 10 };
    ed.speed = 300.0f;
    

    

    
    scene.AddActor(player);

    for (int i = 0; i < 10; ++i) {
        ed.transform = Transform{ Vector2{RandomFloat(engine.GetScreen().x), RandomFloat(engine.GetScreen().y)}, 0, 10 };
        scene.AddActor(new Enemy{ ed });
    }

    std::vector<FMOD::Sound*> sounds;

    FMOD::Sound* sound = nullptr;
    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);


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

        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_1)) { audio->playSound(sounds[0], nullptr, false, nullptr); }
        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_2)) { audio->playSound(sounds[1], nullptr, false, nullptr); }
        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_3)) { audio->playSound(sounds[2], nullptr, false, nullptr); }
        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_4)) { audio->playSound(sounds[3], nullptr, false, nullptr); }
        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_5)) { audio->playSound(sounds[4], nullptr, false, nullptr); }
        if (engine.GetInput().GetKeyPressed(SDL_SCANCODE_6)) { audio->playSound(sounds[5], nullptr, false, nullptr); }

        engine.GetInput().Update();
        engine.GetTime().Tick();

        float dt = engine.GetTime().GetDeltaTime();

        scene.Update(dt, engine.GetScreen().x, engine.GetScreen().y);

            //RENDER
            engine.GetRenderer().SetColor(0.0f, 0.0f, 0.0f);
            engine.GetRenderer().Clear();

            engine.GetRenderer().SetColor(1.0f, 1.0f, 1.0f);
            

            scene.Draw(engine.GetRenderer());


            engine.GetRenderer().Present();
        }
        //SHUTDOWN
    engine.Shutdown();

        return 0;


    }

