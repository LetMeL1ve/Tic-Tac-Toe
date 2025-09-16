#include "minimax.h"

namespace minimax {
    // A minimax algorithm.
    int minimax(const MGL::field_t& field, bool maximaizing, int depth) {
        int situation = MGL::check_field(field);
        if (situation == 2) return 0;
        if (situation == -1) return -10 + depth;
        if (situation == 1) return 10 - depth;

        int best_val = 0;
        if (maximaizing) {
            best_val = INT_MIN;
            for (const auto& position : get_free_cells(field)) {
                MGL::field_t child = field;
                child[position[0]][position[1]] = 'O';
                int val = minimax(child, !maximaizing, depth + 1);
                best_val = std::max(best_val, val);
            }
            return best_val;
        } else {
            best_val = INT_MAX;
            for (const auto& position : get_free_cells(field)) {
                MGL::field_t child = field;
                child[position[0]][position[1]] = 'X';
                int val = minimax(child, !maximaizing, depth + 1);
                best_val = std::min(best_val, val);
            }
            return best_val;
        }
    }

    // Function that gets best move in positon {field}.
    std::pair<int, int> get_best_move(const MGL::field_t& field, bool maximaizing) {
        std::pair<int, int> best_move;
        int best_value = maximaizing ? INT_MIN : INT_MAX;
        for (auto position : get_free_cells(field)) {
            MGL::field_t child = field;
            child[position[0]][position[1]] = maximaizing ? 'O' : 'X';
            int value = minimax(child, maximaizing, 1);    
            if (maximaizing && best_value < value) {
                best_move = {position[0], position[1]};
                best_value = value;
            } else if (!maximaizing && best_value > value) {
                best_move = {position[0], position[1]};
                best_value = value;
            }
        }
        return best_move;
    }

    // Function that gets all free cells in the field {field}.
    std::vector<std::array<size_t, 2>> get_free_cells(const MGL::field_t& field) {
        std::vector<std::array<size_t, 2>> result;
        for (size_t y = 0; y != MGL::field_size; ++y) {
            for (size_t x = 0; x != MGL::field_size; ++x) {
                if (field[y][x] == ' ') {
                    std::array<size_t, 2> coordinates = {y, x};
                    result.push_back(coordinates);
                }
            }
        }
        return result;
    }
}