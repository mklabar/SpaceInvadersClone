#include "Ship.h"
#include "Projectile.h"
#include "Enemy.h"
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
/* DEFINE GAMESTATES HERE */

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "iD Invaders");

	Ship ship(windowWidth / 2, windowHeight - 50);

	//vector to store all ammo
	std::vector<Projectile> projectiles;
	size_t totalAmmo = projectiles.size();
	
	
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

	//total # of enemies in vector
	size_t totalEnemies = enemies.size();
	

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
			//create a new projectile and add to vector
			Projectile projectile(ship.getPosition().left + 50, windowHeight - 50);
			projectiles.push_back(projectile);

			//update vector length
			totalAmmo = projectiles.size();
		}


		//check if any enemy intersects with any projectile
		for (size_t i = 0; i < totalEnemies; i++)
		{
			for (size_t j = 0; j < totalAmmo; j++)
			{
				if (projectiles[j].getPosition().intersects(enemies[i].getPosition()))
				{
					enemies[i].destroy();
					projectiles[j].destroy();

				}

			}
			

		}
		
		
	
		window.clear(Color(148, 213, 0, 255));

		for (size_t i = 0; i < totalAmmo; i++)
		{
			projectiles[i].update();
			window.draw(projectiles[i].getShape());
		}

		for (size_t i = 0; i < totalEnemies; i++)
		{
			enemies[i].update();
			window.draw(enemies[i].getShape());
		}
	
		ship.update();
		window.draw(ship.getShape());

		
		window.display();
	}

}