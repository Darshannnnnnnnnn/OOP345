/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/

#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {
    class Reservation {
        std::string m_resID{};
        std::string m_resName{};
        std::string m_email{};
        int m_numPeople{};
        int m_day{};
        int m_hour{};
    public:
        Reservation();
        void update(int day, int time);
        Reservation(const std::string& res);
        std::ostream& display(std::ostream& os) const;
        bool operator==(const Reservation& res) const;
    };
    std::ostream& operator<<(std::ostream& os, const Reservation& res);
    std::string& trim(std::string& val);
}

#endif // SENECA_RESERVATION_H
