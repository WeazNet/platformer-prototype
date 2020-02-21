#include "game.h"

Game::Game(SDL_Window* &window, SDL_Renderer* &renderer) {
    w=window;
    ren=renderer;
    running=true;

    map = new Map(ren);
    map->loadTileset("res/tileset.png");
    map->load("map", "levels/1.level", TILE_SIZE, 1);
    map->load("minimap", "levels/1.level", TILE_SIZE/4, 0);

    draw = new Draw(ren);

    player = new Player(ren);

    debugger = new Debugger(ren);
    debugger->activate(true);
    loop();
}

Game::~Game() {
    debugger=NULL;draw=NULL;map=NULL;player=NULL;
    delete debugger;
    delete draw;
    delete map;
    delete player;
    IMG_Quit();
    SDL_DestroyWindow(w);
    SDL_RenderClear(ren);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

void Game::loop() {
    int static lastTime = 0;
    while(running) {
        lastFrame = SDL_GetTicks();
        if(lastTime >= (lastTime+1000)) {
            lastTime=lastFrame;
            frameCount=0;
        }

        input();
        update();
        render();
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 140, 140, 140, 255);
    SDL_Rect rect;
    rect.x=rect.y=0;
    rect.w=WIDTH;
    rect.h=HEIGHT;
    SDL_RenderFillRect(ren, &rect);

    /*************/
    utils.addEntity(*player);
    debugger->viewCollidersBox(true, utils);
    utils.clearEntities();
    
    map->draw("map");
    map->draw("minimap");
    draw->init(*player);
    /*************/
    frameCount++;
    FPS = SDL_GetTicks() - lastFrame;
    if(FPS < (1000/60)) {
        SDL_Delay((1000/60)-FPS);
    }
    SDL_RenderPresent(ren);
}

void Game::input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) running=false;
        player->input(e);
    }
}

void Game::update() {
    player->update();
    player->updateAnimation();
    map->updateCollision(player);
    if(player->isFall()) {
        player->setDest(player->getDX(), player->getDY()+player->getVGrav());
    }
}