#include <iostream>
#include "SDL.h"

const int Width = 640;
const int Height = 480;

SDL_Window* window = NULL;
SDL_Surface* Current = NULL;
SDL_Surface* ButtonChanging[5];


void init() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else {
        window = SDL_CreateWindow("Game: Touch everything you see on the screen", 500, 330, Width, Height, SDL_WINDOW_SHOWN);
        Current = SDL_GetWindowSurface(window);
    }
}

void loadMedia()
{
    ButtonChanging[0] = SDL_LoadBMP("12/Click.bmp");
    ButtonChanging[1] = SDL_LoadBMP("12/W,world.bmp");
    ButtonChanging[2] = SDL_LoadBMP("12/S,world.bmp");
    ButtonChanging[3] = SDL_LoadBMP("12/A,world.bmp");
    ButtonChanging[4] = SDL_LoadBMP("12/D,world.bmp");
}

void close()
{ 
    for (int i = 0; i < 5; i++) {
        SDL_FreeSurface(ButtonChanging[i]);
        ButtonChanging[i] = NULL;
    }
    SDL_FreeSurface(Current);
    Current = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}


int main(int argc, char* args[]) {
    std::cout << "Boom" << std::endl;
    init();
    loadMedia();
    SDL_UpdateWindowSurface(window);
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {

                case SDLK_e:
                    SDL_BlitSurface(ButtonChanging[0], NULL, Current, NULL);
                    break;
                case SDLK_s:
                    SDL_BlitSurface(ButtonChanging[1], NULL, Current, NULL);
                    break;
                case SDLK_a:
                    SDL_BlitSurface(ButtonChanging[2], NULL, Current, NULL);
                    break;
                case SDLK_d:
                    SDL_BlitSurface(ButtonChanging[3], NULL, Current, NULL);
                    break;    
                case SDLK_w:
                    SDL_BlitSurface(ButtonChanging[4], NULL, Current, NULL);
                    break;
                }
                SDL_UpdateWindowSurface(window);
            }
        }
    }
    close();
    return 0;
}
