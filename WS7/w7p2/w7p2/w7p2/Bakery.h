/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H
#include <string>
#include <iostream>
#include <vector>
#include <list>
namespace seneca
{
    enum class BakedType
    {
        BREAD,
        PASTERY
    };

    struct BakedGood
    {
        BakedType m_bakedType{};
        std::string m_description{};
        size_t m_shelfLife{};
        size_t m_stock{};
        double m_price{};
    };

    class Bakery
    {
        std::vector<BakedGood> m_bakedGoods{};
        std::string& trim(std::string& s);
    public:
        Bakery(const std::string& filename);
        void showGoods(std::ostream& os) const;
        void sortBakery(const std::string& field);
        std::vector<BakedGood> combine(Bakery& bakery);
        bool inStock(const std::string& description, const BakedType& bakedType) const;
        std::list<BakedGood> outOfStock(const BakedType& bakedType) const;
    };

    std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif