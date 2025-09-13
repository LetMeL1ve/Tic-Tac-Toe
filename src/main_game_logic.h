#include <limits>
#include <iostream>
#include <array>

namespace MGL {
    constexpr size_t field_size = 3;
    using field_t = std::array<std::array<char, field_size>, field_size>;
    extern bool is_x_playing;

    void print_field(const field_t& field);

    int check_field(const field_t& field);

    void player_move(field_t& field);

    int get_number();
    
}