#include "include/Window.h"
#include "include/TestClass.h"
#include <SDL2/SDL.h>

int main() {
    // Inicializace SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Vytvoření instance třídy Window
    Window window("USB Manager", 800, 600);

    // Otevření okna
    window.Open();

    // Smyčka událostí
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Zavření okna
    window.Close();

    // Ukončení SDL
    SDL_Quit();

    return 0;
}
