#include <iostream>
#include "BlueEnemy.h"
#include "SDL_StructGlobalVariables.h"

BlueEnemy::BlueEnemy()
{
	enemy_count = 0;
	x_enemy_pos = 40;
	y_enemy_pos = 40;
	bullets_count = 0;
	previous_shot = 0;
	current_shot = 1;
}

void BlueEnemy::RenderEnemy()
{
	for (int i = 0; i < enemy_count; i++)
	{
		SDL_SetRenderDrawColor(game_renderer, 0x00, 0xA0, 0xFF, 0xFF);
		SDL_RenderFillRect(game_renderer, &blue_enemy[i]);
	}
}

void BlueEnemy::SetBlueEnemy()
{
	for (; enemy_count < 10;)
	{
		blue_enemy[enemy_count] = { x_enemy_pos, y_enemy_pos, BLUE_ENEMY_SIZE, BLUE_ENEMY_SIZE };
		++enemy_count;
		x_enemy_pos += 65;
	}
}

void BlueEnemy::MoveBlueEnemyRight()
{
	enemy_count = 0;
	for (; enemy_count < 10;)
	{
		if (blue_enemy[9].x + blue_enemy[9].w < SCREEN_WIDTH)
		{
			blue_enemy[enemy_count].x += 1;
		}
		++enemy_count;
	}
}

void BlueEnemy::MoveBlueEnemyLeft()
{
	enemy_count = 0;
	for (; enemy_count < 10;)
	{
		if (blue_enemy[0].x > 0)
		{
			blue_enemy[enemy_count].x -= 1;
		}
		++enemy_count;
	}
}

void BlueEnemy::MoveBlueBullets()
{
	for (int i = 0; i < bullets_count; i++)
	{
		blue_bullets[i].y++;
	}
}

void BlueEnemy::ShootBlueBullets()
{
	//The if statements check if there are enough bullets and 
	//spaces them out so they do not come out as a whole line
	if ((bullets_count < 1000) && (((current_shot = std::clock()) - previous_shot) / ((double)CLOCKS_PER_SEC / 1000)) > 1700)
	{
		previous_shot = current_shot;
		blue_bullets[bullets_count] = { blue_enemy[random].x , blue_enemy[random].y, BULLET_SIZE / 2, BULLET_SIZE };
		++bullets_count;
	}
}

void BlueEnemy::RenderBlueBullets()
{
	for (int i = 0; i < bullets_count; i++)
	{
		SDL_SetRenderDrawColor(game_renderer, 0x00, 0xA0, 0xFF, 0xFF);
		SDL_RenderFillRect(game_renderer, &blue_bullets[i]);
	}
}

void BlueEnemy::RandomNum()
{
	srand(time(0));
	random = rand() % 10;
}

void BlueEnemy::CheckCollisionWithPlayer()
{
	for (int i = 0; i < bullets_count; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//The if statements check the collison on the .y level of the enemies + the .x and .w values between the bullet and the enemy
			if (blue_bullets[i].y + blue_bullets[i].h == player_ship.y && ((blue_bullets[i].x >= player_ship.x) && (blue_bullets[i].x + blue_bullets[i].w <= player_ship.x + player_ship.w)))
			{
				player_health--;
				blue_bullets[i].x *= 50;
				if (player_health == 0)
				{
					blue_bullets[i].x *= 50;
					player_ship.x *= 50;
				}
			}
		}
	}
}

