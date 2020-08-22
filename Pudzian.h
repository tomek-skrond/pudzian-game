#pragma once
#include "Entity.h"
#include "EnemyJakob.h"


class Pudzian :
	public Entity
{
protected:
	bool isAttacking;
public:
	Pudzian();
	~Pudzian();

	virtual void Move(const float dir_x, const float dir_y, const float &dt);
	virtual void Update(const float& dt);
	virtual bool getIsAttacking() { return this->isAttacking; }
	virtual float getAttackPoints() { return this->Damage; }
	void Render(sf::RenderTarget* target = nullptr);
	void UpdateRotation(const float indicator);
	void AttackAnimation(const float indicator);
	virtual sf::Vector2f getPosition() { return sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y); }
	//void EnemyInteraction(EnemyJakob &jakob);
	//void Attack(EnemyJakob &jakob);
	void InitPudzian();
};

