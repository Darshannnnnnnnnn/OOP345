#include "Book.h"
#include <iomanip>
#include <sstream>

namespace seneca {

    Book::Book(const std::string& strBook) {
        // Parse the book string
        std::stringstream ss(strBook);
        std::string token;

        // Extract tokens separated by commas
        std::getline(ss, token, ',');
        m_author = trimSpaces(token);

        std::getline(ss, token, ',');
        m_title = trimSpaces(token);

        std::getline(ss, token, ',');
        m_country = trimSpaces(token);

        std::getline(ss, token, ',');
        m_price = std::stod(trimSpaces(token));

        std::getline(ss, token, ',');
        m_year = std::stoi(trimSpaces(token));

        // The description is the remaining part of the string
        std::getline(ss, token);
        m_desc = trimSpaces(token);
    }

    std::string Book::trimSpaces(const std::string& str) const {
        size_t start = str.find_first_not_of(' ');
        if (start == std::string::npos) {
            return "";
        }
        size_t end = str.find_last_not_of(' ');
        return str.substr(start, end - start + 1);
    }

    // Queries
    const std::string& Book::title() const { return m_title; }
    const std::string& Book::country() const { return m_country; }
    const size_t& Book::year() const { return m_year; }
    double& Book::price() { return m_price; }

    bool Book::isEmpty() const {
        return m_title.empty();
    }

    void Book::display(std::ostream& os) const {
        os << std::right;
        os << std::setw(20) << m_author << " | "
            << std::setw(22) << m_title << " | "
            << std::setw(5) << m_country << " | "
            << std::setw(4) << m_year << " | "
            << std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | "
            << m_desc << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        book.display(os);
        return os;
    }

}
