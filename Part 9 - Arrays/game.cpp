#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include "template.h"

namespace Tmpl8
{
	constexpr int PIXELS = 65536;
	float pixelX[PIXELS], pixelY[PIXELS];
	float origX[PIXELS], origY[PIXELS];

	float x = 400, y = 256;

	void Game::Init() 
	{
		for (int i = 0; i < PIXELS; ++i)
			origX[i] = IRand(800), origY[i] = IRand(511), pixelX[i] = origX[i], pixelY[i] = origY[i];
	}
	
	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);
		// cross hair
		/*screen->Line(mousex, 0, mousex, 511, 0xff0000);
		screen->Line(0, mousey, 799, mousey, 0xff0000);*/

		// move the pixel around cuz funny
		/*float dx = x - mousex, dy = y - mousey;
		float dist = sqrtf(dx* dx + dy * dy);
		if (dist < 50)
			x += dx / dist, y += dy / dist;
		screen->Plot((int)x, (int)y, 0xffffff);*/

		// iterate through the num of pixels
		for (int i = 0; i < PIXELS; ++i)
		{
			float dx = pixelX[i] - mousex, dy = pixelY[i] - mousey;
			float dist = sqrtf(dx * dx + dy * dy);

			// move away the pixel
			if (dist < 50)
				pixelX[i] += dx / dist, pixelY[i] += dy / dist;
			else
			{
				// return to original position
				float returnDx = origX[i] - pixelX[i];
				float returnDy = origY[i] - pixelY[i];
				float returnDist = sqrtf(returnDx * returnDx + returnDy * returnDy);

				if (returnDist > 1)
					pixelX[i] += returnDx / returnDist, pixelY[i] += returnDy / returnDist;
			}

			// draw the pixels
			screen->Plot((int)pixelX[i], (int)pixelY[i], 0xffffff);
		}
	}
};