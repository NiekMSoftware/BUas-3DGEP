#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <iostream>

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

	static Sprite image(new Surface("assets/space.jpg"), 1);

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// Clear window
		screen->Clear(0);

		Pixel* pixels = image.GetSurface()->GetBuffer();
		int imgWidth = image.GetWidth();
		int imgHeight = image.GetHeight();

		// Loop through each pixel in the sprite
		for (int y = 0; y < imgHeight; ++y)
		{
			for (int x = 0; x < imgWidth; ++x)
			{
				// Access the pixel
				Pixel& pixel = pixels[x + y * imgWidth];

				// Separate the color channels
				int red = (pixel & 0xff0000) >> 16;
				int green = (pixel & 0x00ff00) >> 8;
				int blue = (pixel & 0x0000ff);

				// Fade to black using floating point
				float fadeFactor = 0.9f; // Adjust this factor over time
				red = static_cast<int>(red * fadeFactor);
				green = static_cast<int>(green * fadeFactor);
				blue = static_cast<int>(blue * fadeFactor);

				// Alternatively, fade to black using integer
				/*int fadeStep = 5;
				red = std::max(0, red - fadeStep);
				green = std::max(0, green - fadeStep);
				blue = std::max(0, blue - fadeStep);*/

				// Recombine the color channels
				pixel = (red << 16) | (green << 8) | blue;
			}
		}
		// using integers is a bit slower.

		image.Draw(screen, 1, 1);
	}
};