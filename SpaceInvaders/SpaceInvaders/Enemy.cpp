#include "Enemy.h"

Enemy::Enemy(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	enemyShape.setSize(Vector2f(50, 50));
	enemyShape.setPosition(position);
}

FloatRect Enemy::getPosition()
{
	return enemyShape.getGlobalBounds();
}

RectangleShape Enemy::getShape()
{
	return enemyShape;
}

void Enemy::moveLeft()
{
	//only move at certain intervals
}

void Enemy::moveRight()
{
	//only move at certain intervals
}

void Enemy::update()
{
	enemyShape.setPosition(position);
}
