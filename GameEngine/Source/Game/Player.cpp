#include "Player.h"
#include "Bullet.h"
#include "Assets.h"
#include "../Engine/Engine.h"

void Player::Update(float dt, const float width, const float height)
{
    float thrust = 0.0f;
    float drag = 10.0f;
    if (sr::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_W)) { thrust += m_speed; };
    if (sr::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_S)) { thrust -= m_speed; };

    float rotate = 0.0f;
    if (sr::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_A)) { rotate = -180.0f; };
    if (sr::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_D)) { rotate = 180.0f; };

    sr::Vector2 vel{ 1,0 };
  
    SetRotation(m_transform.rotation + rotate * dt);
    vel = vel.Rotate(m_transform.rotation * sr::math::DEG_TO_RAD) * thrust;
    AddVelocity(vel * dt);

    if (sr::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {
        BulletDesc bd;
        bd.name = "Enemy";
        bd.model = assets::bulletModel;
        bd.transform = m_transform;
        bd.speed = 1000.0f;
        bd.damping = 1.0f;
    }

    Actor::Update(dt, width, height);
}

void Player::Draw(const sr::Renderer& renderer) const
{
	Actor::Draw(renderer);
}
