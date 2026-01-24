#include <SDL2/SDL.h>

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *w = SDL_CreateWindow(
        "SDL OK",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        870, 870,
        SDL_WINDOW_SHOWN // <- Important
    );

    if (!w) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(20000); // wait
    SDL_DestroyWindow(w);
    SDL_Quit();
    return 0;
}

