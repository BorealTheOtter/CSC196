#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"

#include <fmod.hpp>

using namespace sr;


int main()
{
    // get current working directory
    std::cout << "Directory Operations:\n";
    std::cout << "Working directory: " << sr::GetWorkingDirectory() << "\n";

    // set working directory (current working directory + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    sr::SetWorkingDirectory("Assets");
    std::cout << "New directory: " << sr::GetWorkingDirectory() << "\n\n";

    // get filenames in the working directory
    std::cout << "Files in Directory:\n";
    auto filenames = sr::GetFilesInDirectory(sr::GetWorkingDirectory());
    for (const auto& filename : filenames)
    {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // get filename info
    if (!filenames.empty())
    {
        // get filename
        std::string str = sr::GetFilename(filenames[0]);
        std::cout << "Filename: " << str << "\n";

        // get extension
        str = sr::GetFileExtension(filenames[0]);
        std::cout << "Extension: " << str << "\n";

        // get filename no extension
        str = sr::GetFilenameNoExtension(filenames[0]);
        std::cout << "Filename No Extension: " << str << "\n\n";
    }

    // read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    if (sr::ReadTextFile("test.txt", str))
    {
        std::cout << str << "\n";
    }

    // write to text file
    std::cout << "Text File Writing:\n";
    sr::WriteTextFile("test.txt", "Hello, World!", true);
    if (sr::ReadTextFile("test.txt", str))
    {
        std::cout << str << "\n";
    }

    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    //INITIALIZE
    Engine::Get().Initialize();

    Scene scene{};

    

    Mesh mesh = { {Vector2 {0,1}, Vector2{0,-1}, Vector2 {-1.5f,-2}, Vector2{-0.5f,0}, Vector2 {-1.5f,2}, Vector2 {0,1}}, Color{1.0f,1.0f,1.0f} };

    PlayerDesc pd;
    pd.name = "Player";
    pd.model = assets::playerModel;
    pd.transform = Transform{ Vector2{(float)(Engine::Get().GetScreen().x / 2), (float)(Engine::Get().GetScreen().y / 2)}, 0, 20 };
    pd.speed = 400.0f;
    pd.damping = 1.0f;
 
    Player* player = new Player{pd};

    EnemyDesc ed;
    ed.name = "Enemy";
    ed.model = assets::enemyModel;
    ed.transform = Transform{ Vector2{RandomFloat(Engine::Get().GetScreen().x), RandomFloat(Engine::Get().GetScreen().y)}, 0, 10 };
    ed.speed = 300.0f;
    ed.damping = 1.1f;
    

    

    
    scene.AddActor(player);

    for (int i = 0; i < 1000; ++i) {
        ed.transform = Transform{ Vector2{RandomFloat(Engine::Get().GetScreen().x), RandomFloat(Engine::Get().GetScreen().y)}, 0, 10 };
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
            if (Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
                quit = true;
            }
        }

        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_1)) { audio->playSound(sounds[0], nullptr, false, nullptr); }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_2)) { audio->playSound(sounds[1], nullptr, false, nullptr); }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_3)) { audio->playSound(sounds[2], nullptr, false, nullptr); }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_4)) { audio->playSound(sounds[3], nullptr, false, nullptr); }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_5)) { audio->playSound(sounds[4], nullptr, false, nullptr); }
        if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_6)) { audio->playSound(sounds[5], nullptr, false, nullptr); }

        Engine::Get().GetInput().Update();
        Engine::Get().GetTime().Tick();

        float dt = Engine::Get().GetTime().GetDeltaTime();

        scene.Update(dt, Engine::Get().GetScreen().x, Engine::Get().GetScreen().y);

            //RENDER
            Engine::Get().GetRenderer().SetColor(0.0f, 0.0f, 0.0f);
            Engine::Get().GetRenderer().Clear();

            Engine::Get().GetRenderer().SetColor(1.0f, 1.0f, 1.0f);
            

            scene.Draw(Engine::Get().GetRenderer());


            Engine::Get().GetRenderer().Present();
        }
        //SHUTDOWN
    Engine::Get().Shutdown();

        return 0;


    }

