#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <cassert>

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

	Surface image("assets/space.png");
	
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        // Get screen and image dimensions
        int screenWidth = screen->GetWidth();   // 800
        int screenHeight = screen->GetHeight(); // 512
        int imageWidth = 200;  // The width of the image grid in terms of LED grid cells
        int imageHeight = 200; // The height of the image grid in terms of LED grid cells

        // Calculate LED width and height so the entire grid fits on the screen
        int ledWidth = screenWidth / imageWidth;
        int ledHeight = screenHeight / imageHeight;

        // Clear the graphics window
        screen->Clear(0);

        // Draw a grid of LEDs
        for (int x = 0; x < imageWidth; x++)
        {
            for (int y = 0; y < imageHeight; y++)
            {
                Pixel p = image.GetBuffer()[x + y * imageWidth];
                int red = p & 0xff0000;
                int green = p & 0x00ff00;
                int blue = p & 0x0000ff;

                // Calculate positions for the LEDs
                int startX = x * ledWidth;
                int startY = y * ledHeight;

                // Draw the red, green, and blue bars as part of the LED
                screen->Bar(startX, startY, startX + ledWidth - 1, startY + ledHeight / 3 - 1, red);
                screen->Bar(startX, startY + ledHeight / 3, startX + ledWidth - 1, startY + 2 * ledHeight / 3 - 1, green);
                screen->Bar(startX, startY + 2 * ledHeight / 3, startX + ledWidth - 1, startY + ledHeight - 1, blue);
            }
        }
    }
};