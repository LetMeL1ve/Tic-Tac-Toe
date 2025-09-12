#include "main_game_logic.h"

int main()
{
    char field[main_game_logic::field_size][main_game_logic::field_size] = { // Array that represents a game field.
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    while (main_game_logic::check_field(field) == 0) {
        main_game_logic::print_field(field);
        main_game_logic::player_move(field);
    }
    std::cout << (main_game_logic::is_x_playing ? "O wins!" : "X wins!");
}