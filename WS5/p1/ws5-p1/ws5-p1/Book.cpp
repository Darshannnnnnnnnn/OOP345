/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 14th June 2024
*/
#include "Book.h"
#include <iomanip>

namespace seneca {
    void Book::setEmpty() {
        m_author = "";
        m_title = "";
        m_country = "";
        m_year = 0;
        m_price = 0.0;
        m_description = "";
    }
    Book::Book() {
        setEmpty();
    }
    const std::string& Book::title() const {
        return m_title;
    }
    const std::string& Book::country() const {
        return m_country;
    }
    const size_t& Book::year() const {
        return m_year;
    }
    double& Book::price() {
        return m_price;
    }
    Book::Book(const std::string& strBook) {
        std::string a = strBook;
        size_t n = a.find(',');
        m_author = a.substr(0, n);
        m_author = trim(m_author);

        std::string b = a.substr(n + 1);
        n = b.find(',');
        m_title = b.substr(0, n);
        m_title = trim(m_title);

        std::string c = b.substr(n + 1);
        n = c.find(',');
        m_country = c.substr(0, n);
        m_country = trim(m_country);

        std::string d = c.substr(n + 1);
        n = d.find(',');
        m_price = std::stod(d.substr(0, n));

        std::string e = d.substr(n + 1);
        n = e.find(',');
        m_year = std::stoi(e.substr(0, n));

        std::string f = e.substr(n + 1);
        m_description = trim(f);
    }
    std::ostream& Book::display(std::ostream& os) const {
        os << std::setw(20) << m_author << " | ";
        os << std::setw(22) << m_title << " | ";
        os << std::setw(5) << m_country << " | ";
        os << std::setw(4) << m_year << " | ";
        os << std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | ";
        os << m_description << std::endl;

        return os;
    }

    std::string& trim(std::string& val) {
        size_t first = val.find_first_not_of(' ');
        size_t last = val.find_last_not_of(' ');
        val = val.substr(first, (last - first + 1));
        return val;
    }

    std::ostream& operator<<(std::ostream& os, const Book& b) {
        return b.display(os);
    }
}
