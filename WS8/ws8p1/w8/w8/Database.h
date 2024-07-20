/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H
#include <iostream>
#include <string>
#include <memory>
#include <cstdint>
#include <array>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
namespace seneca {
    
    enum class Err_Status {
        Err_Success,
        Err_NotFound, 
        Err_OutOfMemory, 
    };
   
    template <typename T>
    class Database {
    public:
        static std::shared_ptr<Database> getInstance(const std::string& filename);
        Err_Status GetValue(const std::string& key, T& value); 
        Err_Status SetValue(const std::string& key, const T& value); 
        
        Database(const Database& other); 
        Database(Database&& other) noexcept; 
        Database& operator=(const Database& other); 
        Database& operator=(Database&& other) noexcept; 
        ~Database(); 

    private:
        Database(const std::string& filename); 
        void encryptDecrypt(T& value);
        static std::shared_ptr<Database> instance; 
        std::string dbFileName; 
        size_t numEntries = 0; 
        std::array<std::string, 20> keys = {};
        std::array<T, 20> values = {};
    };

    
    template <>
    void Database<std::string>::encryptDecrypt(std::string& value);
    
    template <>
    void Database<long long>::encryptDecrypt(long long& value);
}
#endif // SENECA_DATABASE_H