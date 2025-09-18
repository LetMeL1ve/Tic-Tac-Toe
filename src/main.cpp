#include "main_game_logic.h"
#include "minimax.h"

/*
* The main file.
*/
void get_yx(int& x, int& y);

int main()
{
    // Field 
    MGL::field_t field {{
        {{' ', ' ', ' '}},
        {{' ', ' ', ' '}},
        {{' ', ' ', ' '}}
    }};

    std::cout << "Do you want to play VS bot? [y, n]";
    char choice;
    std::cin >> choice;
    MGL::is_bot_playing = ((choice) == 'y');

    // Main game loop.
    while (MGL::check_field(field) == 0) {
        int y, x;
        if (!MGL::is_o_playing) {
            if (MGL::is_bot_playing) {
                auto best_move = minimax::get_best_move(field, MGL::is_o_playing);
                y = best_move.first;
                x = best_move.second;
            } else {
                MGL::print_field(field);
                get_yx(x, y);
            }
        } else {
            MGL::print_field(field);
            get_yx(x, y); 
        }

        MGL::player_move(field, x, y);
        MGL::is_o_playing = !MGL::is_o_playing;
    }
    if (MGL::check_field(field) == -1)
        std::cout << "X wins!";
    else if (MGL::check_field(field) == 1)
        std::cout << "O wins!";
    else 
        std::cout << "It's a draw.";
    std::cin.clear();
    char temp;
    std::cin >> temp;
}

// Function that gets coordinates from user.
void get_yx(int& x, int& y) {
    // Getting x
    std::cout << "Enter coordinates [x, y]:";
    while (true) {
        if (std::cin >> x && 0 <= x && x < 3)
           break;
        // Clearing the console if input is invalid.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Try agian.";
    }
    // Getting y
    while (true) {
        if (std::cin >> y && 0 <= y && y < 3)
           break;
        // Clearing the console if input is invalid.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Try agian.";
    }
}