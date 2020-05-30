#include "Projectile.h"

Projectile::Projectile(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	projectileShape.setSize(sf::Vector2f(5, 30));
	projectileShape.setPosition(position);
}

void Projectile::setVisibility(bool isVisible)
{
	if (isVisible)
		visible = true;
	else
		visible = false;
}

bool Projectile::getVisibility()
{
	return visible;
}

FloatRect Projectile::getPosition()
{
	return projectileShape.getGlobalBounds();
}

float Projectile::getSpeed()
{
	return yVelocity;
}

void Projectile::setPosition(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
	projectileShape.setPosition(position);

}

void Projectile::setSpeed(float speed)
{
	yVelocity = speed;
}

RectangleShape Projectile::getShape()
{
	return projectileShape;
}


void Projectile::update()
{
	position.y -= yVelocity;

	projectileShape.setPosition(position);
}
