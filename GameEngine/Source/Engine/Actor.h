#pragma once

#include "Transform.h"
#include "Model.h"

namespace sr
{
	class Actor
	{
	public:
		Actor() = default;
		Actor(const Transform& t) : m_transform{ t } {}
		Actor(const Transform& t, const Model& m) : m_transform{ t }, m_model{ m } {}

		virtual void Update(float dt, const float width, const float height);

		virtual void Draw(const class Renderer& renderer) const;

		const Transform& GetTransform() const { return m_transform; }

		void SetPosition(const Vector2& pos) { m_transform.pos = pos; }
		void SetRotation(float rotation) { m_transform.rotation = rotation; }
		void SetScale(float scale) { m_transform.scale = scale; }

		const Vector2& GetVelocity() const { return m_velocity; }
		void SetVelocity(const Vector2& velocity) { m_velocity = velocity; }

	protected:
		Transform m_transform;
		Vector2 m_velocity{ 0,0 };

		Model m_model;
	};
}