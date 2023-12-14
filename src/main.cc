#include <iostream>
#include <string>
#include <set>

#include "../inc/game.h"

void print_main_menu() {
    std::cout << "Allowed commands: **TO BE IMPLEMENTED**" << std::endl // TODO: remove if implemented
              << "------------------------------------------------------------------" << std::endl
              << "game [letters] - where letters is the string of letters in the " << std::endl
              << "                 game to be solved. Leave empty for a random game." << std:: endl
              << "exit           - Exits the program." << std::endl;
}

bool is_valid_input(std::string input) {
    if (input.size() != 9) {
        return false;
    }
    for (size_t i = 0; i < input.size(); i++) {
        if (!std::isalpha(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input, letters;
    LetterBoxed game;

    std::cout << "///////////////////////////////////" << std::endl
              << "// 'Letterboxed' solver          //" << std::endl
              << "// Made by Max-190               //" << std::endl
              << "// dec 14th, 2023                //" << std::endl
              << "// Compiled using g++ with c++11 //" << std::endl
              << "///////////////////////////////////" << std::endl
              << std::endl;

    while (input != "exit") {
        try {
            print_main_menu();
            std::cout << "> ";
            std::cin >> input;
            if (input == "new") {
                std::getline(std::cin, letters);
                if (is_valid_input(letters)) {
                    // game(letters);
                } else {
                    throw std::runtime_error("Input is not valid");
                }
            }
        } catch (std::exception const &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}