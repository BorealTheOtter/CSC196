#include "Engine.h"


int main()
{
    //INITIALIZE
    sr::Renderer renderer;
	sr::Input input;
    sr::Time time;

    int width = 1920;
    int height = 1080;
    
    renderer.Initialize("Game Engine", width, height);
	input.Initialize();

    
	std::vector<sr::Vector2> points;

    sr::Vector2 pos{ (float)(width/2), (float)(height/2) };

	for (size_t i = 0; i < 3000; ++i) {
        points.push_back(sr::Vector2{ sr::RandomFloat((float)width), sr::RandomFloat((float)height) });
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
        time.Tick();
 
	
        
		float dt = time.GetDeltaTime();
      
  //      if (input.GetKeyPressed(SDL_SCANCODE_SPACE)) { std::cout << "Pressed" << std::endl; }
  //      if (input.GetKeyDown(SDL_SCANCODE_SPACE)) { std::cout << "Down" << std::endl; }
  //      if (input.GetKeyReleased(SDL_SCANCODE_SPACE)) { std::cout << "Released" << std::endl; }

  //      if (input.GetMousePressed(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Pressed" << std::endl; }
  //      if (input.GetMouseDown(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Down" << std::endl; }
  //      if (input.GetMouseReleased(sr::Input::MouseButton::LEFT)) { std::cout << "Mouse Released" << std::endl; }

        
        
		if (input.GetMouseDown(sr::Input::MouseButton::LEFT)) {
			points.push_back(input.GetMousePos());
		}
  
        sr::Vector2 vel{ 0.0f, 0.0f };
        if (input.GetKeyDown(SDL_SCANCODE_W)) { vel.y -= 400.0f; };
        if (input.GetKeyDown(SDL_SCANCODE_A)) { vel.x -= 400.0f; };
        if (input.GetKeyDown(SDL_SCANCODE_S)) { vel.y += 400.0f; };
        if (input.GetKeyDown(SDL_SCANCODE_D)) { vel.x += 400.0f; };

        pos += (vel * dt);
  
        //RENDER
        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        for (int i = 0; i < points.size(); ++i) {
            renderer.SetColor(sr::RandomInt(256), sr::RandomInt(256), sr::RandomInt(256));
            renderer.DrawPoint((float)(points[i].x), (float)(points[i].y));
        }

        renderer.SetColor(255,255,255);
	    renderer.DrawFillRect(pos.x, pos.y, 50.0f, 50.0f);

        renderer.Present();
    }
    //SHUTDOWN
    renderer.Quit();

    return 0;

}