#ifndef PLAYER_HPP
#define PLAYER_HPP

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../Character.hpp"
#endif

class Player : public Character {
public:
    int health = 1000;
    int shifts = 0;
    Player(SDL_Renderer* game_state, std::string label, Position initial_state);

    int getShifts();

    int getHealth();

    void setShifts(int shift);

    void setHealth(int health);

    void movePlayer(int x_shift, int y_shift);

    void cure();

    void damage();
};

#endif

