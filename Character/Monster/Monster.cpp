
#include "Monster.hpp"
#include "../Player/Player.hpp"
#include <iostream>

Monster::Monster(SDL_Renderer* game_state, std::string label, Position initial_state) : Character(game_state, label, initial_state) {
    this->position.x_cord = GRID_SIZE;
    this->position.y_cord = 1;
}

/// @brief Calculates and moves the monster in the direction to best catch the player
/// @param player_x Player x coordinates
/// @param player_y Player y coordinates
void Monster::sensePlayer(int player_x, int player_y) {
    int x_gap = player_x - this->position.x_cord;
    int y_gap = player_y - this->position.y_cord;
    int best_x_value = 0;
    int best_y_value = 0;

    for (int x_value = -1; x_value <= 1; ++x_value) {
        int new_x_gap = player_x - (this->position.x_cord + x_value);

        if (std::abs(new_x_gap) < std::abs(x_gap)) {
            best_x_value = x_value;
            x_gap = new_x_gap;
        } else if (std::abs(new_x_gap) == std::abs(x_gap)) {
            best_x_value = std::min(x_value, best_x_value);
        }
    }
    for (int y_value = -1; y_value <= 1; ++y_value) {
        int new_y_gap = player_y - (this->position.y_cord + y_value);

        if (std::abs(new_y_gap) < std::abs(y_gap)) {
            best_y_value = y_value;
            y_gap = new_y_gap;
        } else if (std::abs(new_y_gap) == std::abs(y_gap)) {
            best_y_value = std::min(y_value, best_y_value);
        }
    }

     this->move(best_x_value, best_y_value);
}

void Monster::calculateExit() {
}

void Monster::monsterMove(Player* player) {
   
    sensePlayer(player->position.x_cord, player->position.y_cord);
}