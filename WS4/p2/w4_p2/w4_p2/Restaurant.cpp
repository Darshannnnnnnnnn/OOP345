/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/
#include "Restaurant.h"

namespace seneca {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
        : m_numReservations(cnt) {
        m_res = new Reservation * [cnt];
        for (size_t i = 0; i < cnt; ++i) {
            m_res[i] = new Reservation(*reservations[i]);
        }
    }

    Restaurant::Restaurant(const Restaurant& res)
        : m_res(nullptr), m_numReservations(0) {
        *this = res;
    }

    Restaurant& Restaurant::operator=(const Restaurant& res) {
        if (this != &res) {
            for (size_t i = 0; i < m_numReservations; ++i) {
                delete m_res[i];
            }
            delete[] m_res;

            m_numReservations = res.m_numReservations;
            m_res = new Reservation * [m_numReservations];
            for (size_t i = 0; i < m_numReservations; ++i) {
                m_res[i] = new Reservation(*res.m_res[i]);
            }
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_numReservations; ++i) {
            delete m_res[i];
        }
        delete[] m_res;
    }

    Restaurant::Restaurant(Restaurant&& res) noexcept
        : m_res(res.m_res), m_numReservations(res.m_numReservations) {
        res.m_res = nullptr;
        res.m_numReservations = 0;
    }

    Restaurant& Restaurant::operator=(Restaurant&& res) noexcept {
        if (this != &res) {
            for (size_t i = 0; i < m_numReservations; ++i) {
                delete m_res[i];
            }
            delete[] m_res;

            m_res = res.m_res;
            m_numReservations = res.m_numReservations;

            res.m_res = nullptr;
            res.m_numReservations = 0;
        }
        return *this;
    }

    size_t Restaurant::size() const {
        return m_numReservations;
    }

    std::ostream& Restaurant::display(std::ostream& os) const {
        static int callCount = 0;
        callCount++;
        os << "--------------------------\n";
        os << "Fancy Restaurant (" << callCount << ")\n";
        os << "--------------------------\n";
        if (m_numReservations == 0) {
            os << "This restaurant is empty!\n";
        }
        else {
            for (size_t i = 0; i < m_numReservations; ++i) {
                os << *m_res[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
        return res.display(os);
    }
}
