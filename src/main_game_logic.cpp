#include "main_game_logic.h"

/*
* Source file of main logic.
*/

namespace MGL
{
    void print_field(const field_t& field) { // Method that prints formated field to standart output.
        const std::string horizontal_sep = "\n-----------------\n", vertical_sep = " | "; // Separation symbols defined.
        std::cout << horizontal_sep;
        std::cout << "| / | 0 | 1 | 2 |";
        std::cout << horizontal_sep;
        for (size_t y = 0; y != field_size; ++y) {
            std::cout << "| " << y << vertical_sep;
            for (size_t x = 0; x != field_size; ++x) {

                std::cout << field[y][x] << vertical_sep;
            }
            std::cout << horizontal_sep;
        }
    }

    int check_field(const field_t& field) { // Returns -1 if X wins, returns 1 if O wins if draw returns 2 else returns 0.
        bool result = false;
        // Horizontal check
        if (field[0][0] == field[0][1] && field[0][2] == field[0][1] && field[0][0] != ' ')
        return field[0][0] == 'X' ? -1 : 1;

        if (field[1][0] == field[1][1] && field[1][2] == field[1][1]  && field[1][0] != ' ')
        return field[1][0] == 'X' ? -1 : 1;

        if (field[2][0] == field[2][1] && field[2][2] == field[2][1]  && field[2][0] != ' ')
        return field[2][0] == 'X' ? -1 : 1;

        // Diagonal check
        if (field[0][0] == field[1][1] && field[2][2] == field[1][1]  && field[0][0] != ' ')
        return field[0][0] == 'X' ? -1 : 1;

        if (field[0][2] == field[1][1] && field[2][0] == field[1][1]  && field[0][2] != ' ')
        return field[0][2] == 'X' ? -1 : 1;

        // Vertical check
        if (field[0][0] == field[1][0] && field[1][0] == field[2][0]  && field[1][0] != ' ')
        return field[0][0] == 'X' ? -1 : 1;

        if (field[0][1] == field[1][1] && field[1][1] == field[2][1]  && field[0][1] != ' ')
        return field[0][1] == 'X' ? -1 : 1;

        if (field[0][2] == field[1][2] && field[1][2] == field[2][2]  && field[0][2] != ' ')
        return field[0][2] == 'X' ? -1 : 1;

        // Draw check
        for (size_t y = 0; y != MGL::field_size; ++y) {
            for (size_t x = 0; x != MGL::field_size; ++x) {
                if (field[y][x] == ' ')
                    return 0;
            }
        }
        return 2;
    }
    
    bool player_move(field_t& field, int x, int y) { // Method that update field. Returns true if it changes the field.
        if (field[y][x] == ' ') {
            field[y][x] = is_o_playing ? 'X' : 'O';
            return true;
        }
        return false;
    }
}
