#pragma once
#include "Pudzian.h"
#include "Entity.h"

class Pudzian;

class PlayerGUI
{
	Pudzian* player;

	float width;
	float height;

	sf::Font font;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;
public:
	PlayerGUI(Pudzian* player);
	~PlayerGUI();
	void initFont();
	void initHPBar();
	void RenderHPBar(sf::RenderTarget &target);
	void UpdateHPBar();
	void Update(const float &dt);
	void Render(sf::RenderTarget &target);
	sf::RectangleShape &getHpBarInner() { return this->hpBarInner; }
};
