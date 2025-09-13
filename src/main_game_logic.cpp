#include "main_game_logic.h"

/*
* Header file of main logic.
*/

namespace MGL
{
    bool is_x_playing = false;
    
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

    int check_field(const field_t& field) { // Returns -1 if X wins, returns 1 if O wins else returns 0.
        bool result;
        // Horizontal check
        if (field[0][0] == field[0][1] && field[0][2] == field[0][1] && field[0][0] != ' ')
        result = true;
        else if (field[1][0] == field[1][1] && field[1][2] == field[1][1]  && field[1][0] != ' ')
        result = true;
        else if (field[2][0] == field[2][1] && field[2][2] == field[2][1]  && field[2][0] != ' ')
        result = true;
        // Diagonal check
        else if (field[0][0] == field[1][1] && field[2][2] == field[1][1]  && field[0][0] != ' ')
        result = true;
        else if (field[0][2] == field[1][1] && field[2][0] == field[1][1]  && field[0][2] != ' ')
        result = true;
        // Vertical check
        else if (field[0][0] == field[1][0] && field[1][0] == field[2][0]  && field[1][0] != ' ')
        result = true;
        else if (field[0][1] == field[1][1] && field[1][1] == field[2][1]  && field[0][1] != ' ')
        result = true;
        else if (field[0][2] == field[1][2] && field[1][2] == field[2][2]  && field[0][2] != ' ')
        result = true;
        
        return result ? (is_x_playing ? -1 : 1) : 0;
    }

    int get_number() { // Helping method for getting valid number form standart input.
        int number;
        while (true) {
            if (std::cin >> number)
                return number;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void player_move(field_t& field) { // Method that update field.
        while (true) {
            std::cout << "Enter coordinates [y, x]:";
            int y = get_number();
            int x = get_number();
            if (field[y][x] == ' ') {
                field[y][x] = is_x_playing ? 'X' : 'O';
                is_x_playing = !is_x_playing;
                return;
            } else
                std::cout << "Try again.\n";
        }
    }
}
