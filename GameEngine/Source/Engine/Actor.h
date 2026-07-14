#pragma once

#include "Transform.h"

namespace sr
{
	class Actor
	{
	public:
		Actor(const Transform& t) : m_transform{ t } {}

		void Update(float dt, const float width, const float height);

		void Draw(const class Renderer& renderer) const;

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
}