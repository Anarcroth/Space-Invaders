#include "SDL_StructGlobalVariables.h"
#include "ShipBullets.h"
#include <iostream>

ShipBullets::ShipBullets():bullets_count(0), previous_shot(0), current_shot(1), score(0)
{
	//...
}

void ShipBullets::MoveBulletsUp()
{
	for (int i = 0; i < bullets_count; i++)
	{
		bullets[i].y--;
	}
}

void ShipBullets::ShootBulltes()
{
	//The if statements check if there are enough bullets and 
	//spaces them out so they do not come out as a whole line
	if ((bullets_count < 1000) && (((current_shot = std::clock()) - previous_shot) / ((double)CLOCKS_PER_SEC / 1000)) > 200)
	{
		previous_shot = current_shot;
		bullets[bullets_count] = { player_ship.x + 20, player_ship.y - BULLET_SIZE, BULLET_SIZE, BULLET_SIZE };
		++bullets_count;
	}
}

void ShipBullets::RenderBullets()
{
	for (int i = 0; i < bullets_count; i++)
	{
		SDL_SetRenderDrawColor(game_renderer, 0xFF, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(game_renderer, &bullets[i]);
	}
}

void ShipBullets::CheckCollisionWithEnemy()
{
	for (int i = 0; i < bullets_count; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//The if statements check the collison on the .y level of the enemies + the .x and .w values between the bullet and the enemy
			if (bullets[i].y == white_enemy[j].y + white_enemy[j].h && ((bullets[i].x >= white_enemy[j].x - 8) && (bullets[i].x + bullets[i].w <= white_enemy[j].x + white_enemy[j].w + 8)))
			{
				bullets[i].x *= 100;
				white_enemy[j].x *= 100;
				score += 10;
			}

			//The if statements check the collison on the .y level of the enemies + the .x and .w values between the bullet and the enemy
			if (bullets[i].y == green_enemy[j].y + green_enemy[j].h && ((bullets[i].x >= green_enemy[j].x - 8) && (bullets[i].x + bullets[i].w <= green_enemy[j].x + green_enemy[j].w + 8)))
			{
				bullets[i].x *= 100;
				green_enemy[j].x *= 100;
				score += 30;
			}

			//The if statements check the collison on the .y level of the enemies + the .x and .w values between the bullet and the enemy
			if (bullets[i].y == blue_enemy[j].y + blue_enemy[j].h && ((bullets[i].x >= blue_enemy[j].x - 8) && (bullets[i].x + bullets[i].w <= blue_enemy[j].x + blue_enemy[j].w + 8)))
			{
				bullets[i].x *= 100;
				blue_enemy[j].x *= 100;
				score += 50;
			}
		}
	}
}

int ShipBullets::GetScore()
{
	return score;
}
