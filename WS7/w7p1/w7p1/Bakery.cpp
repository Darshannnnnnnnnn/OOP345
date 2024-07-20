/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#include "Bakery.h"
#include <iomanip>  
#include <iostream> 
#include <fstream>  
#include <stdexcept> 
#include <string>

namespace seneca {

    Bakery::Bakery(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        std::string line;
        while (std::getline(file, line)) {
            goods.push_back(parseBakedGood(line));
        }
    }

    void Bakery::showGoods(std::ostream& os) const {
      
        for (const auto& good : goods) {
            std::string typeStr = (good.type == BakedType::BREAD) ? "Bread" : "Pastry";
            os << "* " << std::left << std::setw(10) << typeStr
                << " * " << std::setw(20) << good.description
                << " * " << std::setw(5) << good.shelfLife
                << " * " << std::setw(5) << good.stock
                << " * " << std::setw(8) << std::fixed<<std::right << std::setprecision(2) << good.price
                << " * \n";
        }
                
    }

    BakedGood Bakery::parseBakedGood(const std::string& line) const {
        BakedGood good;
        
        good.type = line.substr(0, 8).find("Bread") != std::string::npos ? BakedType::BREAD : BakedType::PASTERY;
        good.description = line.substr(8, 20);
        good.shelfLife = std::stoi(line.substr(28, 10)); 
        good.stock = std::stoi(line.substr(38, 10));    
        good.price = std::stod(line.substr(48, 8));    

        return good;
    }

    void printstars(std::ostream& os, int count) {
        for (int i = 0; i < count; ++i) {
            os << "*";
        }
        
    }

    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        out << "* " << std::setw(10) << static_cast<int>(b.type)
            << " * " << std::setw(20) << b.description
            << " * " << std::setw(10) << b.shelfLife
            << " * " << std::setw(10) << b.stock
            << " * " << std::setw(8) << std::fixed << std::setprecision(2) << b.price
            << "*";
        return out;
    }

} // namespace seneca
