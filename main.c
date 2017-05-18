#include "./SDL2-2.0.5/include/SDL.h"
#include "rt.h"

void	test()
{
	t_cam	*cam;
	t_vec	*vec_dir;

	cam->view->width = WIDTH/1000;
	cam->view->height = HEIGHT/1000;
	cam->view->dist = 1;
	cam->ptn->x = -1;
	cam->ptn->y = 0;
	cam->ptn->z = 0;
	vec_dir->x = cam->view->dist;
	vec_dir->y = 0;
	vec_dir->z = 0;

	return ;
}

int		main(void)
{
	SDL_Window	*win;
	SDL_Event	event;
	SDL_Renderer *renderer;
	int			run;

	run = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL)
	{
		SDL_Quit();
		return (EXIT_FAILURE);
	}
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	test();
	for (int i = 0; i < 500; i++) {
		SDL_SetRenderDrawColor(renderer, i > 255 ? i/2 : i, 0, i > 255 ? i/2 : i, 255);
		SDL_RenderDrawPoint(renderer, i, i);		
	}
	SDL_RenderPresent(renderer);
	while (run)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			run = 0;
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}