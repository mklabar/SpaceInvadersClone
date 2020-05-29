#include "Enemy.h"

Enemy::Enemy(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	enemyShape.setSize(Vector2f(50, 50));
	enemyShape.setPosition(position);
}

void Enemy::setVisibility(bool isVisible)
{
	if (isVisible)
		visible = true;
	else
		visible = false;
}

bool Enemy::getVisibility()
{
	return visible;
}

FloatRect Enemy::getPosition()
{
	return enemyShape.getGlobalBounds();
}

RectangleShape Enemy::getShape()
{
	return enemyShape;
}

void Enemy::toggleDirectionRight()
{
	//toggles the value to the opposite of what it was
	movesRight = !movesRight;
}

void Enemy::setDirectionDown(bool movingDown)
{
	movingDown = movesDown;
}

bool Enemy::move(int distance, int width)
{
	if (movesRight)
	{
		//if width - distance = 0 don't move
		if (position.x < width - distance)
		{
			position.x += distance;
			return true;
		}

	}
	else
	{
		//if position - distance = 0 don't move
		if (position.x > distance)
		{
			position.x -= distance;
			return true;
		}

	}

	//did not move due to wall collision
	return false;
}

void Enemy::moveRight(int distance)
{
	position.x += distance;
	
}

void Enemy::update()
{
	/*if (position.x < 1024 && position.x >= 0)
		moveLeft(1);
	else if (position.x < 0)
		moveRight(1);*/
	enemyShape.setPosition(position);
}
