#include <iostream>
#include <string>

const int field_size = 3;
char field[field_size][field_size] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_field();

int main()
{
   print_field(); 
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