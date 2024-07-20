/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <iostream>
#include <string>
#include "Utilities.h"
namespace seneca {
    class Station {
        int m_id; // member variable to store ID
        std::string m_itemName; // member variable to store item name
        std::string m_description; // member variable to store description
        size_t m_SerialNumber; // member variable to store serial number
        size_t m_quantity; // member variable to store quantity

        static size_t m_widthField; // static member variable to store field width
        static int id_generator; // static member variable to generate IDs

    public:
        Station(const std::string& record); // constructor that initializeing a Station object from a record string
        ~Station(); // destructor
        Station(const Station& other); // copy constructor
        Station(Station&& other) noexcept; // move constructor
        Station& operator=(const Station& other); //copy assignment operator
        Station& operator=(Station&& other) noexcept; // move assignment operator
        const std::string& getItemName() const; // returning item name
        size_t  getNextSerialNumber(); // returning next serial number
        size_t getQuantity() const; // returning quantity
        void updateQuantity(); // updating quantity
        void display(std::ostream& os, bool full) const; // displaying station object
    };
}
#endif // SENECA_STATION_H