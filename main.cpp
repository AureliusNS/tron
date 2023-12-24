#include <SDL.h>

int windowInit() {
    // SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize! SDL_Error %s\n", SDL_GetError());
        return 1;
    }

    // Create SDL window and render
    SDL_Window* window = SDL_CreateWindow("Tron v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game loop
    bool quit = false;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Game logic and rendering
        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        SDL_RenderClear(renderer);

        // Draw game element
        SDL_RenderPresent(renderer);
    }

    // Clean up and close SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


}

int main() {
    windowInit();
    return 0;
}
