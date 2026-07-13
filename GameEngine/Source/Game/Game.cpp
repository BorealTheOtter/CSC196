#include "Engine.h"

using namespace sr;

int screenWidth = 1920;
int screenHeight = 1080;

struct Transform
{
	Vector2 pos;
	float rotation;
    float scale;
};

class Actor 
{
public:
    Actor(const Transform& t) : m_transform{t} {}

	void Update(float dt) 
    {
        m_transform.pos += (m_velocity * dt);

        m_transform.pos.x = math::Wrap(m_transform.pos.x, 0.0f, (float)screenWidth);
        m_transform.pos.y = math::Wrap(m_transform.pos.y, 0.0f, (float)screenHeight);
	}

    void Draw(const Renderer& renderer) const {
		renderer.SetColor(255, 255, 255);
        renderer.DrawFillRect(m_transform.pos.x - (m_transform.scale * 0.5f), m_transform.pos.y - (m_transform.scale * 0.5f), 50.0f, 50.0f);
    }

	const Transform& getTransform() const { return m_transform; }

	void setPosition(const Vector2& pos) { m_transform.pos = pos; }
	void setRotation(float rotation) { m_transform.rotation = rotation; }
	void setScale(float scale) { m_transform.scale = scale; }

	const Vector2& getVelocity() const { return m_velocity; }
	void setVelocity(const Vector2& velocity) { m_velocity = velocity; }

protected:
	Transform m_transform;
    Vector2 m_velocity{ 0,0 };
};


int main()
{
    //INITIALIZE
    Renderer renderer;
    Input input;
    Time time;

    //Actor player{ Transform{ Vector2{(float)(screenWidth / 2), (float)(screenHeight / 2)}, 0, 50 } };

    renderer.Initialize("Game Engine", screenWidth, screenHeight);
    input.Initialize();


    std::vector<Vector2> points;

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


              //handle clicking points
        if (input.GetMousePressed(sr::Input::MouseButton::LEFT)) {
            if (points.empty()) {
                points.push_back(input.GetMousePos());
            }
            else {
                sr::Vector2 v = points.back() - input.GetMousePos();
                if (v.Length() > 10.0f) {
                    points.push_back(input.GetMousePos());
                }
            }
        }

        //handle click and drag
        if (input.GetMouseDown(sr::Input::MouseButton::LEFT)) {
            sr::Vector2 v = points.back() - input.GetMousePos();
            if (v.Length() > 10.0f) {
                points.push_back(input.GetMousePos());
            }
        }

        //handle undo
        if (input.GetKeyDown(SDL_SCANCODE_LCTRL) && input.GetKeyPressed(SDL_SCANCODE_Z))
        {
            if (!points.empty()) { points.pop_back(); }
        }




            //sr::Vector2 vel{ 0.0f, 0.0f };
            //if (input.GetKeyDown(SDL_SCANCODE_W)) { vel.y -= 400.0f; };
            //if (input.GetKeyDown(SDL_SCANCODE_A)) { vel.x -= 400.0f; };
            //if (input.GetKeyDown(SDL_SCANCODE_S)) { vel.y += 400.0f; };
            //if (input.GetKeyDown(SDL_SCANCODE_D)) { vel.x += 400.0f; };

            //player.setVelocity(vel);
            //player.Update(time.GetDeltaTime());


            //RENDER
            renderer.SetColor(0, 0, 0);
            renderer.Clear();

            renderer.SetColor(255, 255, 255);
            if (points.size() > 1) {
                for (int i = 0; i < (int)points.size() - 1; ++i) {
                    renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
                }
            }
            else if (points.size() == 1) {
                renderer.DrawRect(points[0].x - 5, points[0].y - 5, 10, 10);
            }

            //player.Draw(renderer);


            renderer.Present();
        }
        //SHUTDOWN
        renderer.Quit();

        return 0;


    }

