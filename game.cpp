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
    map->load("res/tileset.png", "world.map", TILE_SIZE);

    player = new Player(ren);

    loop();
}

Game::~Game() {
    deleteAll(draw);
    deleteAll(debugInterface);
    deleteAll(map);
    deleteAll(player);
    
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
            Debug::clearFrameCount();
        }
        input();
        update();
        render();
        frameTime = SDL_GetTicks() - frameStart;
        if((1000/60) > frameTime) {
            SDL_Delay((1000/60)-frameTime);
        }
        Debug::hydrateFPS(1000/frameTime);
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 126, 192, 238, 255);
    SDL_RenderFillRect(ren, &rect);

    map->draw();
    draw->initObject(*player);
    if(Debug::isActive()) Debug::addColliders(collisions);
    debugInterface->showCollidersBox();
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
    player->updateMouse(map->getMap());
    /** Camera update **/
    /* TODO: Camera Class */
    if(player->getDX() < 200) {player->setDest(200, player->getDY()); map->scroll(player->getSpeed(), 0);}
    if(player->getDX() > WIDTH-200) {player->setDest(WIDTH-200, player->getDY()); map->scroll(-player->getSpeed(), 0);}
    if(player->getDY() < 200) {player->setDest(player->getDX(), 200); map->scroll(0, player->getSpeed());}
    if(player->getDY() > HEIGHT-200) {player->setDest(player->getDX(), HEIGHT-200); map->scroll(0, -player->getSpeed());}
    /****/
    player->updateAnimation();
    collisions.addCollider(*player);
    collisions.update(*player, map->getMap());
    if(player->isFall()) {
        player->setDest(player->getDX(), player->getDY()+player->getVGrav());
    }
}