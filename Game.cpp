#include "Game.h"



void Game::InitVariables()
{
	this->window = nullptr;
	this->playerGUI = new PlayerGUI(&this->player);
	this->background.loadFromFile("Resources/Textures/background.png");
	this->backgroundSprite.setTexture(this->background);

	this->bullets.push_back(new Bullet(this->textures["BULLET_RIGHT"], this->jakob.getPosition().x, this->jakob.getPosition().y, -1.f, 0.f, 50.f));
	
}

void Game::InitTextures()
{
	this->textures["BULLET_RIGHT"] = new sf::Texture();
	this->textures["BULLET_RIGHT"]->loadFromFile("Resources/Textures/bullet_right.png");

	this->textures["BULLET_LEFT"] = new sf::Texture();
	this->textures["BULLET_LEFT"]->loadFromFile("Resources/Textures/bullet_left.png");

}

void Game::InitWindow()
{
	
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->videoMode.getDesktopMode();
	this->window = new sf::RenderWindow(this->videoMode, "Pudzian The Game",sf::Style::Titlebar | sf::Style::Close);

}

Game::Game(Pudzian &player,EnemyJakob &jakob):player(player),jakob(jakob)
{
	
	this->InitVariables();
	this->InitTextures();
	this->InitWindow();
	//this->InitEnemies(ez);
	this->Render();
	this->Update();
}
Game::Game()
{

	//this->spawnEngine = new SpawnEngine(this->spawnEngine->getLevel());
	this->InitVariables();
	this->InitWindow();
	//this->InitEnemies(ez);
	this->Render();
	this->Update();
}

Game::~Game()
{
	//delete this->spawnEngine;
	delete this->window;
	delete this->playerGUI;

	//delete textures
	for (auto &x : this->textures) {
		delete &x.second;
	}
	//delete bullets
	for (auto &x : this->bullets) {
		delete &x;
	}
}

const bool Game::GetWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::UpdateBullets()
{
	for (auto &bullet : this->bullets) {
		bullet->Update(this->dt);
	}
}

void Game::Fight()
{
	this->EnemyAttackInteraction(this->player,this->jakob);
	this->EnemyAttackInteraction(this->jakob,this->player);
}


void Game::EnemyAttackInteraction(EnemyJakob &jakob,Pudzian &player) {
	if (player.getSprite().getGlobalBounds().contains(jakob.getPosition().x,jakob.getPosition().y) && player.getIsAttacking()) {
		this->PudzianAttack(jakob);
	}
}

void Game::EnemyAttackInteraction(Pudzian &player,EnemyJakob &jakob) {
	if (jakob.getSprite().getGlobalBounds().contains(player.getPosition().x, player.getPosition().y)) {
		this->JakobAttack(player);
	}
}

void Game::JakobAttack(Pudzian &p) {
	float hp = p.getHealthPoints();

	hp -= this->jakob.getAttackPoints();
	p.setHealthPoints(hp);

	std::cout << "xdd" << p.getHealthPoints() << std::endl;
}
void Game::PudzianAttack(EnemyJakob &j) {
	float hp = j.getHealthPoints();

	hp -= this->player.getAttackPoints();
	j.setHealthPoints(hp);

	std::cout << j.getHealthPoints() << std::endl;
}

void Game::UpdateHandler()
{
	/*
	this->entityVector.push_back(this->player);
	this->entityVector.push_back(this->jakob);

	for (auto &entity : entityVector) {
		entity.Update(this->dt);
	}*/
	this->playerGUI->Update(this->dt);
	this->player.Update(this->dt);
	this->jakob.Update(this->dt);

}

//SPRITE DRAWING
void Game::DrawEntities()
{
	this->window->draw(this->backgroundSprite);
	this->playerGUI->Render(*this->window);
	for (auto &bullet : this->bullets) {
		bullet->Render(this->window);
	}
	//this->spawnEngine->Render(this->window);
	this->jakob.Render(this->window);
	this->player.Render(this->window);
}

//EVENT HANDLING
void Game::Update()
{
	this->UpdateDt();
	this->PollEvents(this->dt);
	//TODO: walka tutaj
	this->Fight();
	this->UpdateHandler();

}

//UPDATING DT
void Game::UpdateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}


void Game::PollEvents(const float &dt)
{
	while (this->window->pollEvent(this->e)) {
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->window->close();
		} 

	}
}

void Game::Render()
{
	/*
		-clear old frame
		-render objects
		-display frame in window

	renders game objects
	*/
	
	this->window->clear(sf::Color(0, 0, 0, 255));
	this->DrawEntities();
	this->window->display();
}

float Game::getDt()
{
	return this->dt;
}
