#include "font.h"

Font::Font() {
    TTF_Init();
    regular = TTF_OpenFont("res/SF Pixelate.ttf", FONT_SIZE_NORMAL);
    italic = TTF_OpenFont("res/SF Pixelate Oblique.ttf", FONT_SIZE_NORMAL);
    bold = TTF_OpenFont("res/SF Pixelate Bold.ttf", FONT_SIZE_NORMAL);
}

Font::~Font() {
    TTF_CloseFont(regular);
    TTF_CloseFont(italic);
    TTF_CloseFont(bold);
    TTF_Quit();
}

TTF_Font* Font::getRegular() {
    if(regular == NULL) cout << TTF_GetError() << endl;
    return regular;
}

TTF_Font* Font::getItalic() {
    if(italic == NULL) cout << TTF_GetError() << endl;
    return italic;
}

TTF_Font* Font::getBold() {
    if(bold == NULL) cout << TTF_GetError() << endl;
    return bold;
}