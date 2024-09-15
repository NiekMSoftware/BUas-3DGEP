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
        int width = 800; // Width of the gradient area
        int height = 512; // Height of the gradient area

        // Define rainbow colors
        Pixel rainbowColors[] = {
            (255 << 16) + (0 << 8) + 0,       // Red
            (255 << 16) + (127 << 8) + 0,     // Orange
            (255 << 16) + (255 << 8) + 0,     // Yellow
            (0 << 16) + (255 << 8) + 0,       // Green
            (0 << 16) + (225 << 8) + 255,     // Cyan
            (0 << 16) + (0 << 8) + 255,       // Blue
            (75 << 16) + (0 << 8) + 130,      // Indigo
            (148 << 16) + (0 << 8) + 211      // Violet
        };

        int stripeWidth = width / 7; // Calculate width of each stripe

        for (int x = 0; x < width; ++x)
        {
            // Determine the color for the current stripe
            float t = (float)x / (width - 1); // Normalized position from 0 to 1
            int colorIndex = (int)(t * (7 - 1)); // Determine which two colors to interpolate between
            float localT = (t * (7 - 1)) - colorIndex; // Interpolation factor

            // Get the two colors to interpolate between
            Pixel color1 = rainbowColors[colorIndex];
            Pixel color2 = rainbowColors[colorIndex + 1];

            // Interpolate between the two colors
            int r1 = (color1 >> 16) & 0xFF;
            int g1 = (color1 >> 8) & 0xFF;
            int b1 = color1 & 0xFF;
            int r2 = (color2 >> 16) & 0xFF;
            int g2 = (color2 >> 8) & 0xFF;
            int b2 = color2 & 0xFF;

            int r = (int)(r1 * (1 - localT) + r2 * localT);
            int g = (int)(g1 * (1 - localT) + g2 * localT);
            int b = (int)(b1 * (1 - localT) + b2 * localT);

            Pixel color = (r << 16) + (g << 8) + b;

            // Draw the vertical line for the current color
            int x1 = x;
            int y1 = 0;
            int x2 = x;
            int y2 = height - 1;
            screen->Bar(x1, y1, x2, y2, color);
        }
	}
};