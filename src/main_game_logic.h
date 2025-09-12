#include <limits>
#include <iostream>

namespace main_game_logic {
    const int field_size = 3;
    bool is_x_playing = false;

    void print_field(const char field[][field_size]);

    int check_field(const char field[][field_size]);

    void player_move(char field[][field_size]);
    
}