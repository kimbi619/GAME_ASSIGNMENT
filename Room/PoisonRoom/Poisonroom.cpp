
#include "Poisonroom.hpp"

Poisonroom::Poisonroom(SDL_Renderer* game_state, std::string label) : Room(game_state){
    this->position.x_cord = 5;
    this->position.y_cord = 5;
}


int Poisonroom::kill(Player player){
    exit(0);
}


void Poisonroom::fillRoom(SDL_Renderer* game_state, SDL_Color color){
    this->setRoomColor(game_state, color);
}