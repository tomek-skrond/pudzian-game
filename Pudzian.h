#pragma once
#include "Entity.h"
#include "EnemyJakob.h"


class Pudzian :
	public Entity
{
protected:
	bool isAttacking;
	float rotationIndicator;
	sf::Vector2f direction;
public:
	Pudzian();
	~Pudzian();

	virtual void Move(const float dir_x, const float dir_y, const float &dt);
	virtual void Update(const float& dt);
	bool getIsAttacking() { return this->isAttacking; }
	float getAttackPoints() { return this->Damage; }
	float getRotationIndicator() { return this->rotationIndicator; }
	void Render(sf::RenderTarget* target = nullptr);
	void UpdateRotation(const float indicator);
	void AttackAnimation(const float indicator);
	const sf::Vector2f& getPos() { return this->sprite.getPosition(); }
	const sf::Vector2f& getDir() { return this->direction; }
	//void EnemyInteraction(EnemyJakob &jakob);
	//void Attack(EnemyJakob &jakob);
	void InitPudzian();
};
