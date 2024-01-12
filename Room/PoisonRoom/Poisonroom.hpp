#ifndef POISONROOM_HPP
#define POISONROOM_HPP

#include <string>
#include "../../Character/Player/Player.hpp"


#ifndef TRAPROOM_HPP
#include "../Room.hpp"
#endif

class Poisonroom: public Room {
    public:
        Poisonroom(SDL_Renderer* game_state, std::string label);


        /// @brief Confirms if Player has entered win room and update game state
        /// @param player 
        /// @return 
        int kill(Player player);
        
        void fillRoom(SDL_Renderer* game_state, SDL_Color color);

};

#endif