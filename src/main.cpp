#include <iostream>
#include <string>
#include <limits>

const int field_size = 3;
char field[field_size][field_size] = { // Array that represents a game field.
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
bool is_x_playing = false;

void print_field();

bool check_field();

void player_move();

int main()
{
    while (check_field()) {
        print_field();
        player_move();
    }
    std::cout << (is_x_playing ? "O wins!" : "X wins!");
}

void print_field() { // Method that prints formated field to standart output.
    const std::string horizontal_sep = "\n-----------------\n", vertical_sep = " | "; // Separation symbols defined.

    std::cout << horizontal_sep;
    std::cout << "| / | 0 | 1 | 2 |";
    std::cout << horizontal_sep;
    for (int y = 0; y != field_size; ++y) {
        std::cout << "| " << y << vertical_sep;
        for (int x = 0; x != field_size; ++x) {
                
            std::cout << field[y][x] << vertical_sep;
        }
        std::cout << horizontal_sep;
    }
}

bool check_field() { // Returns false if someone wins.
    if (field[0][0] == field[0][1] && field[0][2] == field[0][1] && field[0][0] != ' ')
    return false;
    else if (field[1][0] == field[1][1] && field[1][2] == field[1][1]  && field[1][0] != ' ')
    return false;
    else if (field[2][0] == field[2][1] && field[2][2] == field[2][1]  && field[2][0] != ' ')
    return false;
    else if (field[0][0] == field[1][1] && field[2][2] == field[1][1]  && field[0][0] != ' ')
    return false;
    else if (field[0][2] == field[1][1] && field[2][0] == field[1][1]  && field[0][2] != ' ')
    return false;
    return true;
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
void player_move() { // Method that update field.
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