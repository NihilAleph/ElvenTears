#pragma once
#include "Body.h"

enum class PlayerMoveState { STANDING, WALKING, ATTACKING, MIDAIR_UP, MIDAIR_DOWN, SIGHTED };

class Player : public Body
{
public:
	Player();
	~Player();

	virtual void init(b2World* world, const glm::vec2& position) override;

	virtual void draw(taengine::SpriteBatch& spriteBatch) override;
	virtual void update(taengine::InputManager& inputManager) override;

	void drawDebug(taengine::DebugRenderer& renderer, taengine::Color color);

	void addFootContacts() { m_footContacts++; }
	void subFootContacts() { m_footContacts--; }

	void addKill() { m_killCount++; }

	void setSighted() { m_moveState = PlayerMoveState::SIGHTED; }
	bool isSighted() { return m_moveState == PlayerMoveState::SIGHTED; }

private:

	float m_animationSpeed = 0.15f;
	float m_animationTime = 0.0f;

	int m_direction = 1; // or -1

	int m_footContacts = 0;

	int m_killCount = 0;

	PlayerMoveState m_moveState = PlayerMoveState::STANDING;

	b2Fixture* m_attackSensor = nullptr;
};

