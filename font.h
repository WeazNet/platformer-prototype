#ifndef FONT_H
#define FONT_H

#define FONT_SIZE_NORMAL 16

#include <SDL2/SDL_ttf.h>
#include <iostream>

class Font {
private:
    static TTF_Font* regular;
    static TTF_Font* italic;
    static TTF_Font* bold;
public:
    Font();
    ~Font();
    static TTF_Font* getRegular();
    static TTF_Font* getItalic();
    static TTF_Font* getBold();
};
#endif//FONT_H