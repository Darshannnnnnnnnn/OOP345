/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/
#include "ConfirmationSender.h"


namespace seneca {
    ConfirmationSender::ConfirmationSender() : m_res(nullptr), m_numRes(0) {}

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs)
        : m_res(nullptr), m_numRes(0) {
        *this = cs;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
        if (this != &cs) {
            delete[] m_res;

            m_numRes = cs.m_numRes;
            m_res = new const Reservation * [cs.m_numRes];
            std::copy(cs.m_res, cs.m_res + cs.m_numRes, m_res);
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) noexcept
        : m_res(cs.m_res), m_numRes(cs.m_numRes) {
        cs.m_res = nullptr;
        cs.m_numRes = 0;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) noexcept {
        if (this != &cs) {
            delete[] m_res;

            m_res = cs.m_res;
            m_numRes = cs.m_numRes;

            cs.m_res = nullptr;
            cs.m_numRes = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_res;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        if (!isExist(res)) {
            const Reservation** temp = new const Reservation * [m_numRes + 1];
            std::copy(m_res, m_res + m_numRes, temp);
            temp[m_numRes] = &res;
            delete[] m_res;
            m_res = temp;
            m_numRes++;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        auto it = std::find_if(m_res, m_res + m_numRes,
            [&res](const Reservation* r) { return *r == res; });
        if (it != m_res + m_numRes) {
            std::move(it + 1, m_res + m_numRes, it);
            m_numRes--;
        }
        return *this;
    }

    bool ConfirmationSender::isExist(const Reservation& res) const {
        return std::any_of(m_res, m_res + m_numRes,
            [&res](const Reservation* r) { return *r == res; });
    }

    std::ostream& ConfirmationSender::display(std::ostream& os) const {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (m_numRes == 0) {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < m_numRes; ++i) {
                os << *m_res[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
        return cs.display(os);
    }
}
