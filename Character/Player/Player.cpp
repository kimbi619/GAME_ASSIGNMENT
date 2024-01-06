
#include "Player.hpp"
#include <iostream>

Player::Player(SDL_Renderer* game_state, std::string label, Position initial_state) : Character(game_state, label, initial_state) {
    this->position.x_cord = 1;
    this->position.y_cord = GRID_SIZE;
}

int Player::getShifts() {
    return this->shifts;
}
int Player::getHealth() {
    return this->health;
}

void Player::setShifts(int shift) {
    this->shifts = shift;
}
void Player::setHealth(int health){
    this->health = health;
}

void Player::cure() {

}

void Player::damage(int damage) {
    int new_health = this->health - damage;
    this->setHealth(new_health);
}

void Player::movePlayer(int x_shift, int y_shift) {
    this->move(x_shift, y_shift);
    this->shifts += 1;
    this->health -= 1;
}

