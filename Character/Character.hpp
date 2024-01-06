
#include <string>

// THIRD PARTY
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// LOCAL 
#define CHARACTER_HPP

#ifndef HEADER_HPP
#include "../header.hpp"
#endif





class Character {
    public:
        std::string label;
        std::string color;
        Position position;

        // Constructor
        Character(SDL_Renderer* game_state, std::string label, Position initial_state);

        // Destructor
        ~Character();

        /// @brief Returns the current coordinates of the character
        /// @return Current character position
        Position getCharacterPosition();

        /// @brief Sets character position to a given coordinate
        /// @param x 
        /// @param y 
        void setCharacterPosition(int x, int y);
        
        
        void moves_remaining(int moves);

        void reset();

        /// @brief Moves the player in a particular direction
        /// @param x_shift 
        /// @param y_shift 
        void move(int x_shift, int y_shift);


        void render(SDL_Renderer* game_state, const SDL_Color& color);

        void updateCharacter(SDL_Renderer* game_state, std::string image_path);
        
    private:
        SDL_Rect m_character;
        SDL_Texture* m_texture;
        SDL_Texture* m_text_texture;
        TTF_Font* m_font;

};
