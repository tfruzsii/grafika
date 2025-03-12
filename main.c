#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Inicializálás
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init hiba: %s\n", SDL_GetError());
        return -1;
    }

    // Ablak létrehozása OpenGL kontextussal
    SDL_Window *window = SDL_CreateWindow("SDL2 + OpenGL Teszt", 
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        printf("SDL_CreateWindow hiba: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // OpenGL kontextus létrehozása
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        printf("SDL_GL_CreateContext hiba: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // OpenGL állapotok beállítása
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Háttérszín fekete

    // Fő ciklus
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Képernyő törlése
        glClear(GL_COLOR_BUFFER_BIT);

        // Absztrakt OpenGL kód ide jöhet (pl. objektumok rajzolása)
        glPushMatrix();
        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f); // Piros szín
        glVertex2f(-0.5f, -0.5f); // Bal alsó csúcs
        glVertex2f( 0.5f, -0.5f); // Jobb alsó csúcs
        glVertex2f( 0.5f,  0.5f); // Jobb felső csúcs
        glVertex2f(-0.5f,  0.5f); // Bal felső csúcs

        glEnd();

        glPopMatrix();

        // Képfrissítés
        SDL_GL_SwapWindow(window);
    }

    // Takarítás
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
