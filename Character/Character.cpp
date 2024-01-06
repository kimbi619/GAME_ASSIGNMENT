
#include <string>
#include <iostream>

// LOCAL 
#include "Character.hpp"
// #include "Monster.hpp"

// THIRD PARTY
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>



Character::Character(SDL_Renderer* game_state, std::string label, Position initial_state) {
    TTF_Font* m_font = TTF_OpenFont("./fonts/Montserrat.ttf", 8);
    SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, label.c_str(), {255, 255, 255});
    m_text_texture = SDL_CreateTextureFromSurface(game_state, textSurface);
    SDL_FreeSurface(textSurface);

    m_character.w = CELL_SIZE;
    m_character.h = CELL_SIZE;
    m_character.x = (initial_state.x_cord + 1) * CELL_SIZE;
    m_character.y = (initial_state.y_cord + 1) * CELL_SIZE;

}

Character::~Character() {
    SDL_DestroyTexture(m_texture);
    SDL_DestroyTexture(m_text_texture);
    TTF_CloseFont(m_font);
    TTF_Quit();
}


void Character::setCharacterPosition(int x, int y){
    m_character.x = x;
    m_character.y = y;
}

Position Character::getCharacterPosition(){
    Position position;
    position.x_cord = m_character.x;
    position.y_cord = m_character.y;
    return position;
}

void Character::moves_remaining(int moves = -1){

}

void Character::reset(){

}

void Character::move(int x_shift, int y_shift) {
    this->position.x_cord += x_shift;
    this->position.y_cord += y_shift;

    if (this->position.x_cord < 1){
        this->position.x_cord = 1;
    }
    if (this->position.y_cord < 1) {
        this->position.y_cord = 1;
    }
    if (this->position.x_cord > GRID_SIZE ){
        this->position.x_cord = GRID_SIZE;
    }
    if (this->position.y_cord > GRID_SIZE) {
        this->position.y_cord = GRID_SIZE;
    }
    m_character.x = this->position.x_cord * CELL_SIZE;
    m_character.y = this->position.y_cord * CELL_SIZE;
}

void Character::render(SDL_Renderer* game_state, const SDL_Color& color) {
    SDL_SetRenderDrawColor(game_state, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(game_state, &m_character);

    SDL_RenderCopy(game_state, m_text_texture, NULL, &m_character);
}

// void Character::updateCharacter(SDL_Renderer* game_state, std::string image_path){
//     SDL_Surface* surface = SDL_LoadBMP(image_path.c_str());
//     SDL_FreeSurface(surface);
//     SDL_RenderCopy(game_state, surface, NULL, &m_character);
// }



