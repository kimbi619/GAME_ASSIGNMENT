
#ifndef TRAPROOM_HPP
#define TRAPROOM_HPP

#include "../Room.hpp"
#include "../../Character/Player/Player.hpp"

class Traproom: public Room {
    public:
        int damageAmount = 0;
        Traproom(SDL_Renderer* game_state, int damage);

        /// @brief Sets damage that room can cause to the player
        /// @param damage 
        void setDamageAmount(int damage);

        /// @brief Gets damage room can cause
        /// @return int: damage
        int getDamageAmount();

        void setRandomPosition();

        void fillRoom(SDL_Renderer* game_state, SDL_Color color, Player player);

};

#endif