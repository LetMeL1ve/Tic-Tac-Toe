#include "main_game_logic.h"

/*
* The main file.
*/
void get_yx(int& x, int& y);

int main()
{
    MGL::field_t field {};

    field[0].fill(' ');
    field[1].fill(' ');
    field[2].fill(' ');

    while (MGL::check_field(field) == 0) {
        MGL::print_field(field);

        int y, x;
        if (0 && MGL::is_x_playing) {
            // TODO: Minimax add.
        } else {
            get_yx(x, y);
        }
        MGL::player_move(field, x, y);
    }
}

void get_yx(int& x, int& y) {
    std::cout << "Enter coordinates [x, y]:";
    while (true) {
       if (std::cin >> x)
           break;
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::cout << "Try agian.";
    }
    while (true) {
       if (std::cin >> y)
           break;
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::cout << "Try agian.";
    }
}