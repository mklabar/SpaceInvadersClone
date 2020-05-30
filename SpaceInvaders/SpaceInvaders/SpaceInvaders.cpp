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
	int currentFrame = 0;
	system("dir");
	//load in sprites for textures
	Texture enemyTexture;
	Texture playerTexture;
	enemyTexture.loadFromFile("images/enemy_ship.png");
	playerTexture.loadFromFile("images/player_ship.png");


	Texture* pEnemyTexture = &enemyTexture;
	Texture* pPlayerTexture = &playerTexture;


	RenderWindow window(VideoMode(windowWidth, windowHeight), "iD Invaders");

	Ship ship(windowWidth / 2, windowHeight - 50, pPlayerTexture);
	Projectile projectile(windowWidth / 2, windowHeight - 64);
	
	//vector to store all enemies
	std::vector<Enemy> enemies;

	//loop to create several enemies (10 per row, 3 rows)
	for(int i = 0; i < 30; i++)
	{
		if (i < 10) 
		{
			Enemy enemy(windowWidth / 5 + (75 * i), windowHeight / 5, pEnemyTexture);
			enemies.push_back(enemy);
		}
		else if (i < 20)
		{
			Enemy enemy(windowWidth / 5 + (75 * (i-10)), (windowHeight / 5) * 2, pEnemyTexture);
			enemies.push_back(enemy);
		}
		else if (i < 30)
		{
			Enemy enemy(windowWidth / 5 + (75 * (i-20)), (windowHeight / 5) * 3, pEnemyTexture);
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
			if (ship.getPosition().left + 64 > windowWidth)
			{
				ship.reboundRight();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && !projectile.getVisibility()) 
		{
			projectile.setPosition(ship.getPosition().left + 32, windowHeight - 64);
			projectile.setVisibility(true);
			projectile.setSpeed(.1f);
		}

		//if the projectile is visible, check if it intersects an enemy
		if (projectile.getVisibility()) 
		{
			for (size_t j = 0; j < totalEnemies; j++)
			{
				//if the enemy is visible, check intersection
				if (projectile.getPosition().intersects(enemies[j].getPosition()) && enemies[j].getVisibility())
				{

					enemies[j].setVisibility(false);
					projectile.setVisibility(false);

				}
			}
			if (projectile.getPosition().top < 0)
				projectile.setVisibility(false);
		}
		if (currentFrame % 60 == 0)
		{
			for (size_t i = 0; i < totalEnemies; i++)
			{
				if (enemies[i].move(enemies[i].enemySpeed, windowWidth) == false) {
					enemies[i].toggleDirectionRight();
					for (size_t i = 0; i < totalEnemies; i++)
					{
						enemies[i].enemySpeed = 0;

					}
				}

			}
		}


		

		window.clear(Color(148, 213, 0, 255));
		

		ship.update();
		window.draw(ship.getShape());

		projectile.update();
		//only draw if visibility is true
		if(projectile.getVisibility())
			window.draw(projectile.getShape());

		for (size_t i = 0; i < totalEnemies; i++)
		{
			enemies[i].update();
			//only draw if visibility is true
			if(enemies[i].getVisibility())
				window.draw(enemies[i].getShape());
		}

		window.display();
		currentFrame++;
	}

}