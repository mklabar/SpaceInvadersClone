#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
private:
	Vector2f position;
	RectangleShape enemyShape;

	float enemySpeed = 0;
public:
	Enemy(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void update();

};