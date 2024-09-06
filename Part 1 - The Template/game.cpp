#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	struct linepoints {
		float x1;
		float y1;

		float x2;
		float y2;

		Pixel color;
	};

	linepoints m_word[21];

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		// C
		m_word[0] = { 150, 120, 80, 60, RedMask };
		m_word[1] = { 80, 60, 10, 120, RedMask };
		m_word[2] = { 10, 120, 10, 240, RedMask };
		m_word[3] = { 10, 240, 80, 300, RedMask };
		m_word[4] = { 80, 300, 150, 240, RedMask };

		// O
		m_word[5] = { 240, 60, 180, 120, GreenMask };
		m_word[6] = { 180, 120, 180, 240, GreenMask };
		m_word[7] = { 180, 240, 240, 300, GreenMask };
		m_word[8] = { 240, 300, 300, 240, GreenMask };
		m_word[9] = { 300, 240, 300, 120, GreenMask };
		m_word[10] = { 300, 120, 240, 60, GreenMask };

		// D
		m_word[11] = { 330, 60, 330, 300, BlueMask };
		m_word[12] = { 330, 300, 380, 300, BlueMask };
		m_word[13] = { 380, 300, 460, 240, BlueMask };
		m_word[14] = { 460, 240, 460, 120, BlueMask };
		m_word[15] = { 460, 120, 380, 60, BlueMask };
		m_word[16] = { 380, 60, 330, 60, BlueMask };

		// E
		m_word[17] = { 490, 60, 490, 300, 0xffff00 };
		m_word[18] = { 490, 60, 600, 60, 0xffff00 };
		m_word[19] = { 490, 180, 600, 180, 0xffff00 };
		m_word[20] = { 490, 300, 600, 300, 0xffff00 };
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
	void Game::Tick(float deltaTime)
	{
		for (linepoints linepoint : m_word) {
			screen->Line(linepoint.x1, linepoint.y1, linepoint.x2, linepoint.y2, linepoint.color);
		}
	}
};