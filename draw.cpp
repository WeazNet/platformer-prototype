#include "draw.h"

Draw::Draw(SDL_Renderer* &r) {
    ren=r;
}
Draw::~Draw() {
}

SDL_Rect Draw::initText(const char* text, int r, int g, int b, int a, TTF_Font* font, SDL_Rect origin, Object &parentClass, std::string orientation, bool first, std::tuple<int,int>spacing) {
    int spacingX, spacingY;
    std::tie(spacingX, spacingY) = spacing;
    SDL_Color color;
    color.r=r; color.g=g; color.b=b; color.a=a;
    SDL_Surface* surf;
    SDL_Texture* tex;
    surf = TTF_RenderText_Blended(font, text, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    origin.w=surf->w; origin.h=surf->h;
    origin.y+=origin.h+spacingY;
    if(orientation == "bottom") {
        if(first) {
            origin.y=parentClass.getDY()+spacingY;
            origin.x+=spacingX;
        }
        if(origin.w > parentClass.getDW()-spacingX) parentClass.setDW(origin.w+2*spacingX);
        if(!first) {
            parentClass.setDH(origin.y-parentClass.getDY()+origin.h+spacingY);
        } else {
            parentClass.setDH(origin.h+spacingY);
        }
    }
    else if(orientation == "bottom_right") {
        origin.x = origin.x+parentClass.getDX()+spacingX;
        origin.y = origin.y+parentClass.getDY()+spacingY;
    }
    SDL_FreeSurface(surf);
    surf=NULL;
    SDL_RenderCopy(ren, tex, NULL, &origin);
    SDL_DestroyTexture(tex);
    tex=NULL;
    if(Debug::isActive()) Debug::frameIncrement();
    return origin;
}

void Draw::initObject(Object &o) {
    SDL_Rect src = o.getSrc();
    SDL_Rect dest = o.getDest();
    if(Debug::isActive()) Debug::frameIncrement();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

SDL_Rect Draw::initObject(Object &o, Object &parentClass, std::string orientation, SDL_Rect origin, int spacing) {
    if(orientation=="right") {
        o.setDest(parentClass.getDX()+origin.x+spacing, parentClass.getDY()+spacing, o.getSrc().w, o.getSrc().h);
        origin.x += o.getSrc().w + 2*spacing;
    }
    else {
        std::cout << "Error: orientation initObject() not valid." << std::endl;
        SDL_Rect rect = {};
        return rect;
    }
    initObject(o);
    return origin;
}

void Draw::initFileConfig(std::string filename, std::vector<char>heights, int w, int h, int x, int y) {
    std::ofstream file {filename, std::ios::app};
    file << x << " " << y << '\n' << w << " " << h << '\n';
    for(auto height : heights) {
        file << height << " ";
    }
}

void Draw::initFile(Tile &o, std::string filename) {
    std::ofstream file {filename, std::ios::app};
        file << o.getType() << " ";     
}

void Draw::removeFile(const char* filename) {
    if (auto f = fopen(filename, "r")) {
        fclose(f);
        remove(filename);
    }
}

void Draw::removeFileRect(std::string filename, int widthFile, SDL_Rect &rect) {
}

void Draw::initFileSpace(std::string filename) {
    std::ofstream file{filename, std::ios::app};
    file << '\n';
}
