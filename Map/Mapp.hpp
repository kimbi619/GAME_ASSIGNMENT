
#include <SDL2/SDL.h>
// #include "../header.hpp"
#ifndef HEADER_HPP
#include "../header.hpp"
#endif


class Mapp{
    public:
        Position position;
        Mapp(SDL_Renderer* game_state);

        ~Mapp();

        void render(SDL_Renderer* game_state);
        
        void draw_game_grid(SDL_Renderer* game_state);

    private:
        SDL_Rect mapp;
        SDL_Texture* m_texture;

};

