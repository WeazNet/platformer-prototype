#ifndef FONT_H
#define FONT_H

#define FONT_SIZE_NORMAL 16

#include <SDL2/SDL_ttf.h>
#include <iostream>

class Font {
private:
    TTF_Font* regular;
    TTF_Font* italic;
    TTF_Font* bold;
public:
    Font();
    ~Font();
    TTF_Font* getRegular();
    TTF_Font* getItalic();
    TTF_Font* getBold();
};
#endif//FONT_H