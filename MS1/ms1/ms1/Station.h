/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <iostream>
#include <string>
#include "Utilities.h"
namespace seneca {
    class Station {
        int m_id; 
        std::string m_itemName; 
        std::string m_description; 
        size_t m_SerialNumber;
        size_t m_quantity;

        static size_t m_widthField; 
        static int id_generator; 

    public:
        Station(const std::string& record);
        ~Station();
        Station(const Station& other); 
        Station(Station&& other) noexcept;
        Station& operator=(const Station& other);
        Station& operator=(Station&& other) noexcept;
        const std::string& getItemName() const; 
        size_t  getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity(); 
        void display(std::ostream& os, bool full) const; 
    };
}
#endif // SENECA_STATION_H