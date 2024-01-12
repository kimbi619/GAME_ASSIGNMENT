

#include "Mapp.hpp"
#include "../Character/Character.hpp"
#include <SDL2/SDL.h>

Mapp::Mapp(SDL_Renderer* game_state) {
    mapp.w = Screen_size;
    mapp.h = Screen_size;
    mapp.x = CELL_SIZE;
    mapp.y = CELL_SIZE;
    this->position.x_cord = CELL_SIZE;
    this->position.y_cord = CELL_SIZE;
    
}


Mapp::~Mapp() {

}

void Mapp::render(SDL_Renderer* game_state) {
    SDL_SetRenderDrawColor(game_state, 255, 128, 0, 255);
    SDL_RenderFillRect(game_state, &mapp);
    SDL_RenderDrawRect(game_state, &mapp);
}

void Mapp::draw_game_grid(SDL_Renderer* game_state) {
    for (int i = 0; i < GRID_SIZE; i++) {
        // Horizontal lines
        SDL_RenderDrawLine(game_state, 2* CELL_SIZE, 2* CELL_SIZE + CELL_SIZE *i, /*x1,y1*/
            Screen_size + CELL_SIZE, 2* CELL_SIZE + CELL_SIZE *i /*x2,y2*/
        );
        // Vertical Lines 
        SDL_RenderDrawLine(game_state, 2* CELL_SIZE + CELL_SIZE *i, 2 * CELL_SIZE, /*x1,y1*/
            2* CELL_SIZE + CELL_SIZE *i, Screen_size /*x2,y2*/
        );
    }
}