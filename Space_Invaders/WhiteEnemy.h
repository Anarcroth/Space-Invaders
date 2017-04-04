#pragma once
#ifndef __WHITEENEMY_H_INCLUDED__
#define __WHITEENEMY_H_INCLUDED__
#include <SDL.h>
#include <vector>
#include "GenericEnemy.h"

class WhiteEnemy : public GenericEnemy
{
public:
	WhiteEnemy();

	virtual void RenderEnemy();
	void SetWhiteEnemy();

protected:
	SDL_Rect white_enemy[10];
	static const short int WHITE_ENEMY_SIZE = 15;

};
#endif // !__WHITEENEMY_H_INCLUDED__

