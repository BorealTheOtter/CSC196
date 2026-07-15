#pragma once
#include "Actor.h"


	class Player : public sr::Actor
	{
	public:
		Player() = default;
		Player(const sr::Transform& t) : Actor{ t } {}
		Player(const sr::Transform& t, const sr::Model& m) : Actor{ t, m } {}
		Player(const sr::Transform& t, const sr::Model& m, float s) : Actor{ t, m }, m_speed{s} {}

		void Update(float dt, const float width, const float height) override;
		void Draw(const class sr::Renderer& renderer) const;
	private:
		float m_speed = 200.0f;
	};