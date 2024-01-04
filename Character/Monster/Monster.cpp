
#include "Monster.hpp"
#include "../Player/Player.hpp"
#include <iostream>

Monster::Monster(SDL_Renderer* game_state, std::string label, Position initial_state) : Character(game_state, label, initial_state) {}

void Monster::sensePlayer() {
    printf("hello world");
}

void Monster::calculateExit() {
}

void Monster::monsterMove(Player* player) {
    this->move(-1, 1);
    std::cout << player->getShifts() << std::endl;
}