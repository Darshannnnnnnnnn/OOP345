/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Database.h"
namespace seneca {
    
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::instance = nullptr;
    
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& filename) {
        
        if (!instance) {
            instance = std::shared_ptr<Database<T>>(new Database<T>(filename)); 
        }
        return instance; 
    }
    
    template <typename T>
    Database<T>::Database(const std::string& filename) : dbFileName(filename), numEntries(0), keys({}), values({}) {
        std::ostringstream oss; 
        uintptr_t address = reinterpret_cast<uintptr_t>(this); 
        oss << "[0x" << std::hex << address << "] Database(const std::string&)";
        std::string addressStr = oss.str(); 

        std::size_t start = addressStr.find("0x") + 2; 
        std::string hexPart = addressStr.substr(start, std::string::npos); 
        if (hexPart.length() > 7) { 
            hexPart = hexPart.substr(hexPart.length() - 7);
        }
        
        std::cout << "[0x" << hexPart << "] Database(const std::string&)" << std::endl;

        std::ifstream file(filename); 
        if (file.is_open()) { 
            std::string key;
            T value; 
            while (file >> key >> value) {
                for (char& ch : key) { 
                    if (ch == '_') ch = ' ';
                }
                encryptDecrypt(value); 
                keys[numEntries] = key; 
                values[numEntries] = value; 
                ++numEntries; 
                if (numEntries >= 20) break; 
            }
            file.close(); 
        }
        else { 
            std::cerr << "Error opening file: " << filename << std::endl; 
        }
    }
   
    template <typename T>
    Err_Status Database<T>::GetValue(const std::string& key, T& value) {
        for (size_t i = 0; i < numEntries; ++i) { 
            if (keys[i] == key) { 
                value = values[i]; 
                return Err_Status::Err_Success; 
            }
        }
        return Err_Status::Err_NotFound;
    }
    
    template <typename T>
    Err_Status Database<T>::SetValue(const std::string& key, const T& value) {
        if (numEntries < 20) { 
            keys[numEntries] = key; 
            values[numEntries] = value; 
            ++numEntries; 
            return Err_Status::Err_Success; 
        }
        return Err_Status::Err_OutOfMemory; 
    }
    
    template <typename T>
    Database<T>::Database(const Database& other) : dbFileName(other.dbFileName), numEntries(0), keys({}), values({}) {
        *this = other; 
    }
   
    template <typename T>
    Database<T>::Database(Database&& other) noexcept : dbFileName(std::move(other.dbFileName)), numEntries(0), keys({}), values({}) {
        *this = std::move(other); 
    }
    
    template <typename T>
    Database<T>& Database<T>::operator=(const Database& other) {
        if (this != &other) { 
            dbFileName = other.dbFileName; 
            numEntries = other.numEntries; 
            std::copy(other.keys.begin(), other.keys.end(), keys.begin()); 
            std::copy(other.values.begin(), other.values.end(), values.begin()); 
        }
        return *this; 
    }
   
    template <typename T>
    Database<T>& Database<T>::operator=(Database&& other) noexcept {
        if (this != &other) { 
            dbFileName = std::move(other.dbFileName);
            numEntries = other.numEntries; 
            std::move(other.keys.begin(), other.keys.end(), keys.begin()); 
            std::move(other.values.begin(), other.values.end(), values.begin()); 
            other.numEntries = 0; 
        }
        return *this; 
    }
   
    template <typename T>
    Database<T>::~Database() {
        std::ostringstream oss; 
        uintptr_t address = reinterpret_cast<uintptr_t>(this);
        oss << "[0x" << std::hex << address << "] ~Database()"; 
        std::string addressStr = oss.str();

        
        std::size_t start = addressStr.find("0x") + 2;
        std::string hexPart = addressStr.substr(start, std::string::npos);
        if (hexPart.length() > 7) {
            hexPart = hexPart.substr(hexPart.length() - 7);
        }

        std::cout << "[0x" << hexPart << "] ~Database()" << std::endl; 

        std::ofstream backupFile(dbFileName + ".bkp.txt"); 
        if (backupFile.is_open()) { 
            for (size_t i = 0; i < numEntries; ++i) { 
                T value = values[i]; 
                encryptDecrypt(value); 
                backupFile << std::left << std::setw(25) << keys[i] << " -> " << value << std::endl; 
            }
            backupFile.close(); 
        }
    }
  
    template <>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[] = "secret encryption key"; 
        for (char& c : value) { 
            for (const char k : secret) { 
                c ^= k; 
            }
        }
    }
   
    template <>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[] = "super secret encryption key"; 
        char* valuePtr = reinterpret_cast<char*>(&value); 
        for (size_t i = 0; i < sizeof(value); ++i) { 
            for (const char k : secret) { 
                valuePtr[i] ^= k;
            }
        }
    }
}

template class seneca::Database<std::string>;
template class seneca::Database<long long>;