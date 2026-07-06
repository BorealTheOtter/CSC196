#include "Engine.h"


int main()
{
    //INITIALIZE
    sr::Renderer renderer;

    int width = 1920;
    int height = 1080;
    
    renderer.Initialize("Game Engine", width, height);

    //std::cout << sizeof(sr::Vector2) << std::endl;

    sr::Vector2 vel{ 0.5f, 0.0f };
	std::vector<sr::Vector2> v;
	

	for (size_t i = 0; i < 3000; ++i) {
        v.push_back(sr::Vector2{ sr::RandomFloat(width), sr::RandomFloat(height) });
	}
    
    //MAIN LOOP
    bool quit = false;
    while (!quit) {

        //UPDATE
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //RENDER
		renderer.SetColor(0, 0, 0);
        renderer.Clear();
      
        
        //for (int i = 0; i < 5; ++i) {
        //    renderer.SetColor(sr::RandomInt(256), sr::RandomInt(256), sr::RandomInt(256));
        //    renderer.DrawFillRect((float)(sr::RandomInt(1920)), (float)(sr::RandomInt(1080)), (float)(sr::RandomInt(960)), (float)(sr::RandomInt(540)));
        //}

        //for (int i = 0; i < 10; ++i) {
        //    renderer.SetColor(sr::RandomInt(256), sr::RandomInt(256), sr::RandomInt(256));
		//	renderer.DrawLine((float)(sr::RandomInt(1920)), (float)(sr::RandomInt(1080)), (float)(sr::RandomInt(1920)), (float)(sr::RandomInt(1080)));
        //}

        for (int i = 0; i < v.size(); ++i) {
            renderer.SetColor(sr::RandomInt(256), sr::RandomInt(256), sr::RandomInt(256));

			v[i] = v[i] + vel;
            renderer.DrawPoint((float)(v[i].x), (float)(v[i].y));
        }

        

        renderer.Present();
    }
    //SHUTDOWN
    renderer.Quit();

    return 0;

}