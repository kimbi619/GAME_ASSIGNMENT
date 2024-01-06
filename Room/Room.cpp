
#include <string>
#include <iostream>

// LOCAL 
#include "../Character/Character.hpp"
#include "Room.hpp"

// THIRD PARTY
#include <SDL2/SDL.h>


Room::Room(SDL_Renderer* game_state) {
    m_room.w = CELL_SIZE;
    m_room.h = CELL_SIZE;
    m_room.x = 0;
    m_room.y = CELL_SIZE;
    this->position.x_cord = 1;
    this->position.y_cord = 1;
    
}


Room::~Room() {
}

/// @brief Change the color of the room based on room type when entered
/// @param color 
void Room::displayColor(std::string color){
    
}

/// @brief Sets room position
/// @param x 
/// @param y 
void Room::setPosition(int x, int y){
    // int x_cord = x * CELL_SIZE;
    // int y_cord = y * CELL_SIZE;
    // if(x_cord < 0){
    //     m_room.x = 0;
    // }

    // if(y_cord < 0){
    //     m_room.y = 0;
    // }

    // if(x_cord > Screen_size){
    //     m_room.x = Screen_size;
    // }

    // if(y_cord > Screen_size){
    //     m_room.y = Screen_size;
    // }

    // m_room.x = x_cord;
    // m_room.y = y_cord;

    this->position.x_cord += x;
    this->position.y_cord += y;
    m_room.x = this->position.x_cord * CELL_SIZE;
    m_room.y = this->position.y_cord * CELL_SIZE;
}

void Room::setPositionFromOrigin(int x, int y){
    this->position.x_cord = x;
    this->position.y_cord = y;
    m_room.x = this->position.x_cord * CELL_SIZE;
    m_room.y = this->position.y_cord * CELL_SIZE;
}



/// @brief checks if room is active or not
/// @param visited 
void Room::visited(bool visited=false){

}

void Room::setRoomColor(SDL_Renderer* game_state, SDL_Color color){
    SDL_SetRenderDrawColor(game_state, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(game_state, &m_room);
}




void Room::render(SDL_Renderer* game_state) {
    SDL_SetRenderDrawColor(game_state, 0, 0, 0, 255);
    SDL_RenderDrawRect(game_state, &m_room);

    // SDL_RenderCopy(game_state, m_text_texture, NULL, &m_character);
}

