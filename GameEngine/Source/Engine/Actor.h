#pragma once

#include <string>


#include "Transform.h"
#include "Model.h"

namespace sr
{
	struct ActorDesc 
	{
		Transform transform;
		Vector2 velocity{ 0,0 };
		Model model;
		std::string name;
		std::string tag;
	};

	class Actor
	{
	public:
		Actor() = default;
		Actor(const ActorDesc& ad) : m_transform{ ad.transform }, m_velocity{ ad.velocity }, m_model{ ad.model } {};
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
		void AddVelocity(const Vector2& velocity) { m_velocity += velocity; }
		
		const std::string& GetName() const { return m_name; }
		const std::string& GetTag() const { return m_tag; }
	protected:
		std::string m_name;
		std::string m_tag;

		Transform m_transform;
		Vector2 m_velocity{ 0,0 };

		Model m_model;
	};
}