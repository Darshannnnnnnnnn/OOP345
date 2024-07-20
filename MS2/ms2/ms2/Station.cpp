/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#include <iomanip>
#include "Station.h"
namespace seneca {
    size_t Station::m_widthField = 0; // initializing static member variable m_widthField to 0
    int Station::id_generator = 0; // initializing static member variable id_generator to 0
    // constructor that initializeing a Station object from a record string
    Station::Station(const std::string& record) : m_id(++id_generator) {
        Utilities util; // creating an instance of Utilities
        size_t next_pos = 0; // initializing next_pos to 0
        bool more = true; // initializing more to true

        m_itemName = util.extractToken(record, next_pos, more); // extracting and setting item name
        m_SerialNumber = std::stoul(util.extractToken(record, next_pos, more)); // extracting and setting serial number
        m_quantity = std::stoul(util.extractToken(record, next_pos, more)); // extracting and setting quantity
        m_description = util.extractToken(record, next_pos, more); // extracting and setting description
        // checking if extracted field width is greater than m_widthField
        if (util.getFieldWidth() > m_widthField) {
            m_widthField = util.getFieldWidth(); // updating m_widthField
        }
    }
    // destructor
    Station::~Station() = default;
    // copy constructor
    Station::Station(const Station& other) : m_id(0) {
        *this = other; // using copy assignment operator
    }
    // move constructor
    Station::Station(Station&& other) noexcept : m_id(0) {
        *this = std::move(other); // using move assignment operator
    }
    //copy assignment operator
    Station& Station::operator=(const Station& other) {
        // checking for self-assignment
        if (this != &other) {
            m_id = other.m_id; // copying ID
            m_itemName = other.m_itemName; // copy item name
            m_description = other.m_description; // copy description
            m_SerialNumber = other.m_SerialNumber; // copy serial number
            m_quantity = other.m_quantity; // copy quantity
        }
        return *this;
    }
    // move assignment operator     
    Station& Station::operator=(Station&& other) noexcept {
        // checking for self-assignment
        if (this != &other) {
            m_id = other.m_id; // move ID
            m_itemName = std::move(other.m_itemName); // move item name
            m_description = std::move(other.m_description); // move description
            m_SerialNumber = other.m_SerialNumber; // move serial number
            m_quantity = other.m_quantity; // move quantity

            other.m_id = 0; // resetting moved-form object's ID
            other.m_SerialNumber = 0; // resetting moved-form object's serial number
            other.m_quantity = 0; // resetting moved-form object's quantity
        }
        return *this;
    }
    // returning item name
    const std::string& Station::getItemName() const {
        return m_itemName; // returning m_itemName
    }
    // returning next serial number
    size_t Station::getNextSerialNumber() {
        return m_SerialNumber++; // incrementing and returning m_SerialNumber
    }
    // returning quantity
    size_t Station::getQuantity() const {
        return m_quantity; // returning m_quantity
    }
    // updating quantity
    void Station::updateQuantity() {
        // checking if m_quantity is greater than 0
        if (m_quantity > 0) {
            m_quantity--; // decreasing m_quantity by 1
        }
    }
    // displaying station object
    void Station::display(std::ostream& os, bool full) const {
        // displaying ID, itemName, SerialNumber
        os << std::setw(3) << std::setfill('0') << m_id << " | "
            << std::setw(14) << std::left << std::setfill(' ') << m_itemName << " | "
            << std::setw(6) << std::right << std::setfill('0') << m_SerialNumber << " | ";
        // checking if full s true
        if (full) {
            os << std::setw(4) << std::right << std::setfill(' ') << m_quantity << " | " << m_description; // displaying quantity and description
        }
        os << std::endl; // ending line
    }
}