#ifndef MONSTER_HPP
#define MONSTER_HPP

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../Character.hpp"
#endif
#include "../Player/Player.hpp"

class Monster : public Character {
public:
    Monster(SDL_Renderer* game_state, std::string label, Position initial_state);

    void sensePlayer(int player_x, int player_y);

    void calculateExit();

    /// @brief Move the monster towards the player intelligently
    /// @param player 
    void monsterMove(Player* player);

};

#endif

