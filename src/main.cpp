#include <iostream>
#include <string>

const int field_size = 3;
char field[field_size][field_size] = {
    {'1', '2', '3'},
    {'X', 'X', 'X'},
    {'7', '8', '9'}
};

void print_field();

bool field_check();

int main()
{
   print_field();
   std::cout << std::boolalpha << field_check();
}

void print_field() {
    const std::string horizontal_sep = "\n-------------\n", vertical_sep = " | "; 
    std::cout << horizontal_sep;
    for (int y = 0; y != std::size(field); ++y) {
        for (int x = 0; x != std::size(field); ++x) {
            if (x % 3 == 0) 
                std::cout << "| ";
            std::cout << field[y][x] << vertical_sep;
        }
        std::cout << horizontal_sep;
    }
}

bool field_check() { // returns false if someone wins.
    if (field[0][0] == field[0][1] && field[0][2] == field[0][1])
    return false;
    else if (field[1][0] == field[1][1] && field[1][2] == field[1][1])
    return false;
    else if (field[2][0] == field[2][1] && field[2][2] == field[2][1])
    return false;
    else if (field[0][0] == field[1][1] && field[2][2] == field[1][1])
    return false;
    else if (field[0][2] == field[1][1] && field[2][0] == field[1][1])
    return false;
    return true;
}