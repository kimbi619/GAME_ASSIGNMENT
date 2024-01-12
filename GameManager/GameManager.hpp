#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>

#ifndef HEADER_HPP
#include "../header.hpp"
#endif


class GameManager{
    public:
        Position position;
        GameManager(SDL_Renderer* game_state);

        ~GameManager();

        void write(SDL_Renderer* game_state, std::string text, std::string score);

        void render(SDL_Renderer* game_state);
    
    private:
        SDL_Rect g_manager;
        SDL_Rect g_wrapper;
        SDL_Rect scoreboard;
        SDL_Texture* scoreboard_texture;
        TTF_Font* m_font;
};