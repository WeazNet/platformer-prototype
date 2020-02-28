#include "player.h"

Player::Player(SDL_Renderer* &r) {
    ren=r;
    draw = new Draw(ren);
    left=right=up=0;
    setImage("res/player.png", ren);
    setDest(0, 0, 14*4, 21*4);
    setSolid(1);
    createCycle(IDOL_RIGHT, 14, 21, 2, 20);
    createCycle(IDOL_LEFT, 14, 21, 2, 20);
    createCycle(RUN_RIGHT, 14, 21, 4, 5);
    createCycle(RUN_LEFT, 14, 21, 4, 5);
    createCycle(JUMP_RIGHT, 14, 21, 4, 10);
    createCycle(JUMP_LEFT, 14, 21, 4, 10);
    setCurrentAnimation(IDOL_RIGHT);
}

Player::~Player() {
    deleteAll(draw);
}

void Player::input(SDL_Event &event) {
    e=event;
    if(e.type == SDL_KEYDOWN) {
        if(e.key.keysym.sym == SDLK_d) {right=1;}
        if(e.key.keysym.sym == SDLK_q) {left=1;}
        if(e.key.keysym.sym == SDLK_z) {up=1;}
    }
    if(e.type == SDL_KEYUP) {
        if(e.key.keysym.sym == SDLK_d) {
            right=0;
            setCurrentAnimation(IDOL_RIGHT);
        }
        if(e.key.keysym.sym == SDLK_q) {
            left=0;
            setCurrentAnimation(IDOL_LEFT);
        }
        if(e.key.keysym.sym == SDLK_z) {
            up=0;
        }
    }
}

void Player::update() {
    if(left) {if(getCurrentAnimation() != RUN_RIGHT){setCurrentAnimation(RUN_LEFT);} setDest(getDX()-speed, getDY());}
    if(right) {if(getCurrentAnimation() != RUN_LEFT){setCurrentAnimation(RUN_RIGHT);} setDest(getDX()+speed, getDY());}
    if(up && !lockJump) {jump=true;}
    updateJump();
}

void Player::tileInteractivity(std::vector<Tile> map) {
    SDL_Rect mouse = {e.button.x,e.button.y,1,1};
        for(int i=0; i<(int)map.size(); i++) {
            SDL_Rect m = map[i].getDest();
            if(SDL_HasIntersection(&mouse, &m) && map[i].onMarking()) {
                onAction(map[i], HOVERED);
                if(e.motion.state==SDL_BUTTON_LMASK || e.type == SDL_MOUSEBUTTONDOWN) {
                    onAction(map[i], PRESSED);
                }
                if(e.type == SDL_MOUSEBUTTONUP) {
                    onAction(map[i], STOPPED);
                }
            }
        }
        if(Debug::isActive()) Debug::hydratePosMouse(mouse.x, mouse.y);
}

void Player::onAction(Tile &t, int a) {
    SDL_Rect dest = t.getDest();
    Object o;
    o.setImage("res/tilenotice.png", ren);
    o.setDest(t.getDX(),t.getDY(), t.getDW(), t.getDH());
    switch(a) {
        case HOVERED:
            SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
            SDL_RenderDrawRect(ren, &dest);
            break;
        case PRESSED:
            if(t.getHarvestLevel() == HAND) {
                t.decreaseDurability(1);
                Map::hydrate(t);
                if(t.getDurability() <= 0) {
                    std::cout << "Block(" << t.getId() << ") removed." << std::endl;
                    t.init(NONE);
                    Map::hydrate(t);
                }
                if(t.getDurability() != 0) {
                    Tile reference;
                    reference.init(t.getType());
                    if(t.getDurability() >= 3*reference.getDurability()/4) {
                        o.setSrc(0,0,t.getDW(),t.getDH());
                        draw->initObject(o);
                    }
                    else if(t.getDurability() >= reference.getDurability()/2) {
                        o.setSrc(TILE_SIZE,0,t.getDW(),t.getDH());
                        draw->initObject(o);
                    }
                    else {
                        o.setSrc((TILE_SIZE*2),0,t.getDW(),t.getDH());
                        draw->initObject(o);
                    }
                }
            } else {
                o.setSrc((TILE_SIZE*3),0,t.getDW(),t.getDH());
                draw->initObject(o);
            }
            SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
            SDL_RenderDrawRect(ren, &dest);
            break;
        case STOPPED:
            if(t.getDurability() > 0.0) {
                t.init(t.getType());
                Map::hydrate(t);
            }
            draw->initObject(t);
            break;
        default:
            break;
    }
}
