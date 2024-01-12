
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

        /// @brief Sets the display color of the room   
        /// @param color SDL color with is a simple list { r, g, b}
        void displayColor(std::string color);
        
        /// @brief Defines the position of a room, used to set trap rooms and other dynamic rooms   
        /// @param x x coordinates of the room
        /// @param y y coordinates of the room
        void setPosition(int x, int y);
        
        /// @brief Set absolute position of room. used in finish room
        /// @param x 
        /// @param y 
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