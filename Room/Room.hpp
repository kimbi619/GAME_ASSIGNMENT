
#include <string>
#include <SDL2/SDL.h>


class Room {
    public:

        // Constructor
        Room(SDL_Renderer* game_state);

        // Destructor
        ~Room();

        void displayColor(std::string color);
        
        void setPosition(int x, int y);
        
        void visited(bool is_visited);

        void render(SDL_Renderer* game_state);

        /// @brief Sets the room color 
        /// @param game_state 
        void fillRoom(SDL_Renderer* game_state);

    private:
        SDL_Rect m_room;
        SDL_Texture* m_texture;

};