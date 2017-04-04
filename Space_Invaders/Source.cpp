//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "PlayerInfo.h"
#include "SDL_StructGlobalVariables.h"
#include "InitializeAndLoadWindow.h"
#include "PlayerShip.h"
#include "ShipBullets.h"
#include "WhiteEnemy.h"
#include "GreenEnemy.h"
#include "BlueEnemy.h"

using namespace std;

//Decleration of the global variables
SDL_Window* game_window = NULL;
SDL_Surface* screen_surface = NULL;
SDL_Texture* game_texture = NULL;
SDL_Renderer* game_renderer = NULL;

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

void SaveProfileWithNewScore(PlayerInfo& player_inf, ShipBullets& ship_bull);

int main(int argc, char* args[])
{		
	cout << "Welcome to Space Invaders!\n";

	SDL_Delay(1000);

	//Initialization of game objects
	InitializeAndLoadWindow start;
	ShipBullets ship_bullets;
	PlayerShip* player_ship = &ship_bullets;
	WhiteEnemy* white_enemy = &ship_bullets;
	GreenEnemy* green_enemy = &ship_bullets;
	BlueEnemy* blue_enemy = &ship_bullets;

	//Player input states
	const Uint8* PLAYER_INPUT = SDL_GetKeyboardState(NULL);
	
	int n = 1;

	//Start up SDL and intialize window
	if (!start.InitializeSDLWindow())
	{
		cout << "Failed to initialize!\n";
	}
	else
	{
		//Load media
		if (!start.LoadBackGround())
		{
			cout << "Failed to load media!\n";
		}
		else
		{
			//Main loop flag
			bool quit_game = false;

			//Event handler
			SDL_Event event;

			//While application is running
			while (!quit_game)
			{
				//Handle events on queue
				while (SDL_PollEvent(&event) != 0)
				{
					//User requests quit
					if ((event.type == SDL_QUIT) || (event.key.keysym.sym == SDLK_x))
					{
						quit_game = true;
					}		
				}
				//Delays the screen by 1000/4 of a second
				SDL_Delay(4);

				//Set the Enemy position
				white_enemy->SetWhiteEnemy();
				green_enemy->SetGreenEnemy();
				blue_enemy->SetBlueEnemy();
				blue_enemy->ShootBlueBullets();

				//Set a random enemy to shoot each time
				blue_enemy->RandomNum();

				if (PLAYER_INPUT[SDL_SCANCODE_LEFT] || PLAYER_INPUT[SDL_SCANCODE_A])
				{
					//Moves player ship to the left
					player_ship->MoveShip(1);
				}
				if (PLAYER_INPUT[SDL_SCANCODE_RIGHT] || PLAYER_INPUT[SDL_SCANCODE_D])
				{
					//Moves player ship to the right
					player_ship->MoveShip(2);
				}
				if (PLAYER_INPUT[SDL_SCANCODE_SPACE])
				{
					ship_bullets.ShootBulltes();
				}

				//Clear screen
				SDL_RenderClear(game_renderer);

				//Render texture to screen
				SDL_RenderCopy(game_renderer, game_texture, NULL, NULL);

				/*It is important in what order the 
				textures and rects are rendered to the
				screen*/

				//This allows the green/blue enemies to move left
				//and right in proper sequence and time
				n++;
				if ((n % 5 == 0) && n < 200)
				{
					green_enemy->MoveGreenEnemyRight();
					blue_enemy->MoveBlueEnemyLeft();
				}
				if ((n >= 200) && n % 5 == 0)
				{
					green_enemy->MoveGreenEnemyLeft();
					blue_enemy->MoveBlueEnemyRight();
					if (n == 400)
					{
						n = 0;
					}
				}

				blue_enemy->MoveBlueBullets();
				ship_bullets.MoveBulletsUp();
				ship_bullets.CheckCollisionWithEnemy();
				blue_enemy->CheckCollisionWithPlayer();

				//Render screen elements
				player_ship->RenderShip();
				ship_bullets.RenderBullets();
				white_enemy->RenderEnemy();
				green_enemy->RenderEnemy();
				blue_enemy->RenderEnemy();
				blue_enemy->RenderBlueBullets();

				if (ship_bullets.GetScore() == 900)
				{
					//End Game
					quit_game = true;
				}

				//Update screen
				SDL_RenderPresent(game_renderer);
			}
		}
	}
	//Close Game
	start.CloseWindow();

	cout << "\nYour score was: " << ship_bullets.GetScore() << endl;

	//Objects of player and intialization
	PlayerInfo player_info;

	char y_n_answer;
	cout << "\nCreate a profile?\n";
	cout << "Y/N: ";
	cin >> y_n_answer;
	if(toupper(y_n_answer) == 'Y')
	{
		if (player_info.CreateNewProfile())
		{
			SaveProfileWithNewScore(player_info, ship_bullets);
		}
		else
		{
			//Quit game
			cout << "Bye!" << endl;
			return 0;
		}
	}

	player_info.InsertProfilesToVector();
	cout << "\nDo you want to sort the list of players and scores?\n";
	cout << "Y/N: ";
	cin >> y_n_answer;
	if (toupper(y_n_answer) == 'Y')
	{
		player_info.SortProfiles();
	}
	else
	{
		cout << "Bye!" << endl;
	}

	return 0;
}

void SaveProfileWithNewScore(PlayerInfo& player_inf,ShipBullets& ship_bull)
{
	//Add the acumulated score to the current player
	player_inf.SetCurrentScore(ship_bull.GetScore());
	player_inf.CompareScores();
	//Save current player profile to file
	player_inf.SaveCurrPlayerToFile();
}