#include "Enemy.h"
#include "Player.h"
#include "../Engine/Engine.h"

void Enemy::Update(float dt, const float width, const float height)
{
    Player* player = m_scene->GetActorByName<Player>("Player");
    if (player) 
    {
        sr::Vector2 direction = player->GetTransform().pos - m_transform.pos;
        float rotation = direction.Angle();
        SetRotation(rotation * sr::math::RAD_TO_DEG);

        sr::Vector2 forward{ 1,0 };
        forward = forward.Rotate(m_transform.rotation * sr::math::DEG_TO_RAD);
        AddVelocity(forward * m_speed * dt);
    }

    float thrust = 0.0f;

    float rotate = 0.0f;


    sr::Vector2 vel{ 1,0 };

    //SetRotation(m_transform.rotation + rotate * dt);
    vel = vel.Rotate(m_transform.rotation * sr::math::DEG_TO_RAD) * thrust;
    AddVelocity(vel * dt);
    Actor::Update(dt, width, height);
}

void Enemy::Draw(const sr::Renderer& renderer) const
{
    Actor::Draw(renderer);
}