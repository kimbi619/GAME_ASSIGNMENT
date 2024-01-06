#ifndef WINROOM_HPP
#define WINROOM_HPP

#include <string>
#include "../../Character/Player/Player.hpp"


#ifndef TRAPROOM_HPP
#include "../Room.hpp"
#endif

class Winroom: public Room {
    public:
        Winroom(SDL_Renderer* game_state, std::string label);


        /// @brief Confirms if Player has entered win room and update game state
        /// @param player 
        /// @return 
        int win(Player player);
        
        void fillRoom(SDL_Renderer* game_state, SDL_Color color);

};

#endif