#pragma once
#ifndef __INITIALIZEANDLOADWINDOW_H_INCLUDED__
#define __INITIALIZEANDLOADWINDOW_H_INCLUDED__
#include <SDL.h>
#include <string>

class InitializeAndLoadWindow
{
public:
	bool InitializeSDLWindow();
	bool LoadBackGround();
	SDL_Texture* LoadTexture(std::string path);
	void CloseWindow();

};
#endif // !__INITIALIZEANDLOADWINDOW_H_INCLUDED__