#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include "color.h"
#include "picture.h"

class Picture;

class Screen {
private:
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    char *title;
    Color bgColor;
    void meanFilter();
    void gaussianFilter();
    void filter(double [3][3]);
    void updateScreen();
    int pitch;
    int numPixels;
    Uint32 *pixels;

public:
    Screen(const char *, const Color =BLACK, int = 800, int = 600);
    void setPixel(int, int, Uint8, Uint8, Uint8);
    void setPixel(int, int, Color);
    void update();
    void setBackColor(Color c);
    Color getBackColor() const { return bgColor; };
    int getWidth() const { return width; };
    int getHeight() const { return height; 	};
    ~Screen();
    void run(Picture &);
};

#endif