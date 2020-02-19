#include "draw.h"

Draw::Draw(SDL_Renderer* r) {
    ren=r;
    font = TTF_OpenFont("res/font.ttf", 20);
}
Draw::~Draw() {
    TTF_CloseFont(font);
}

void Draw::init(const char* text, int x, int y, int r, int g, int b, int a) {
    SDL_Color color;
    color.r=r; color.g=g; color.b=b; color.a=a;
    SDL_Surface* surf;
    SDL_Texture* tex;
    surf = TTF_RenderText_Solid(font, text, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_Rect rect;
    rect.x=x; rect.y=y; rect.w=surf->w; rect.h=surf->h;
    SDL_RenderCopy(ren, tex, NULL, &rect);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(surf);
}

void Draw::init(Object o) {
    SDL_Rect src = o.getSrc();
    SDL_Rect dest = o.getDest();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}