#include "game.h"

Game::Game(SDL_Window* &window, SDL_Renderer* &renderer) {
    w=window;
    ren=renderer;
    running=true;
    
    rect.x=rect.y=0;
    rect.w=WIDTH;
    rect.h=HEIGHT;

    draw = new Draw(ren);

    Generate gen(ren);

    Debug::activate(true);
    debugInterface = new DebugInterface(ren);

    map = new Map(ren);
    map->load("resources/tile_set.png", "world.map");

    camera = new Camera(ren);

    player = new Player(ren);

    inventory = new Inventory(ren);

    loop();
}

Game::~Game() {
    deleteAll(draw);
    deleteAll(debugInterface);
    deleteAll(map);
    deleteAll(camera);
    deleteAll(player);
    deleteAll(inventory);
    
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
            if(Debug::isActive()) Debug::clearFrameCount();
        }
        input();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if((1000/60) > frameTime) {
            SDL_Delay((1000/60)-frameTime);
        }
        if(Debug::isActive()) Debug::hydrateFPS(1000/frameTime);
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 126, 192, 238, 255);
    SDL_RenderFillRect(ren, &rect);

    map->draw();
    draw->initObject(*player);
    if(Debug::isActive()) Debug::addColliders(collisions);
    debugInterface->showCollidersBox();
    player->tileInteractivity(Map::getMapNearby(player->getDest()));
    inventory->render();
    debugInterface->render();
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
    collisions.clearColliders();
    player->update();
    camera->updatePlayerPositionInMap(map, player);
    player->updateAnimation();
    collisions.addCollider(*player);
    collisions.update(*player, Map::getMap());
    if(player->isFall()) {
        player->setDest(player->getDX(), player->getDY()+player->getVGrav());
    }
}