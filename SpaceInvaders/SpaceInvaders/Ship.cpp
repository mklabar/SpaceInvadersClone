#include "Ship.h"

Ship::Ship(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	shipShape.setSize(Vector2f(100, 40));
	shipShape.setPosition(position);
}

FloatRect Ship::getPosition()
{
	return shipShape.getGlobalBounds();
}

RectangleShape Ship::getShape()
{
	return shipShape;
}

void Ship::moveLeft()
{
	position.x -= shipSpeed;
}

void Ship::moveRight()
{
	position.x += shipSpeed;
}

void Ship::reboundLeft()
{
	position.x += shipSpeed;
}
void Ship::reboundRight()
{
	position.x -= shipSpeed;
}

void Ship::update()
{
	shipShape.setPosition(position);
}
