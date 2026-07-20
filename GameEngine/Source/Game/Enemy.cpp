#include "Enemy.h"
#include "../Engine/Engine.h"

void Enemy::Update(float dt, const float width, const float height)
{
    float thrust = 0.0f;

    float rotate = 0.0f;


    sr::Vector2 vel{ 1,0 };

    SetRotation(m_transform.rotation + rotate * dt);
    vel = vel.Rotate(m_transform.rotation * sr::math::DEG_TO_RAD) * thrust;
    AddVelocity(vel * dt);
    Actor::Update(dt, width, height);
}

void Enemy::Draw(const sr::Renderer& renderer) const
{
    Actor::Draw(renderer);
}