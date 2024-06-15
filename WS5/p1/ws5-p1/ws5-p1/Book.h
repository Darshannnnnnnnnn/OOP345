/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 14th June 2024
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>

namespace seneca {
    class Book {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_description{};
        void setEmpty();
    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        std::ostream& display(std::ostream& os) const;
    };
    std::string& trim(std::string& val);
    std::ostream& operator<<(std::ostream& os, const Book& b);
}

#endif // !SDDS_BOOK_H
