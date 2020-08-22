#include "Entity.h"

Entity::Entity()
{
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
	
}



void Entity::Move(const float dir_x, const float dir_y, const float & dt)
{
	this->sprite.move(dir_x*dt*this->movementSpeed, dir_y*dt*this->movementSpeed);
}



