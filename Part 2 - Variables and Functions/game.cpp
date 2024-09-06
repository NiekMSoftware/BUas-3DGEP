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

	void Game::DrawI(int x, int y) 
	{
		screen->Line(100 + x, 50 + y, 200 + x, 50 + y, 0xffffff);
		screen->Line(150 + x, 50 + y, 150 + x, 300 + y, 0xffffff);
		screen->Line(100 + x, 300 + y, 200 + x, 300 + y, 0xffffff);
	}

	void Game::DrawFatI(int amount, int x)
	{
		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < amount; j++) {
				DrawI(x + i, j);
			}
		}
	}

	int move = 0;
	int dir = 1;

	void Game::Tick(float deltaTime)
	{
		screen->Clear(80);

		dir = move == 0 ? 1 : move == 500 ? -1 : dir;
		DrawFatI(30, move);
		move += dir;
	}
};