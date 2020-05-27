#include "Ship.h"
#include "Projectile.h"
#include "Enemy.h"
#include <sstream>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
/* DEFINE GAMESTATES HERE */

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "iD Invaders");

	Ship ship(windowWidth / 2, windowHeight - 50);
	Projectile projectile(windowWidth / 2, windowHeight - 50);
	
	//vector to store all enemies
	std::vector<Enemy> enemies;

	//loop to create several enemies (10 per row, 3 rows)
	for(int i = 0; i < 30; i++)
	{
		if (i < 10) 
		{
			Enemy enemy(windowWidth / 5 + (75 * i), windowHeight / 5);
			enemies.push_back(enemy);
		}
		else if (i < 20)
		{
			Enemy enemy(windowWidth / 5 + (75 * (i-10)), (windowHeight / 5) * 2);
			enemies.push_back(enemy);
		}
		else if (i < 30)
		{
			Enemy enemy(windowWidth / 5 + (75 * (i-20)), (windowHeight / 5) * 3);
			enemies.push_back(enemy);
		}
	}
	

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{
			ship.moveLeft();
			if (ship.getPosition().left < 0)
			{
				ship.reboundLeft();
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{
			ship.moveRight();
			if (ship.getPosition().left + 100 > windowWidth)
			{
				ship.reboundRight();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) 
		{
			projectile.setPosition(ship.getPosition().left + 50, windowHeight - 50);
			projectile.setSpeed(.1f);
		}
		




		ship.update();
		projectile.update();
		window.clear(Color(148, 213, 0, 255));

		int length = enemies.size();
		for (int i = 0; i < length; i++)
		{
			enemies[i].update();
			window.draw(enemies[i].getShape());

		}
	
		window.draw(ship.getShape());
		window.draw(projectile.getShape());
		
		window.display();
	}

}