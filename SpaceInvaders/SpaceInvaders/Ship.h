#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship
{
private:
	Vector2f position;
	RectangleShape shipShape;

	float shipSpeed = .2f;
public:
	Ship(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void reboundLeft();
	void reboundRight();
	void update();

};