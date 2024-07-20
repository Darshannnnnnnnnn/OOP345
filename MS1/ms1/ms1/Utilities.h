/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 11th July 2024
*/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include <iostream>
#include <string>
#include <stdexcept>
namespace seneca {
    class Utilities {
        size_t m_widthField{ 1 }; 
        static char m_delimiter; 

    public:
        void setFieldWidth(size_t newWidth); 
        size_t getFieldWidth() const; 
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more); 
        static void setDelimiter(char newDelimiter);
        static char getDelimiter(); 
    };
}
#endif // SENECA_UTILITIES_H