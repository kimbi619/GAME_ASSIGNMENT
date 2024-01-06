
#include "Traproom.hpp"
#include <random>

Traproom::Traproom(SDL_Renderer* game_state, int damage) : Room(game_state){
    this->damageAmount = damage;

    this->position.x_cord = 1;
    this->position.y_cord = 1;
}

void Traproom::setDamageAmount(int damage) {
    this->damageAmount = damage;
}

int Traproom::getDamageAmount(){
    return this->damageAmount;
}

void Traproom::setRandomPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(3, GRID_SIZE - 2);
    int trap_room_position_x = distribution(gen);
    int trap_room_position_y = distribution(gen);
    this->setPositionFromOrigin(trap_room_position_x, trap_room_position_y);


};

void Traproom::fillRoom(SDL_Renderer* game_state, SDL_Color color, Player player){
    if ( player.position.x_cord == this->position.x_cord && player.position.y_cord == this->position.y_cord){
        this->setRoomColor(game_state, color);
        player.damage(this->damageAmount);
        setRandomPosition();
    }else{
        this->setRoomColor(game_state, color);
    }
}