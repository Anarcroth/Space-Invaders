#pragma once
#ifndef __GREENENEMY_H_INCLUDED__
#define __GREENENEMY_H_INCLUDED__
#include <SDL.h>
#include "GenericEnemy.h"

class GreenEnemy : public GenericEnemy
{
public:
	GreenEnemy();

	virtual void RenderEnemy();
	void SetGreenEnemy();
	void MoveGreenEnemyRight();
	void MoveGreenEnemyLeft();

protected:
	SDL_Rect green_enemy[10];
	static const short int GREEN_ENEMY_SIZE = 15;
};
#endif // !_GREENENEMY_H_INCLUDED__


