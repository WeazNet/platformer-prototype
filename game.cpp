#include "game.h"

Game::Game() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) cout << "Error: SDL_Init() " << SDL_GetError() << endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &w, &ren) < 0) cout << "Error: SDL_CreateWindowAndRenderer() " << SDL_GetError() << endl;
    running=true;

    map = new Map(ren);
    map->load("levels/1.level", "res/tileset.png");

    draw = new Draw(ren);

    player = new Player(ren);
    loop();
}

Game::~Game() {
    delete draw;
    delete map;
    delete player;
    IMG_Quit();
    SDL_DestroyWindow(w);
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
    map->draw();
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