#include <iostream>
#include <string>
#include <vector>
#include <memory>

// LOCAL 
// #include "./Character/Character.hpp"
#include "Room/Room.hpp"
#include "./Character/Monster/Monster.hpp"
#include "./Character/Player/Player.hpp"

// THIRD PARTY 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>





class GamePlay {
    public:
        
        GamePlay(){
            start_game();
        }

        void start_game() {
            setup_window();
        }
        
        void draw_rooms(SDL_Renderer* renderer) {
            for (int i = 0; i < GRID_SIZE; i++) {
                SDL_RenderDrawLine(renderer, 0, CELL_SIZE *i, /*x1,y1*/
                    Screen_size, CELL_SIZE *i /*x2,y2*/
                );
                SDL_RenderDrawLine(renderer, CELL_SIZE *i, 0, /*x1,y1*/
                    CELL_SIZE *i, Screen_size /*x2,y2*/
                );
            }
        }

        int setup_window() {

            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                printf("error initializing SDL: \n");
                return -1;
            }
            
            SDL_Init(SDL_INIT_VIDEO);
            TTF_Init();

            
            SDL_Window* window = SDL_CreateWindow("Group 8 Game",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                Screen_size, 
                Screen_size, 
                SDL_WINDOW_SHOWN
            );

            SDL_Renderer* renderer = nullptr;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            // Set initial position of player
            Position player_initial_position;
            player_initial_position.x_cord = 0;
            player_initial_position.y_cord = GRID_SIZE - 1;

            // Set initial position for monster 
            Position monster_initial_position;
            monster_initial_position.x_cord = GRID_SIZE - 1;
            monster_initial_position.y_cord = 0;

            // Create instances of player and monster 
            Monster monster(renderer, "M", monster_initial_position);
            Player player(renderer,  "P", player_initial_position);

            std::vector<std::shared_ptr<Room>> rooms;
            for (int i = 0; i < GRID_SIZE * GRID_SIZE + 1; i++)
            {
                std::shared_ptr<Room> room = std::make_shared<Room>(renderer);
                rooms.push_back(room);
            }

            int col = 0;
            int row = 0;
            for (int i = 0; i < GRID_SIZE * GRID_SIZE + 1; i++)
            {
                
                rooms[i]->setPosition(col, row);
                
                if( i % GRID_SIZE == 0 && i != 0){
                    row += 1;
                    col = -1;
                }
                col += 1;
            }
            
            // rooms[0]->setPosition(2, 3);
            // rooms[2]->setPosition(0, 4);
     
            

            bool gameRunning = true;
            while (gameRunning)
            {
                SDL_Event event;
                while(SDL_PollEvent(&event)){
                    if(event.type == SDL_QUIT){
                        gameRunning = false;
                    }
                    if (event.type == SDL_KEYDOWN)  
                    {
                        // Position pos = player.getCharacterPosition();
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_LEFT:
                            player.movePlayer(-1, 0);
                            break;
                        case SDLK_RIGHT:
                            player.movePlayer(1, 0);
                            break;
                        case SDLK_DOWN:
                            player.movePlayer(0, 1);
                            break;
                        case SDLK_UP:
                            player.movePlayer(0, -1);
                            break;
                        
                        default:
                            break;
                        }
                    }
                    if (event.type == SDL_KEYUP)
                    {
                        if(player.shifts % 2 == 0 && player.shifts != 0)
                        {
                            monster.monsterMove(&player);
                            player.setShifts(0);
                        }
                        // if (monster.position.x_cord == player.position.x_cord && monster.position.y_cord == player.position.y_cord){
                        //     printf("clash!!");
                        // }
                    }
                    
                }

                SDL_SetRenderDrawColor(renderer, 30, 100, 100, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


                draw_rooms(renderer);

                // player.getCharacterPosition();    

                player.render(renderer, {0, 0, 255});  
                monster.render(renderer, {255, 0, 0});

                for(auto& room: rooms) {
                    room->render(renderer);
                }
                
                SDL_RenderPresent(renderer);


            }
            SDL_DestroyWindow(window);
            SDL_Quit();
            
            return 0;
        }
};



int main(int argc, char *argv[])
{
   
    GamePlay gameLoop;
    
    return 0;
}