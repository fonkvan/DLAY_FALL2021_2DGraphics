#include "SDL.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* Window = SDL_CreateWindow("Test Window", 300, 300, 300, 300, SDL_WINDOW_OPENGL);
	SDL_Delay(3000);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return(0);
}