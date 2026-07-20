#include "Player.h"
#include "../Engine/Engine.h"

void Player::Update(float dt, const float width, const float height)
{
    float thrust = 0.0f;
    float drag = 10.0f;
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) { thrust += m_speed; };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) { thrust -= m_speed; };

    float rotate = 0.0f;
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) { rotate = -180.0f; };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) { rotate = 180.0f; };

    sr::Vector2 vel{ 1,0 };
  
    SetRotation(m_transform.rotation + rotate * dt);
    vel = vel.Rotate(m_transform.rotation * sr::math::DEG_TO_RAD) * thrust;
    AddVelocity(vel * dt);
    Actor::Update(dt, width, height);
}

void Player::Draw(const sr::Renderer& renderer) const
{
	Actor::Draw(renderer);
}
