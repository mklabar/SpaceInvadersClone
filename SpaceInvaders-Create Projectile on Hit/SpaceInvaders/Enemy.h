#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
private:
	Vector2f position;
	RectangleShape enemyShape;

	float enemySpeed = 0;
	bool visible = true;
public:
	Enemy(float startX, float startY);
	void setVisibility(bool isVisible);
	bool getVisibility();
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft(int distance);
	void moveRight(int distance);
	void update();

};