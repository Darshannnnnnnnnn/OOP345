/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace seneca {
    class Restaurant {
        Reservation** m_res{};
        size_t m_numReservations{ 0 };
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& res);
        Restaurant& operator=(const Restaurant& res);
        ~Restaurant();
        Restaurant(Restaurant&& res) noexcept;
        Restaurant& operator=(Restaurant&& res) noexcept;
        size_t size() const;
        std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Restaurant& res);
}

#endif // SENECA_RESTAURANT_H
