using namespace std;
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "game.h"

void Destroy(SDL_Window* &w, SDL_Renderer* &ren) {
    SDL_DestroyWindow(w);
    SDL_DestroyRenderer(ren);
}

int main(int argc, char* argv[]) {
    SDL_Window* w;
    SDL_Renderer* ren;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        Destroy(w, ren);
        return EXIT_FAILURE;
    }
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &w, &ren) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        Destroy(w, ren);
        SDL_Quit();         
        return EXIT_FAILURE;
    }
    Game g(w, ren);
    return EXIT_SUCCESS;
}