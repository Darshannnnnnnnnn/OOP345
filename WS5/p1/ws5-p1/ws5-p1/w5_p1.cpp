#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"

int cout = 0; 

enum AppErrors
{
    CannotOpenFile = 1, 
    BadArgumentCount = 2, 
};


int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; ++i)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    seneca::Book library[7];
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
            exit(AppErrors::CannotOpenFile);
        }

        std::string line;
        int index = 0;
        while (std::getline(file, line) && index < 7) {
            if (line[0] != '#') {
                library[index] = seneca::Book(line);
                index++;
            }
        }
    }
    else
    {
        std::cerr << "ERROR: Incorrect number of arguments.\n";
        exit(AppErrors::BadArgumentCount);
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    auto fixPrice = [usdToCadRate, gbpToCadRate](seneca::Book& book) {
        if (book.country() == "US") {
            book.price() *= usdToCadRate;
        }
        else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
            book.price() *= gbpToCadRate;
        }
        };

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    for (const auto& book : library) {
        std::cout << book;
    }
    std::cout << "-----------------------------------------\n\n";

    for (auto& book : library) {
        fixPrice(book);
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    for (const auto& book : library) {
        std::cout << book;
    }
    std::cout << "-----------------------------------------\n";

    return cout;
}
