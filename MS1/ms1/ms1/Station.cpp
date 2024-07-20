/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#include <iomanip>
#include "Station.h"
namespace seneca {
    size_t Station::m_widthField = 0; 
    int Station::id_generator = 0; 
    
    Station::Station(const std::string& record) : m_id(++id_generator) {
        Utilities util; 
        size_t next_pos = 0;
        bool more = true;

        m_itemName = util.extractToken(record, next_pos, more); 
        m_SerialNumber = std::stoul(util.extractToken(record, next_pos, more));
        m_quantity = std::stoul(util.extractToken(record, next_pos, more));
        m_description = util.extractToken(record, next_pos, more);
       
        if (util.getFieldWidth() > m_widthField) {
            m_widthField = util.getFieldWidth(); 
        }
    }
    
    Station::~Station() = default;
    
    Station::Station(const Station& other) : m_id(0) {
        *this = other; 
    }
    
    Station::Station(Station&& other) noexcept : m_id(0) {
        *this = std::move(other); 
    }
    
    Station& Station::operator=(const Station& other) {
        
        if (this != &other) {
            m_id = other.m_id; 
            m_itemName = other.m_itemName; 
            m_description = other.m_description; 
            m_SerialNumber = other.m_SerialNumber; 
            m_quantity = other.m_quantity;
        }
        return *this; 
    }
 
    Station& Station::operator=(Station&& other) noexcept {
       
        if (this != &other) {
            m_id = other.m_id;
            m_itemName = std::move(other.m_itemName);
            m_description = std::move(other.m_description);
            m_SerialNumber = other.m_SerialNumber; 
            m_quantity = other.m_quantity;

            other.m_id = 0; 
            other.m_SerialNumber = 0;
            other.m_quantity = 0;
        }
        return *this;
    }
   
    const std::string& Station::getItemName() const {
        return m_itemName; 
    }
    
    size_t Station::getNextSerialNumber() {
        return m_SerialNumber++; 
    }
    
    size_t Station::getQuantity() const {
        return m_quantity; 
    }
    
    void Station::updateQuantity() {
    
        if (m_quantity > 0) {
            m_quantity--;
        }
    }
    
    void Station::display(std::ostream& os, bool full) const {
      
        os << std::setw(3) << std::setfill('0') << m_id << " | "
            << std::setw(14) << std::left << std::setfill(' ') << m_itemName << " | "
            << std::setw(6) << std::right << std::setfill('0') << m_SerialNumber << " | ";
        
        if (full) {
            os << std::setw(4) << std::right << std::setfill(' ') << m_quantity << " | " << m_description; 
        }
        os << std::endl; 
    }
}