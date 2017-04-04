#pragma once
#ifndef __BLUEENEMY_H_INCLUDED__
#define __BLUEENEMY_H_INCLUDED__
#include <SDL.h>
#include <ctime>
#include "GenericEnemy.h"
#include "PlayerShip.h"

class BlueEnemy : public GenericEnemy, virtual public PlayerShip
{
public:
	BlueEnemy();

	virtual void RenderEnemy();
	void SetBlueEnemy();
	void MoveBlueEnemyRight();
	void MoveBlueEnemyLeft();
	void MoveBlueBullets();
	void ShootBlueBullets();
	void RenderBlueBullets();
	void RandomNum();
	void CheckCollisionWithPlayer();

protected:
	SDL_Rect blue_enemy[10];
	SDL_Rect blue_bullets[1000];
	short int bullets_count;
	clock_t previous_shot;
	clock_t current_shot;
	int random;
	static const short int BULLET_SIZE = 10;
	static const short int BLUE_ENEMY_SIZE = 10;
};	
#endif // !__BLUEENEMY_H_INCLUDED__


