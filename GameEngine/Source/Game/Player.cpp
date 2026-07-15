#include "Player.h"
#include "../Engine/Engine.h"

void Player::Update(float dt, const float width, const float height)
{
    sr::Vector2 vel{ 0.0f, 0.0f };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) { vel.y -= m_speed; };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) { vel.x -= m_speed; };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) { vel.y += m_speed; };
    if (sr::engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) { vel.x += m_speed; };

    SetVelocity(vel);
    Actor::Update(dt, width, height);
}

void Player::Draw(const sr::Renderer& renderer) const
{
	Actor::Draw(renderer);
}
