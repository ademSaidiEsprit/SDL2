#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define SWITCH_TIME 10000  // 10 secondes (en ms)

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Sons alternés",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600, 400,
        0
    );

    /* Charger les sons */
    Mix_Music *sound1 = Mix_LoadMUS("sound1.mp3");
    Mix_Music *sound2 = Mix_LoadMUS("sound2.mp3");

    if (!sound1 || !sound2)
        return 1;

    Uint32 lastSwitch = SDL_GetTicks();
    int currentSound = 1;

    Mix_PlayMusic(sound1, -1); // jouer en boucle

    int running = 1;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        Uint32 now = SDL_GetTicks();

        /* Changement de son toutes les 10 secondes */
        if (now - lastSwitch >= SWITCH_TIME)
        {
            Mix_HaltMusic();

            if (currentSound == 1)
            {
                Mix_PlayMusic(sound2, -1);
                currentSound = 2;
            }
            else
            {
                Mix_PlayMusic(sound1, -1);
                currentSound = 1;
            }

            lastSwitch = now;
        }

        SDL_Delay(10);
    }

    Mix_FreeMusic(sound1);
    Mix_FreeMusic(sound2);
    Mix_CloseAudio();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
