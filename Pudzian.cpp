#include "Pudzian.h"
#include "Entity.h"
#include "EnemyJakob.h"

Pudzian::Pudzian()
{
	this->InitPudzian();
	//this->InitBuffers();
}

Pudzian::~Pudzian()
{
}
void Pudzian::InitPudzian()
{
	//set pudzian parameters
	this->movementSpeed = 300.f;
	this->healthPoints = 500.f;
	this->Damage = 10.f;
	this->sprite.setScale(sf::Vector2f(0.7f, 0.7f));
	this->texture.loadFromFile("Resources/Textures/pudzianos.png");
	this->sprite.setTexture(this->texture);
}
void Pudzian::Move(const float dir_x, const float dir_y, const float & dt)
{
	this->sprite.move(dir_x*dt*this->movementSpeed, dir_y*dt*this->movementSpeed);
	this->UpdateRotation(dir_x);
	
	this->direction.x = dir_x;
	this->direction.y = dir_y;
}

void Pudzian::Update(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		this->Move(0.f,-1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		this->Move(0.f, 1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		this->Move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		this->Move(1.f, 0.f, dt);
	}
	if (this->healthPoints <= 0) {
		this->sprite = sf::Sprite();
	}
	
}

void Pudzian::Render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}

void Pudzian::UpdateRotation(const float indicator)
{
	if (indicator > 0 || indicator == 0) {
		this->texture.loadFromFile("Resources/Textures/pudzianos.png");
		this->sprite.setTexture(this->texture);
		this->rotationIndicator = 1.f;
	}
	else {
		this->texture.loadFromFile("Resources/Textures/pudzian_inverted.png");
		this->sprite.setTexture(this->texture);
		this->rotationIndicator = 0.f;
	}
	this->AttackAnimation(indicator);
}

void Pudzian::AttackAnimation(const float indicator)
{
	//sf::Sprite s = this->sprite;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (indicator > 0.0f) {

			this->texture.loadFromFile("Resources/Textures/pudzian_napierdala_right.png");
			this->sprite.setTexture(this->texture);

		}
		if(indicator < 0.0f){
			this->texture.loadFromFile("Resources/Textures/pudzian_napierdala_left.png");
			this->sprite.setTexture(this->texture);
		}
		if(indicator == 0.0f){
			this->texture.loadFromFile("Resources/Textures/pudzian_napierdala_right.png");
			this->sprite.setTexture(this->texture);
		}
		this->isAttacking = true;
	}
	//this->sprite = s;
}


