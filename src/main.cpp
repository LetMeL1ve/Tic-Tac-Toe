#include "main_game_logic.h"

/*
* The main file.
*/
int main()
{
    MGL::field_t field {};

    field[0].fill(' ');
    field[1].fill(' ');
    field[2].fill(' ');

    while (MGL::check_field(field) == 0) {
        MGL::print_field(field);
        MGL::player_move(field);
    }
}