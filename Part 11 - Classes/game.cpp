#include "game.h"
#include "surface.h"
#include "iostream"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define SPRITESIZE 32

namespace Tmpl8
{

	void Game::Init() {}
	void Game::Shutdown() {}

	Surface tiles("assets/nc2tiles.png");

	char map[5][30] = {
		"kcXkcXkcXkcXkcXkcXkcXkc kc kc",
		"kcXfb fb fbXkcXkcXkcXkc kc kc",
		"kcXfb fb fb fb fbXkcXkc kc kc",
		"kcXlcXlcXfb fb fbXkcXkc kc kc",
		"kcXkcXkcXlcXlcXlcXkcXkc kc kc"
	};

	bool CheckPos(int x, int y)
	{
		int tx = x / SPRITESIZE, ty = y / SPRITESIZE;
		char collider = map[ty][tx * 3 + 2];

		return collider != 'X';
	}

	bool CheckCollision(int x, int y, int width, int height)
	{
		// Calculate the center of the player's bounding box
		int centerX = x + width / 2;
		int centerY = y + height / 2;

		// Only check the center of the bounding box
		return CheckPos(centerX, centerY);
	}

	Sprite tank(new Surface("assets/ctankbase.tga"), 16);
	int px = 75, py = 25;

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);

		int tileSize = 32;
		int mapWidth = 10 * tileSize;
		int mapHeight = 5 * tileSize;
		int screenWidth = screen->GetWidth();
		int screenHeight = screen->GetHeight();

		// calc offset
		int offsetX = (screenWidth - mapWidth) / 2;
		int offsetY = (screenHeight - mapHeight) / 2;

		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 10; x++)
			{
				int tx = map[y][x * 3] - 'a';
				int ty = map[y][x * 3 + 1] - 'a';
				DrawTile(tx, ty, screen, x * tileSize + offsetX, y * tileSize + offsetY);
			}

		tank.Draw(screen, px + offsetX, py + offsetY);

		int nx = px, ny = py;
		if (GetAsyncKeyState(VK_LEFT)) nx--;
		if (GetAsyncKeyState(VK_RIGHT)) nx++;
		if (GetAsyncKeyState(VK_UP)) ny--;
		if (GetAsyncKeyState(VK_DOWN)) ny++;

		if (CheckCollision(nx, ny, 32, 32))
			px = nx, py = ny;
	}
	void Game::DrawTile(int tx, int ty, Surface* screen, int x, int y)
	{
		Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * 595;
		Pixel* dst = screen->GetBuffer() + x + y * 800;
		for (int i = 0; i < SPRITESIZE; i++, src += 595, dst += 800)
			for (int j = 0; j < SPRITESIZE; j++)
				dst[j] = src[j];
	}
};