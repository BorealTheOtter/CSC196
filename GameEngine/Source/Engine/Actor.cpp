#include "pch.h"
#include "Actor.h"
#include "Renderer.h"
#include "MathUtils.h"

namespace sr
{
	void Actor::Update(float dt, const float width, const float height)
	{
		m_transform.pos += (m_velocity * dt);

		m_transform.pos.x = math::Wrap(m_transform.pos.x, 0.0f, width);
		m_transform.pos.y = math::Wrap(m_transform.pos.y, 0.0f, height);
	}

	void Actor::Draw(const Renderer& renderer) const {
		renderer.SetColor(255, 255, 255);
		renderer.DrawFillRect(m_transform.pos.x - (m_transform.scale * 0.5f),
							  m_transform.pos.y - (m_transform.scale * 0.5f),
							  m_transform.scale, m_transform.scale);
	}
}