
#include "Winroom.hpp"

Winroom::Winroom(SDL_Renderer* game_state, std::string label) : Room(game_state){
    this->position.x_cord = GRID_SIZE;
    this->position.y_cord = 1;
}


int Winroom::win(Player player){
    return 0;
}


void Winroom::fillRoom(SDL_Renderer* game_state, SDL_Color color){
    this->setRoomColor(game_state, color);
}