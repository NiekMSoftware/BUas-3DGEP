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

	int white= (255 << 16) + (255 << 8) + 255;
	int black = 0;

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		screen->Clear((144 << 8) + (233 << 16));

		int squareSize = 20;
		int checkerboardSize = 200;

		// draw checkerboard
		for (int row = 0; row < checkerboardSize / squareSize; ++row)
		{
			for (int col = 0; col < checkerboardSize / squareSize; ++col)
			{
				Pixel color = ((row + col) % 2 == 0) ? white : black;

				// Calc pos
				int x1 = col * squareSize;
				int y1 = row * squareSize;
				int x2 = x1 + squareSize - 1;
				int y2 = y1 + squareSize - 1;

				// Draw square
				screen->Bar(x1, y1, x2, y2, color);
			}
		}

		// draw the solid grey bar next to the checkerboard
		int greybarX = checkerboardSize + 10;
		Pixel greyColor = (128 << 16) + (128 << 8) + 128;
		screen->Bar(greybarX, 0, greybarX + 200 - 1, 200 - 1, greyColor);
	}
};