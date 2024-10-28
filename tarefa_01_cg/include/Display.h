#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <stdexcept>

class Display {
public:
    Display(int width, int height);
    ~Display();
    void clear();
    void present();
    void drawPoint(int x, int y, SDL_Color color);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // DISPLAY_H
