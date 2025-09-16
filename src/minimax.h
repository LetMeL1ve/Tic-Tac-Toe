#pragma once 

#include "main_game_logic.h"
#include <vector>
#include <algorithm>

namespace minimax {
    int minimax(const MGL::field_t& field, bool maximaizing);
    std::vector<std::array<size_t, 2>> get_free_cells(const MGL::field_t& field);
    std::pair<int, int> get_best_move(const MGL::field_t& field, bool maximaizing);
}