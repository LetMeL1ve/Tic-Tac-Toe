#pragma once 

#include <limits>
#include <iostream>
#include <array>

/*
* Header file of main logic.
*/
namespace MGL { 
    inline constexpr size_t field_size = 3; // Size constant.
    using field_t = std::array<std::array<char, field_size>, field_size>; // Type that is used for field
    inline bool is_o_playing = true; // True if O plays.

    // Method headers.
    void print_field(const field_t& field);

    int check_field(const field_t& field);

    bool player_move(field_t& field, int x, int y);
}