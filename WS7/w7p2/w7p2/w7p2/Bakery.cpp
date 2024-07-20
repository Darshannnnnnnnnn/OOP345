/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#include "Bakery.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
namespace seneca
{
    Bakery::Bakery(const std::string& filename)
    {
        ifstream file(filename);

        if (!file)
        {
            throw string("File not found");
        }

        while (file.peek() != EOF)
        {
            BakedGood bakedGood{};
            string tempString{};
            string tempBakeType{};
            string tempDescription{};
            size_t pos{};

            getline(file, tempString);

            tempBakeType = tempString.substr(pos, 8);
            trim(tempBakeType);
            pos += 8;
            if (tempBakeType == "Bread")
            {
                bakedGood.m_bakedType = BakedType::BREAD;
            }
            else if (tempBakeType == "Pastry")
            {
                bakedGood.m_bakedType = BakedType::PASTERY;
            }
            tempDescription = tempString.substr(pos, 20);
            bakedGood.m_description = trim(tempDescription);
            pos += 20;
            bakedGood.m_shelfLife = stoul(tempString.substr(pos, 14));
            pos += 14;
            bakedGood.m_stock = stoul(tempString.substr(pos, 8));
            pos += 8;
            bakedGood.m_price = stod(tempString.substr(pos));

            m_bakedGoods.push_back(bakedGood);
        }
    }
    void Bakery::showGoods(std::ostream& os) const
    {
        size_t totalStock{};
        double totalPrice{};

        for_each(m_bakedGoods.begin(), m_bakedGoods.end(), [&os](const auto& good) {
            os << good << endl;
            });

        //for_each(m_bakedGoods.begin(), m_bakedGoods.end(), [&totalStock, &totalPrice](const auto& good) {
        //   totalStock += good.m_stock;
        //   totalPrice += good.m_price;
        //   });

        totalStock = accumulate(m_bakedGoods.begin(), m_bakedGoods.end(), 0, [](auto totalStock, const auto& good) {
            return totalStock + good.m_stock;
            });
        totalPrice = accumulate(m_bakedGoods.begin(), m_bakedGoods.end(), 0.0, [](auto totalPrice, const auto& good) {
            return totalPrice + good.m_price;
            });

        os << "Total Stock: " << totalStock << endl;
        os << "Total Price: " << fixed << setprecision(2) << totalPrice << endl;
    }
    void Bakery::sortBakery(const string& field)
    {
        if (field == "Description")
        {
            sort(m_bakedGoods.begin(), m_bakedGoods.end(), [](const auto& goods1, const auto& goods2) {
                return goods1.m_description < goods2.m_description;
                });
        }
        else if (field == "Shelf")
        {
            sort(m_bakedGoods.begin(), m_bakedGoods.end(), [](const auto& goods1, const auto& goods2) {
                return goods1.m_shelfLife < goods2.m_shelfLife;
                });
        }
        else if (field == "Stock")
        {
            sort(m_bakedGoods.begin(), m_bakedGoods.end(), [](const auto& goods1, const auto& goods2) {
                return goods1.m_stock < goods2.m_stock;
                });
        }
        else if (field == "Price")
        {
            sort(m_bakedGoods.begin(), m_bakedGoods.end(), [](const auto& goods1, const auto& goods2) {
                return goods1.m_price < goods2.m_price;
                });
        }
    }
    std::vector<BakedGood> Bakery::combine(Bakery& bakery)
    {
        vector<BakedGood> tempBakedGoods(m_bakedGoods.size() + bakery.m_bakedGoods.size());
        sortBakery("Price");
        bakery.sortBakery("Price");

        std::merge(m_bakedGoods.begin(), m_bakedGoods.end(), bakery.m_bakedGoods.begin(),
            bakery.m_bakedGoods.end(), tempBakedGoods.begin(), [](const auto& goods1, const auto& goods2) {
                return goods1.m_price < goods2.m_price;
            });

        return tempBakedGoods;
    }

    bool Bakery::inStock(const string& description, const BakedType& bakedType) const
    {
        return any_of(m_bakedGoods.begin(), m_bakedGoods.end(), [=](const auto& goods) {
            return goods.m_description == description && goods.m_bakedType == bakedType && goods.m_stock > 0;
            });
    }

    std::list<BakedGood> Bakery::outOfStock(const BakedType& bakedType) const
    {
        list<BakedGood> updatedGoods{};

        copy_if(m_bakedGoods.begin(), m_bakedGoods.end(), back_inserter(updatedGoods), [bakedType](const BakedGood& bakedGood) {
            return bakedType == bakedGood.m_bakedType && bakedGood.m_stock == 0;
            });

        return updatedGoods;
    }


    std::ostream& operator<<(std::ostream& out, const BakedGood& b)
    {
        if (b.m_bakedType == BakedType::BREAD)
        {
            out << "* " << setw(10) << left << "Bread";
        }
        else if (b.m_bakedType == BakedType::PASTERY)
        {
            out << "* " << setw(10) << left << "Pastry";
        }

        out << " * " << setw(20) << b.m_description;
        out << " * " << setw(5) << b.m_shelfLife;
        out << " * " << setw(5) << b.m_stock;
        out << " * " << setw(8) << fixed << setprecision(2) << right << b.m_price << " * ";

        return out;
    }

    std::string& Bakery::trim(std::string& s)
    {
        int first = s.find_first_not_of(' ');
        int last = s.find_last_not_of(' ');

        s.erase(0, first);
        s.erase(last + 1 - first);
        return s;
    }
}