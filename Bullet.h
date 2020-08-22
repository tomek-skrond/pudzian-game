#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class Bullet
{
	sf::Sprite sprite;

	sf::Vector2f direction;
	sf::Vector2f position;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();

	void Update(const float dt);
	void Render(sf::RenderTarget *target = nullptr);

	const sf::FloatRect GetBounds() {
		return this->sprite.getGlobalBounds();
	}
};

