#pragma once
#include "Pudzian.h"
#include "Entity.h"
#include "Bullet.h"

class Pudzian;

class EnemyJakob :
	public Entity
{
	
public:
	EnemyJakob();
	EnemyJakob(float Damage, float healthPoints, float posX, float posY, Pudzian &player,const float dt);
	virtual sf::Vector2f getPosition() { return sf::Vector2f(this->sprite.getPosition().x, this->sprite.getPosition().y); }
	virtual float getAttackPoints();
	virtual void InitJakob();
	virtual void Update(const float &dt)override;
	virtual void Update(const float &dt, Pudzian &player);
	virtual void checkHealthPoints();
	virtual void Render(sf::RenderTarget* target = nullptr)override;
	virtual void Attack();
	virtual void Move(const float dir_x, const float dir_y, const float & dt);
	virtual void Follow(Pudzian &player,const float dt);
};

