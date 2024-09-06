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

	static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
	static int frame = 0;

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	Sprite theSprite(new Surface("assets/ball.png"), 1);
	float spriteY = 0, speed = 1;

	const float downForce = 0.001f;
	const float damping = 0.8f;

	void Game::Tick(float deltaTime)
	{
		printf("%f\n", deltaTime);

		screen->Clear(0);

		spriteY += speed * deltaTime;
		speed += downForce * deltaTime;

		if (spriteY > (512 - 50))
		{
			spriteY = 512 - 50;
			speed = -speed * damping;
		}

		theSprite.Draw(screen, 20, (int)spriteY);
	}
};