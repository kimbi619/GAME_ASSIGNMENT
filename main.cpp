#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

// LOCAL 
// #include "Room/Room.hpp"
#include "header.hpp"
#include "./GameManager/GameManager.hpp"
#include "Room/Traproom/Traproom.hpp"
#include "Room/Winroom/Winroom.hpp"
#include "Room/PoisonRoom/Poisonroom.hpp"
#include "./Character/Monster/Monster.hpp"
#include "./Character/Player/Player.hpp"
#include "./Map/Mapp.hpp"

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
        
        

        int setup_window() {

            if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0) {
                std::cout << "Unable to import sdl dependencies" << std::endl;
                return -1;
            }
            
            SDL_Init(SDL_INIT_VIDEO);
            TTF_Init();
            
            SDL_Window* window = SDL_CreateWindow("Group 8 Game",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                1500, 
                1500, 
                SDL_WINDOW_SHOWN
            );

            SDL_Renderer* renderer = nullptr;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            
            // Draw map for game 
            Mapp mapp(renderer);
            GameManager game_manager(renderer);


            // Set initial position of player
            Position player_initial_position;
            player_initial_position.x_cord = 0;
            player_initial_position.y_cord = GRID_SIZE - 1;

            // Set initial position for monster 
            Position monster_initial_position;
            monster_initial_position.x_cord = GRID_SIZE - 1;
            monster_initial_position.y_cord = 0;

            // Create instances of player and monster 
            Player player(renderer,  "P", player_initial_position);
            Monster monster(renderer, "M", monster_initial_position);
            
            // Create a win room and define its initial position
            Winroom winroom(renderer, "W");
            winroom.setPosition(0, 0);
            
            Poisonroom poisonroom(renderer, "X");
            poisonroom.setPosition(0, 5);
            

            // Creates vector of rooms using pointers to manage life time
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
            

            // Create instances of traproom
            // A random ammount of trap rooms are created at random positions
            std::vector<std::shared_ptr<Traproom>> traprooms;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution(3, 8);
            int trap_rooms = distribution(gen);
            for (int i = 0; i < trap_rooms; i++)
            {
                std::uniform_int_distribution<int> distribution(2, GRID_SIZE - 2);
                int x_position = distribution(gen);
                int y_position = distribution(gen);
                int trap_room_damage = distribution(gen);
                std::shared_ptr<Traproom> t_room = std::make_shared<Traproom>(renderer, trap_room_damage);
                traprooms.push_back(t_room);
                t_room->setPosition(x_position, y_position);
            }
            
            
     
            

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
                        if(player.position.x_cord == winroom.position.x_cord && player.position.y_cord == winroom.position.y_cord){
                            std::cout << winroom.position.x_cord << std::endl;
                        }

                        if(player.shifts % 2 == 0 && player.shifts != 0)
                        {
                            monster.monsterMove(&player);
                            player.setShifts(0);
                        }
                        if (monster.position.x_cord == player.position.x_cord && monster.position.y_cord == player.position.y_cord){
                            std::cout << "player caught" << std::endl;
                            // TODO: Player has been caught set health to 0 and alert game end;
                        }
                    }
                    
                }

                SDL_SetRenderDrawColor(renderer, 30, 100, 100, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                // ##################################################################@
                // ############## RENDER COMPONENTS TO THE WINDOW ####################
                // ##################################################################@
                mapp.draw_game_grid(renderer);
                mapp.render(renderer);

                

                winroom.fillRoom(renderer, {0, 0, 0}); 
                winroom.render(renderer); 

                // poisonroom.fillRoom(renderer, {100, 100, 0}); 
                // poisonroom.render(renderer); 

                player.render(renderer, {0, 0, 255});  
                monster.render(renderer, {255, 0, 0});

                for(auto& room: rooms) {
                    room->render(renderer);
                }

                for(auto& traproom: traprooms) {
                    traproom->render(renderer);
                    traproom->fillRoom(renderer, { 0, 255, 255}, player);
                }
                // ############## RENDER COMPONENTS TO THE WINDOW ####################


                // ################ CREATE GAME MANAGER #############################
                std::string health = std::to_string(player.health);
                game_manager.render(renderer);
                game_manager.write(renderer, "Welcome", health);
                


                // LOAD GAME;
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