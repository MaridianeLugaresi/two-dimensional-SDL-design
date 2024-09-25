#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stack>
#include <sstream>
#include <unistd.h>

#include<Context.h>
#include<Color.h>
#include<Point.h>
#include<Line.h>
#include<Ramp.h>
#include<Car.h>

// SDL stuff
SDL_Window* pWindow = nullptr;
SDL_Renderer* pRenderer = nullptr;
SDL_Surface * window_surface = nullptr;

void display(Car &car)
{

    Ramp ramp = Ramp();
    ramp.draw();

    car.draw();
    car.updatePosition();

}

void clear() {

    Line l = Line();
    SDL_Surface * window_surface = Context::getInstance()->getWindowSurface();
    for(int x = 0;x < window_surface->w; x++){
        for(int y = 0;y < window_surface->h; y++) {
            l.setPixel(x, y, 255, 255, 255);
        }
    }

}

// Driver code
int main(int argc, char* args[])
{

	SDL_Event event;

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		pWindow = SDL_CreateWindow("SDL_Classes",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
														640, 480,
												SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (pWindow != 0) {
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
			window_surface = SDL_GetWindowSurface(pWindow);

            // Inicializa o contexto gráfico da aplicação
			Context * context = Context::getInstance();
			context->setRenderer(pRenderer);
			context->setWindowSurface(window_surface);

        }

	}
	else
		return 1; // sdl could not initialize

    Car car = Car();

	while (1)
	{

        // Limpa a tela
        clear();

        // Realiza o desenho
        display(car);

        // Aguarda instantes
        usleep(100000);

		// Verifica se foi mandado fechar a janela
		while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }

        }

		// Atualiza a tela
		SDL_UpdateWindowSurface(pWindow);
	}

	// clean up SDL
	SDL_Quit();
	return 0;
}
