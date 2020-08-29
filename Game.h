#pragma once
#include"Entity.h"
#include "Pudzian.h"
#include "EnemyJakob.h"
#include "PlayerGUI.h"
#include "Bullet.h"

class Game
{
	
	float dt;
	float currentHp;

	sf::RenderWindow* window;
	sf::Event e;
	sf::VideoMode videoMode;
	sf::Clock dtClock;

	sf::Sprite backgroundSprite;
	sf::Texture background;
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Pudzian player;
	EnemyJakob *jakob;

	std::vector<EnemyJakob*> enemyVector;

	PlayerGUI* playerGUI;
	sf::RectangleShape hpBarModified;

	//functions
	void InitWindow();
	void InitVariables();
	void InitTextures();
	//void InitEnemies(GameMode mode,int i=0);


public:

	Game(Pudzian &player,EnemyJakob *jakob);
	Game();
	virtual ~Game();

	//accessors
	const bool GetWindowIsOpen()const;

	//functions
	void UpdateBullets();
	void UpdateHandler();
	void UpdateGUI();
	void DrawEntities();
	void Update();
	void UpdateDt();
	void PollEvents(const float &dt);
	void Render();
	void SpawnEnemies();
	float getDt();
};

