#include <iostream>
#include "GreenEnemy.h"
#include "SDL_StructGlobalVariables.h"

GreenEnemy::GreenEnemy()
{
	enemy_count = 0;
	x_enemy_pos = 35;
	y_enemy_pos = 90;
}

void GreenEnemy::RenderEnemy()
{
	for (int i = 0; i < enemy_count; i++)
	{
		SDL_SetRenderDrawColor(game_renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(game_renderer, &green_enemy[i]);
	}
}

void GreenEnemy::SetGreenEnemy()
{
	for (; enemy_count < 10;)
	{
		green_enemy[enemy_count] = { x_enemy_pos, y_enemy_pos, GREEN_ENEMY_SIZE, GREEN_ENEMY_SIZE };
		++enemy_count;
		x_enemy_pos += 65;
	}
}

void GreenEnemy::MoveGreenEnemyRight()
{
	enemy_count = 0;
	for (; enemy_count < 10;)
	{
		if (green_enemy[9].x + green_enemy[9].w < SCREEN_WIDTH)
		{
			green_enemy[enemy_count].x += 1;
		}
		++enemy_count;
	}
}

void GreenEnemy::MoveGreenEnemyLeft()
{
	enemy_count = 0;
	for (; enemy_count < 10;)
	{
		if (green_enemy[0].x > 0)
		{
			green_enemy[enemy_count].x -= 1;
		}
		++enemy_count;
	}
}