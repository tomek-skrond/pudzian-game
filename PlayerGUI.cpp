#include "PlayerGUI.h"
#include "Pudzian.h"


PlayerGUI::PlayerGUI(Pudzian * player)
{
	this->player = player;

	
	this->initFont();
	this->initHPBar();
}

PlayerGUI::~PlayerGUI()
{
}

void PlayerGUI::initFont()
{
	this->font.loadFromFile("Resources/Fonts/Blazed.ttf");
}

void PlayerGUI::initHPBar()
{
	this->width = 100.f;
	this->height = 20.f;
	sf::Vector2f position = sf::Vector2f(20,20);

	this->hpBarBack.setSize(sf::Vector2f(this->width,this->height));
	this->hpBarBack.setFillColor(sf::Color(sf::Color::Red));
	this->hpBarBack.setPosition(position);

	this->hpBarInner.setSize(sf::Vector2f(this->width, this->height));
	this->hpBarInner.setFillColor(sf::Color::Green);
	this->hpBarInner.setPosition(this->hpBarBack.getPosition());
}

void PlayerGUI::RenderHPBar(sf::RenderTarget &target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
}

void PlayerGUI::UpdateHPBar()
{
	
	//this->RenderHPBar(target);
	this->hpBarInner.setScale(this->player->getHealthPoints() / 500, 1.f);//TODO: get max health instead of '500'

}

void PlayerGUI::Update(const float &dt)
{
	//this->hpBarInner.setSize(&this->player->getHealthPoints().x);
	this->UpdateHPBar();
}

void PlayerGUI::Render(sf::RenderTarget &target)
{
	this->RenderHPBar(target);
}
