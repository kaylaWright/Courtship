#include <iostream>
#include "SDL.h"

#define S_HEIGHT 600
#define S_WIDTH 800

//function prototypes
bool Init();
bool LoadMedia(std::string _str);
void Close();

//globals
SDL_Window *p_window = NULL;
SDL_Surface *p_surface = NULL;
SDL_Surface *p_picTest = NULL;

//this type of main is used because it's compatible across platforms.
int main(int argc, char **argv)
{
	if(!Init())
	{
		printf("Nope nope nope.");
	}
	else
	{
		if(!LoadMedia("Bling."))
		{
			printf("Nope nope nope.");
		}
		else
		{
			SDL_BlitSurface(p_picTest, NULL, p_surface, NULL);
			SDL_UpdateWindowSurface(p_window);
			SDL_Delay(3000);
		}
	}

	return 0;
}

bool Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
	else
	{
		p_window = SDL_CreateWindow("Courtship", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN );
		
		if(p_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			p_surface = SDL_GetWindowSurface(p_window);
			return true;
		}
	}


	Close();
	return false;
}

bool LoadMedia(std::string _str)
{
	p_picTest = SDL_LoadBMP("media/yee.bmp");

	if(p_picTest == NULL)
	{
		printf("Can't load your yee! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	
	return true;
}

void Close()
{
	SDL_FreeSurface(p_picTest);
	p_picTest = NULL;

	SDL_DestroyWindow(p_window);
	p_window = NULL;

	SDL_Quit();
}