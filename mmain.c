#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 MP3",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture *background = IMG_LoadTexture(renderer, "palestine2.jpg");

    Mix_Music *music = Mix_LoadMUS("palestine.mp3");

    TTF_Font *font = TTF_OpenFont("arial.ttf", 40);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Bonjour SDL2", white);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {200, 250, textSurface->w, textSurface->h};

    int running = 1;
    int showText = 0;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                showText = 1;
                Mix_PlayMusic(music, -1);
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);

        if (showText)
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(background);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    Mix_FreeMusic(music);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

