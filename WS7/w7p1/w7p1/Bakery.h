/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

namespace seneca {

    enum class BakedType {
        BREAD,
        PASTERY
    };

    struct BakedGood {
        BakedType type;
        std::string description;
        int shelfLife;
        int stock;
        double price;
    };

    class Bakery {
    public:
        Bakery(const std::string& filename);
        void showGoods(std::ostream& os) const;

    private:
        std::vector<BakedGood> goods;

       
        BakedGood parseBakedGood(const std::string& line) const;
    };
    void printstars(std::ostream& os, int count);
  
    std::ostream& operator<<(std::ostream& out, const BakedGood& b);

}

#endif // BAKERY_H
