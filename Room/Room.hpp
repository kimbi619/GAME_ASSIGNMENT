
#include <string>
#include <SDL2/SDL.h>
#define ROOM_HPP

#ifndef HEADER_HPP
#include "../header.hpp"
#endif
class Room {
    public:
        RoomPosition position;
        // Constructor
        Room(SDL_Renderer* game_state);
        
        // Destructor
        ~Room();

        void displayColor(std::string color);
        
        void setPosition(int x, int y);
        
        void setPositionFromOrigin(int x, int y);
        
        void visited(bool is_visited);

        void render(SDL_Renderer* game_state);

        /// @brief Sets the room color 
        /// @param game_state 
        void setRoomColor(SDL_Renderer* game_state, SDL_Color color);

    private:
        SDL_Rect m_room;
        SDL_Texture* m_texture;

};