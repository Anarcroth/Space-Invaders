#pragma once
#ifndef __PLAYERSHIP_H_INCLUDED__
#define __PLAYERSHIP_H_INCLUDED__
#include <SDL.h>

class PlayerShip
{
public:
	PlayerShip();

	void RenderShip();
	void MoveShip(int n);

protected:
	short unsigned int player_health;
	SDL_Rect player_ship;
};
#endif // !__PLAYERSHIP_H_INCLUDED__