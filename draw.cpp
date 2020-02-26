#include "draw.h"

Draw::Draw(SDL_Renderer* &r) {
    ren=r;
}
Draw::~Draw() {
}

tuple<int, int, int> Draw::initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, tuple<int,int,int>origin) {
    int originX, originY, rectW;
    tie(originX, originY, rectW) = origin;
    SDL_Color color;
    color.r=r; color.g=g; color.b=b; color.a=a;
    SDL_Surface* surf;
    SDL_Texture* tex;
    surf = TTF_RenderText_Blended(font, text, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_Rect rect;
    rect.x=x; rect.y=y+originY; rect.w=surf->w; rect.h=surf->h;
    SDL_FreeSurface(surf);
    surf=NULL;
    SDL_RenderCopy(ren, tex, NULL, &rect);
    SDL_DestroyTexture(tex);
    tex=NULL;
    if(Debug::isActive()) Debug::frameIncrement();
    return {rect.x, rect.y+rect.h, rect.w};
}

tuple<int, int, int> Draw::initText(const char* text, int x, int y, int r, int g, int b, int a, TTF_Font* font, tuple<int,int,int>origin, Object &parentClass, int spacing) {
    int posX, posY, w;
    tie(posX,posY,w) = initText(text, x, y, r, g, b, a, font, origin);
    if(parentClass.getDW() < posX+w+spacing && parentClass.getDH() < posY+spacing) {
        parentClass.setDest(parentClass.getDX(), parentClass.getDY(),  posX+w+spacing, posY+spacing);
    }
    else if(parentClass.getDW() < posX+w+spacing) {
        parentClass.setDest(parentClass.getDX(), parentClass.getDY(),  posX+w+spacing, parentClass.getDH());
    }
    else if(parentClass.getDH() < posY+spacing) {
        parentClass.setDest(parentClass.getDX(), parentClass.getDY(),  parentClass.getDW(), posY+spacing);
    }
    return tuple<int, int, int>(posX,posY,w);
}

void Draw::initObject(Object &o) {
    SDL_Rect src = o.getSrc();
    SDL_Rect dest = o.getDest();
    if(Debug::isActive()) Debug::frameIncrement();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Draw::initObject(Object &o, Object const &parentClass, int spacing) {
    o.setDest(parentClass.getDX()+parentClass.getDW()+o.getDX()+spacing, parentClass.getDY()+parentClass.getDH()+o.getDY()+spacing, o.getDW(), o.getDH());
    initObject(o);
}

void Draw::initFileConfig(string filename, vector<char>heights, int w, int h, int x, int y) {
    ofstream file {filename, ios::app};
    file << x << " " << y << '\n' << w << " " << h << '\n';
    for(auto height : heights) {
        file << height << " ";
    }
}

void Draw::initFile(Tile &o, string filename) {
    ofstream file {filename, ios::app};
        file << o.getType() << " ";     
}

void Draw::removeFile(const char* filename) {
    if (auto f = fopen(filename, "r")) {
        fclose(f);
        remove(filename);
    }
}

void Draw::initFileSpace(string filename) {
    ofstream file{filename, ios::app};
    file << '\n';
}
