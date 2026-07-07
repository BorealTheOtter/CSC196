#include "Engine.h"


int main()
{
    //INITIALIZE
    sr::Renderer renderer;
	sr::Input input;

    int width = 1920;
    int height = 1080;
    
    renderer.Initialize("Game Engine", width, height);
	input.Initialize();

    sr::Vector2 vel{ 0.5f, 0.0f };
	std::vector<sr::Vector2> v;

	
	

	for (size_t i = 0; i < 3000; ++i) {
        v.push_back(sr::Vector2{ sr::RandomFloat((float)width), sr::RandomFloat((float)height) });
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
            if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
                quit = true;
            }
        }

		input.Update();

        //RENDER
		renderer.SetColor(0, 0, 0);
        renderer.Clear();
      
        if (input.GetKeyPressed(SDL_SCANCODE_SPACE)) { std::cout << "Pressed" << std::endl; }
        if (input.GetKeyDown(SDL_SCANCODE_SPACE)) { std::cout << "Down" << std::endl; }
        if (input.GetKeyReleased(SDL_SCANCODE_SPACE)) { std::cout << "" << std::endl; }
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

			//v[i] = v[i] + vel;
            renderer.DrawPoint((float)(v[i].x), (float)(v[i].y));
        }

        renderer.SetColor(255,255,255);
		renderer.DrawFillRect(input.GetMousePos().x - 25, input.GetMousePos().y - 25, 50.0f, 50.0f);

        renderer.Present();
    }
    //SHUTDOWN
    renderer.Quit();

    return 0;

}