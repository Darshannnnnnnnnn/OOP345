/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>
#include <algorithm>

namespace seneca {
    class ConfirmationSender {
        const Reservation** m_res{};
        size_t m_numRes{ 0 };
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& cs);
        ConfirmationSender& operator=(const ConfirmationSender& cs);
        ConfirmationSender(ConfirmationSender&& cs) noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& cs) noexcept;
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        bool isExist(const Reservation& res) const;

        std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
}

#endif // SENECA_CONFIRMATIONSENDER_H
