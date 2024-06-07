/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 7th June 2024
*/
#include "Reservation.h"
#include <iomanip>
#include <sstream>

using namespace std;

namespace seneca {

    Reservation::Reservation()
        : m_resID(""), m_resName(""), m_email(""), m_numPeople(0), m_day(0), m_hour(0) {}

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    Reservation::Reservation(const std::string& res) {
        stringstream ss(res);
        string token;

        getline(ss, token, ':');
        m_resID = trim(token);

        getline(ss, token, ',');
        m_resName = trim(token);

        getline(ss, token, ',');
        m_email = trim(token);

        getline(ss, token, ',');
        m_numPeople = stoi(token);

        getline(ss, token, ',');
        m_day = stoi(token);

        getline(ss, token);
        m_hour = stoi(token);
    }

    std::ostream& Reservation::display(std::ostream& os) const {
        string email = "  <" + m_email + ">";
        os << right << "Reservation ";
        os.width(10);
        os << m_resID << ":";
        os.width(21);
        os << m_resName << left << setw(26) << email;
        if (m_hour >= 6 && m_hour <= 9) os << "Breakfast on day ";
        else if (m_hour >= 11 && m_hour <= 15) os << "Lunch on day ";
        else if (m_hour >= 17 && m_hour <= 21) os << "Dinner on day ";
        else os << "Drinks on day ";
        os << m_day << " @ " << m_hour << ":00 for " << m_numPeople << (m_numPeople == 1 ? " person." : " people.") << endl;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        return res.display(os);
    }

    std::string& trim(std::string& val) {
        size_t start = val.find_first_not_of(' ');
        size_t end = val.find_last_not_of(' ');
        if (start == std::string::npos || end == std::string::npos) {
            val.clear();
        }
        else {
            val = val.substr(start, end - start + 1);
        }
        return val;
    }

    bool Reservation::operator==(const Reservation& res) const {
        return m_resID == res.m_resID && m_resName == res.m_resName
            && m_email == res.m_email && m_numPeople == res.m_numPeople
            && m_day == res.m_day && m_hour == res.m_hour;
    }
}

