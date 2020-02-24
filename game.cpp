#include "game.h"

Game::Game(SDL_Window* &window, SDL_Renderer* &renderer) {
    w=window;
    ren=renderer;
    running=true;
    
    rect.x=rect.y=0;
    rect.w=WIDTH;
    rect.h=HEIGHT;

    debug = new Debug(ren);
    debug->activate(true);
    debugInterface = new DebugInterface(ren, debug);

    map = new Map(ren, debug);
    map->load("res/tileset.png", "world.map", TILE_SIZE);

    player = new Player(ren);

    draw = new Draw(ren, debug);
    loop();
}

Game::~Game() {
    debug=NULL;debugInterface=NULL;draw=NULL;map=NULL;player=NULL;
    delete debug;
    delete debugInterface;
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
    Uint32 frameStart;
    float static frameTime = 0;
    while(running) {
        frameStart = SDL_GetTicks();
        if(frameStart >= (frameTime+1000)) {
            frameTime=frameStart;
            debug->clearFrameCount();
        }
        input();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if((1000/60) > frameTime) {
            SDL_Delay((1000/60)-frameTime);
        }
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 140, 140, 140, 255);
    SDL_RenderFillRect(ren, &rect);

    map->draw();
    draw->initObject(*player);
    collisions.addCollider(*player);
    debug->addColliders(collisions);
    debug->showCollidersBox();
    collisions.clearColliders();
    debugInterface->render(draw);

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
    collisions.update(*player, map->getMap());
    if(player->isFall()) {
        player->setDest(player->getDX(), player->getDY()+player->getVGrav());
    }
}