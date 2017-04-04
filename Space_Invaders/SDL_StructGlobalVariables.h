#pragma once
#ifndef __SDL_STRUCTGLOBALVARIABLES_H_INCLUDED__
#define __SDL_STRUCTGLOBALVARIABLES_H_INCLUDED__

#include <SDL.h>

//External global declerations accessible by every file
extern SDL_Window* game_window;
extern SDL_Surface* screen_surface;
extern SDL_Texture* game_texture;
extern SDL_Renderer* game_renderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

#endif // !__SDL_STRUCTGLOBALVARIABLES_H_INCLUDED__