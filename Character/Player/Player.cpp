
#include "Player.hpp"

Player::Player(SDL_Renderer* game_state, std::string label, Position initial_state) : Character(game_state, label, initial_state) {}

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

void Player::damage() {
}

void Player::movePlayer(int x_shift, int y_shift) {
    this->move(x_shift, y_shift);
    this->shifts += 1;

}

