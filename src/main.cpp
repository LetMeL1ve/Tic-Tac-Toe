#include "main_game_logic.h"
using namespace main_game_logic;

int main()
{
    while (check_field() == 0) {
        print_field();
        player_move();
    }
    std::cout << (is_x_playing ? "O wins!" : "X wins!");
}