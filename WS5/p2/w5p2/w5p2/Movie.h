#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace seneca {

    class Movie {
        std::string m_title{};
        size_t m_year{};
        std::string m_desc{};
    public:

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_desc);
        }

        Movie() = default;
        Movie(const std::string& strMovie);
        const std::string& title()const;
        std::string extract(const std::string& str, size_t& start, char delim);
        // std::string trimSpaces(const std::string& str)const;
        void display(std::ostream& os)const;
    };

    std::ostream& operator<<(std::ostream& os, const Movie& movie);


}

#endif