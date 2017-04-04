#include "SDL_StructGlobalVariables.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip() :player_health(3)
{
	player_ship.x = SCREEN_WIDTH / 2;
	player_ship.w = 50;
	player_ship.h = 25;
	player_ship.y = SCREEN_HEIGHT - player_ship.h;
}

void PlayerShip::RenderShip()
{
	SDL_SetRenderDrawColor(game_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(game_renderer, &player_ship);
}

void PlayerShip::MoveShip(int n)
{
	if (n == 1)
	{
		//Move to the left
		player_ship.x -= 1;
		//Prevent player from exiting the screen
		if (player_ship.x < 0)
		{
			//Move back
			player_ship.x += 1;
		}
	}
	else if (n == 2)
	{
		//Move to the right
		player_ship.x += 1;
		//Prevent the player from exiting the screen
		if (player_ship.x + player_ship.w > SCREEN_WIDTH)
		{
			//Move back
			player_ship.x -= 1;
		}
	}
}