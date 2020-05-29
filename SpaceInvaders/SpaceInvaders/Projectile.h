#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile
{
private:
	Vector2f position;
	RectangleShape projectileShape;

	float xVelocity = 0;
	float yVelocity = 0;
	bool visible = false;

public:
	Projectile(float startX, float startY);
	void setVisibility(bool isVisible);
	bool getVisibility();
	FloatRect getPosition();
	float getSpeed();
	void setPosition(float positionX, float positionY);
	void setSpeed(float speed);
	RectangleShape getShape();

	void update();
};
