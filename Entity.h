#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<math.h>
#include<random>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class Entity
{
protected:
	float movementSpeed;
	float healthPoints;
	float Damage;

	sf::Vector2f SpawnPosition;
	sf::Texture texture;
	sf::Sprite sprite;


public:
	
	
	Entity();
	virtual ~Entity();

	virtual float getHealthPoints() { return healthPoints; }
	virtual void setHealthPoints(const float hp) { this->healthPoints = hp; }
	virtual sf::Sprite& getSprite() { return this->sprite; }
	virtual void Move(const float dir_x, const float dir_y, const float &dt);
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

