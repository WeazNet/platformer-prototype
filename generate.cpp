#include "generate.h"

Generate::Generate(SDL_Renderer* &r) {
    ren=r;
    draw = new Draw(ren);

    Air.setType(NONE);
    Stone.setType(STONE);
    Dirt.setType(DIRT);
    Grass.setType(GRASS);
    width = 100;
    height = 50;
    heightAirAdded = 20;
    srand(time(NULL));

    Generation("world");
}

Generate::~Generate() {
    deleteAll(draw);
}

std::string Generate::GenerationTmp(std::string filename) {
    filename += "-tmp.map";
    draw->removeFile(filename.c_str());
    distance=height;
    for(int i=0; i < width; i++) {
        int drawed = 0;
        int lowerNum = distance - 1;
        int heigherNum = distance + 2;
        distance = rand()%(heigherNum-lowerNum) + lowerNum;
        space = rand()%(30-14) + 14;
        int stoneSpace = distance - space;

        for(int j = 0; j < stoneSpace; j++) {
            draw->initFile(Stone, filename);
            drawed++;
        }

        for(int j=stoneSpace; j < distance; j++) {
            draw->initFile(Dirt, filename);
            drawed++;
        } 
        draw->initFile(Grass, filename);
        drawed++;
        while(drawed < height+heightAirAdded) {
            draw->initFile(Air, filename);
            drawed++;
        }
        draw->initFileSpace(filename);
    }
    return filename;
}

void Generate::Generation(std::string filename) {
    std::string tmp = GenerationTmp(filename);
    filename += ".map";
    std::ifstream file(tmp);
    std::string str;
    std::vector<std::string> lines;
    while(getline(file, str)) {
       str.erase(std::remove(str.begin(), str.end(), ' '), str.end()); 
       lines.push_back(str);
    }
    std::vector<char> heights;
    int i = 0;
    while(i < height+heightAirAdded) {
        for(int j=0; j<(int)lines.size(); j++) {
            heights.push_back(lines[j][i]);
        }
        i++;
    }
    std::reverse(heights.begin(), heights.end());

    draw->removeFile(filename.c_str());
    draw->initFileConfig(filename, heights, width, height+heightAirAdded);
}