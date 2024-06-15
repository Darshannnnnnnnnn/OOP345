#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace seneca {

    //holds info about single book
    class Book {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_desc{};
    public:

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_desc);
        }

        Book() = default;
        //receives reference to unmodifiable string
        //receives formatted string to extract and parse
        Book(const std::string& strBook);
        std::string trimSpaces(const std::string& str)const;
        //queries 
        const std::string& title()const;
        const std::string& country()const;
        const size_t& year()const;

        //returns price by reference
        double& price();
        bool isEmpty()const;

        void display(std::ostream& os)const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& book);

}

#endif //!SDDS_BOOK_H