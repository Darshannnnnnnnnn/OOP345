/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 25th May 2024
*/

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>
#include <vector>

namespace seneca {

    class ProteinDatabase {
        std::vector<std::string> sequences;

    public:
        ProteinDatabase();
        ProteinDatabase(const std::string& filename);

        size_t size() const;
        std::string operator[](size_t index) const;

        ProteinDatabase(const ProteinDatabase& other);
        ProteinDatabase& operator=(const ProteinDatabase& other);
        ~ProteinDatabase();
    };

}

#endif // SENECA_PROTEINDATABASE_H
