#include "Game.h"



void Game::InitVariables()
{
	this->window = nullptr;
	this->playerGUI = new PlayerGUI(&this->player);
	this->background.loadFromFile("Resources/Textures/background.png");
	this->backgroundSprite.setTexture(this->background);
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

Game::Game(Pudzian &player,EnemyJakob *jakob):player(player),jakob(jakob)
{
	this->InitTextures();
	this->InitVariables();
	this->InitWindow();

	//this->InitEnemies(ez);
	this->Render();
	this->Update();
}
Game::Game()
{

	//this->spawnEngine = new SpawnEngine(this->spawnEngine->getLevel());
	this->InitTextures();
	this->InitVariables();
	this->InitWindow();
	this->SpawnEnemies();
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
		delete x.second;
	}
	//delete bullets
	for (auto *x : this->bullets) {
		delete x;
	}
	//delete enemies
	for (auto *x : this->enemyVector) {
		delete x;
		std::cout << "jakob deleted" << std::endl;
	}
}

const bool Game::GetWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::UpdateBullets()
{
	unsigned counter = 0;
	for (auto *bullet : this->bullets) {
		bullet->Update(this->dt);
		
		//bullet culling
		if (bullet->GetBounds().top + bullet->GetBounds().height < 0.f) {

			//delete current bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
			std::cout << this->bullets.size() << std::endl;
		}
		++counter;
	}

}


void Game::UpdateHandler()
{
	this->playerGUI->Update(this->dt);
	this->player.Update(this->dt);
	for (auto *x : this->enemyVector) {
		x->Update(this->dt,this->player);
	}

}

void Game::UpdateGUI()
{
	this->playerGUI->Update(this->dt);
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
	for (auto *x : this->enemyVector) {
		x->Render(this->window);
	}
	this->player.Render(this->window);
}

//EVENT HANDLING
void Game::Update()
{
	this->UpdateDt();
	this->PollEvents(this->dt);
	this->UpdateBullets();
	//this->Fight();
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			if (this->player.getRotationIndicator()) {
				this->bullets.push_back(new Bullet(this->textures["BULLET_RIGHT"], this->player.getPos().x, this->player.getPos().y, 1.f, 0.f, 500.f));
			}
			else {
				this->bullets.push_back(new Bullet(this->textures["BULLET_LEFT"], this->player.getPos().x, this->player.getPos().y, -1.f, 0.f, 500.f));
			}

		}
		for (auto *i : this->enemyVector) {
			//TODO: EXTRACT!!!!!!{
			if (this->player.getSprite().getGlobalBounds().contains(i->getPosition().x, i->getPosition().y) && this->player.getIsAttacking()) {
				float hp = this->player.getHealthPoints();

				hp -= i->getAttackPoints();
				this->player.setHealthPoints(hp);

				this->currentHp = hp;

				std::cout << "xdd" << this->player.getHealthPoints() << std::endl;
			}
			if (i->getSprite().getGlobalBounds().contains(this->player.getPos().x, this->player.getPos().y)) {
				float hp = i->getHealthPoints();

				hp -= this->player.getAttackPoints();
				i->setHealthPoints(hp);

				this->currentHp = hp;

				std::cout << i->getHealthPoints() << std::endl;
			}
			//}
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

void Game::SpawnEnemies()
{
	std::mt19937 generator(123);
	std::uniform_real_distribution<float> dis1(0.0, 1920.0);
	std::uniform_real_distribution<float> dis2(0.0, 1080.0);

	for (int i = 0; i < 7; ++i) {
		this->enemyVector.push_back(new EnemyJakob(5.f, 30.f, dis1(generator), dis2(generator), this->player,this->dt));
	}
}

float Game::getDt()
{
	return this->dt;
}
