#include "Bullet.h"


Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture,float posX,float posY,float dirX, float dirY, float movementSpeed)
{
	this->movementSpeed = 100.f;
	this->position = sf::Vector2f(posX,posY);
	this->sprite.setTexture(*texture);
	direction.x = dirX;
	direction.y = dirY;
	this->sprite.setPosition(this->position);
}

Bullet::~Bullet()
{
}

void Bullet::Update(const float dt)
{
	this->sprite.move(this->movementSpeed*this->direction*dt);
}

void Bullet::Render(sf::RenderTarget * target)
{
}
