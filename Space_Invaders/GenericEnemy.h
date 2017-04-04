#pragma once
#ifndef __GENERICENEMY_H_INCLUDED__
#define __GENERICENEMY_H_INCLUDED__

class GenericEnemy
{
public:
	virtual void RenderEnemy() = 0;

protected:
	short int enemy_count;
	short int enemy_health;
	short int x_enemy_pos;
	short int y_enemy_pos;
};
#endif // !__GENERICENEMY_H_INCLUDED__


