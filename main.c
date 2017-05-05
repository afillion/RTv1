#include "./SDL2-2.0.5/include/SDL.h"

int		main(void)
{
	SDL_Window	*win;
	SDL_Event	event;
	int			run;

	run = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL)
	{
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	while (run)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			run = 0;
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
