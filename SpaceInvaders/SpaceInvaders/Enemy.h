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

	//if movesRight = false, direction is set to left 
	bool movesRight = false;

	//if movesDown = false, direction is set to up
	bool movesDown = true;
public:
	Enemy(float startX, float startY);
	void setVisibility(bool isVisible);
	bool getVisibility();
	FloatRect getPosition();
	RectangleShape getShape();
	void toggleDirectionRight();
	void setDirectionDown(bool movingDown);
	bool move(int distance, int width);
	void moveRight(int distance);
	void update();

};