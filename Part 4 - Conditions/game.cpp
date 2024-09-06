#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	Sprite theSprite(new Surface("assets/ball.png"), 1);
	int spriteX = 0;
	int spriteY = 100;
	int speed = 1;
	int speedX = 1;
	int initialSpeedValue = 1;
	int bounces = 0;

	void Game::Tick(float deltaTime)
	{
		spriteY += speed * deltaTime;
		spriteX += speedX * deltaTime;
		
		bool hitTop = false;
		bool hitBottom = false;
		bool hitRight = false;
		bool hitLeft = false;

		if (bounces != 50) {
			hitTop = spriteY < 0;
			hitBottom = spriteY > (512 - 50); 
			hitRight = spriteX > (800 - 50);
			hitLeft = spriteX < 0;
		}

		// Check boundaries
		if (hitBottom)
		{
			spriteY = 512 - 50;
			speed = -speed;
			bounces++;
		}
		else if (hitTop) 
		{
			spriteY = 0;
			speed = initialSpeedValue;
			bounces++;
		}

		if (hitRight)
		{
			spriteX = 800 - 50;
			speedX = -speedX;
			bounces++;
		}
		else if (hitLeft)
		{
			spriteX = 0;
			speedX = initialSpeedValue;
			bounces++;
		}
		
		screen->Clear(0);
		theSprite.Draw(screen, spriteX, spriteY);
		printf("bounces: %i\n", bounces);
	}
};