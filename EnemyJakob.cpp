#include "EnemyJakob.h"
#include "Entity.h"
#include "Pudzian.h"

EnemyJakob::EnemyJakob()
{
	this->InitJakob();
}
EnemyJakob::EnemyJakob(float Damage,float healthPoints,float posX,float posY,Pudzian &player,const float dt){
	
	this->movementSpeed = 500.f;
	this->Damage = Damage;
	this->healthPoints = healthPoints;
	this->SpawnPosition.x = posX;
	this->SpawnPosition.y = posY;

	this->sprite.setScale(sf::Vector2f(0.4f, 0.4f));
	this->texture.loadFromFile("Resources/Textures/jakub.png");

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->SpawnPosition);

}

float EnemyJakob::getAttackPoints()
{
	return this->Damage;
}


void EnemyJakob::InitJakob()
{
	
	std::mt19937 generator(123);
	std::uniform_real_distribution<float> dis(0.0, 1920.0);

	this->Damage = 5.f;
	this->healthPoints = 30.f;
	this->SpawnPosition.x = dis(generator);
	this->SpawnPosition.y = -100.f;

	this->sprite.setScale(sf::Vector2f(0.4f, 0.4f));
	this->texture.loadFromFile("Resources/Textures/jakub.png");

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->SpawnPosition);

}

void EnemyJakob::Update(const float & dt)
{
}

void EnemyJakob::Update(const float & dt,Pudzian &player)
{
	
	//this->Move(0.f,1.f,dt);
	this->Follow(player, dt);
	this->checkHealthPoints();

}

void EnemyJakob::checkHealthPoints()
{
	if (this->healthPoints <= 0 || this->sprite.getPosition().y >= 980.f) {

		this->sprite = sf::Sprite();
		
	}
}

void EnemyJakob::Render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}

void EnemyJakob::Attack()
{
	
}
void EnemyJakob::Move(const float dir_x, const float dir_y, const float & dt)
{
	this->sprite.move(dir_x*dt*this->movementSpeed, dir_y*dt*this->movementSpeed);

}

void EnemyJakob::Follow(Pudzian &player,const float dt)
{
	sf::Vector2f moveVec;
	moveVec.x = abs(player.getPos().x - this->getPosition().x);
	moveVec.y = abs(player.getPos().y - this->getPosition().y);

	float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
	moveVec /= vecLength;

	this->Move(-moveVec.x, -moveVec.y, dt);
	

}
