
#include "GameManager.hpp"
#include <string>
#include <SDL2/SDL_ttf.h>


GameManager::GameManager(SDL_Renderer* game_state) {
    g_manager.w = 500;
    g_manager.h = Screen_size;
    g_manager.x = Screen_size + CELL_SIZE;
    g_manager.y = CELL_SIZE;

    // SMALLER RECTANGLE
    int rect_dif = 4 * CELL_SIZE / 3;
    g_wrapper.x = Screen_size + rect_dif;
    g_wrapper.y = rect_dif;
    g_wrapper.w = 500 - CELL_SIZE * 3 / 4;
    g_wrapper.h = Screen_size - CELL_SIZE * 3 / 4;

    this->position.x_cord = 1;
    this->position.y_cord = 1;

    // write Screen

    scoreboard.x = g_wrapper.x + 10;
    scoreboard.y = g_wrapper.y + 10;
    scoreboard.w = g_wrapper.w - 20;
    scoreboard.h = CELL_SIZE;

    TTF_Font* m_font = TTF_OpenFont("../fonts/Montserrat.ttf", 10);
};

GameManager::~GameManager() {
    // std::cout << "Game ended!!!" std::endl;
    SDL_Quit();
}


void GameManager::render(SDL_Renderer* game_state) {
    // LARGER RECTANGLE
    SDL_SetRenderDrawColor(game_state, 0, 255, 0, 255);
    SDL_RenderFillRect(game_state, &g_manager);
    SDL_RenderDrawRect(game_state, &g_manager);

    // SMALLER RECTANGLE
    SDL_SetRenderDrawColor(game_state, 255, 255, 255, 255);
    SDL_RenderDrawRect(game_state, &g_wrapper);
    SDL_RenderFillRect(game_state, &g_wrapper);

}
void GameManager::write(SDL_Renderer* game_state, std::string text, std::string score) {

    // std::cout << score << std::endl;

    // SMALLER RECTANGLE

    SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, "welcome", {255, 0, 0});
    scoreboard_texture = SDL_CreateTextureFromSurface(game_state, textSurface);
    std::cout << scoreboard_texture << std::endl;

    // SDL_SetRenderDrawColor(game_state, 0, 0, 0, 255);
    // SDL_RenderDrawRect(game_state, &scoreboard);
    // SDL_RenderFillRect(game_state, &scoreboard);

    // SDL_RenderCopy(game_state, scoreboard_texture, NULL, &scoreboard);
    // SDL_FreeSurface(textSurface);


}