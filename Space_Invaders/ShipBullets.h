#pragma once
#ifndef __SHIPBULLETS_H_INCLUDED__
#define __SHIPBULLETS_H_INCLUDED__
#include <SDL.h>
#include <ctime>
#include "WhiteEnemy.h"
#include "GreenEnemy.h"
#include "BlueEnemy.h"
#include "PlayerShip.h"

class ShipBullets : virtual public PlayerShip, public WhiteEnemy, public GreenEnemy, public BlueEnemy
{
public:
	ShipBullets();

	void MoveBulletsUp();
	void ShootBulltes();
	void RenderBullets();
	void CheckCollisionWithEnemy();
	int GetScore();

protected:
	SDL_Rect bullets[1000];
	static const short int BULLET_SIZE = 10;
	short int bullets_count;
	clock_t previous_shot;
	clock_t current_shot;
	short int score;
};


#endif // !__SHIPBULLETS_H_INCLUDED__

