# SpaceInvadersClone
Clone of Space Invaders Using SFML

Designed the structure of the game based off of the Pong lesson. 

The ship can move left and right without going off screen. A projectile is shot from the ship by pressing space and you cannot shoot again until it is destroyed or off screen again. I used the provided assets for the enemy sprite textures and player sprite texture. I intended to have the enemies move left and right on the screen (moving all together to the left, stopping when they hit the wall, and then moving to the right) However I had difficulty setting this up so currently they only move to the left and then stop. 

The other version is included to show how the game can lag when you are detecting collisions via a nested for loop. In this case it is checking if any missile intersects with any enemy every frame of the game.
