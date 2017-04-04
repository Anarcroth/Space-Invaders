#include <SDL_image.h>
#include <iostream>
#include <string>
#include "SDL_StructGlobalVariables.h"
#include "InitializeAndLoadWindow.h"

bool InitializeAndLoadWindow::InitializeSDLWindow()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL couldn't initialize! SDL_Erro: %s\n" << SDL_GetError();
		success = false;
	}
	else
	{
		//Create window	
		game_window = SDL_CreateWindow("Space Ivaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (game_window == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError();
			success = false;
		}
		else
		{
			//Create renderer for the window
			game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);
			if (game_renderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: %s\n" << SDL_GetError();
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(game_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int image_flags = IMG_INIT_PNG;
				if (!(IMG_Init(image_flags) & image_flags))
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError();
					success = false;
				}
				else
				{
					//Get window surface
					screen_surface = SDL_GetWindowSurface(game_window);
				}
			}
		}
	}
	return success;
}

bool InitializeAndLoadWindow::LoadBackGround()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	game_texture = LoadTexture("BackGround.png");
	if (game_texture == NULL)
	{
		std::cout << "Failed to load PNG image!\n";
		success = false;
	}

	return success;
}

SDL_Texture* InitializeAndLoadWindow::LoadTexture(std::string path)
{
	//The final texture
	SDL_Texture* new_texture = NULL;

	//Load image at a specific path
	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == NULL)
	{
		std::cout << "Unable to load image %s! SDL_image Error: %s" << path.c_str() << IMG_GetError() << std::endl;
	}
	else
	{
		//Create texture from surface pixels
		new_texture = SDL_CreateTextureFromSurface(game_renderer, loaded_surface);
		if (new_texture == NULL)
		{
			std::cout << "Unable to optimize image %s! SDL Error: %s\n" << path.c_str() << SDL_GetError();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loaded_surface);
	}

	return new_texture;
}

void InitializeAndLoadWindow::CloseWindow()
{
	//Free loaded image
	SDL_DestroyTexture(game_texture);
	game_texture = NULL;

	//Destroy window
	SDL_DestroyWindow(game_window);
	game_window = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}