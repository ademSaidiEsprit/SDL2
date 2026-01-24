#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_Window *window = SDL_CreateWindow(
        "Background SDL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    /* Charger l'image */
    SDL_Surface *surface = IMG_Load("3d-rendering-hexagonal-texture-background.jpg");
    if (!surface) return 1;

    SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        /* Effacer l'écran */
        SDL_RenderClear(renderer);

        /* Afficher l'image en arrière-plan */
        SDL_RenderCopy(renderer, background, NULL, NULL);

        /* Afficher à l'écran */
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
