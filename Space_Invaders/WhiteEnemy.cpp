#include <iostream>
#include "WhiteEnemy.h"
#include "SDL_StructGlobalVariables.h"

WhiteEnemy::WhiteEnemy()
{
	enemy_count = 0;
	x_enemy_pos = 40;
	y_enemy_pos = 150;
}

void WhiteEnemy::RenderEnemy()
{
	for (int i = 0; i < enemy_count; i++)
	{
		SDL_SetRenderDrawColor(game_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(game_renderer, &white_enemy[i]);
	}
}

void WhiteEnemy::SetWhiteEnemy()
{
	for (; enemy_count < 10;)
	{
		white_enemy[enemy_count] = { x_enemy_pos, y_enemy_pos, WHITE_ENEMY_SIZE, WHITE_ENEMY_SIZE };
		++enemy_count;
		x_enemy_pos += 60;
	}
}
