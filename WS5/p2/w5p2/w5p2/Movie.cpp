#include "Movie.h"

#include <iostream>
#include <string>
#include <iomanip>

namespace seneca {

    Movie::Movie(const std::string& strMovie) {
        size_t start = 0;
        m_title = extract(strMovie, start, ',');
        m_year = std::stod(extract(strMovie, start, ','));
        m_desc = extract(strMovie, start, '\n');
    }

    const std::string& Movie::title()const {
        return m_title;
    }
    std::string Movie::extract(const std::string& str, size_t& start, char delim) {
        const size_t end = str.find(delim, start);
        std::string token;
        if (end == std::string::npos) {
            token = str.substr(start, std::string::npos);
            start = std::string::npos;
        }
        else {
            token = str.substr(start, end - start);
            start = end + 1;
        }
        // Trim spaces
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        return token;
    }
    void Movie::display(std::ostream& os)const {
        //os << ' ';
        os.width(40);
        os << std::right << m_title << " | ";
        os.width(4);
        os << std::right << m_year << " | ";
        os << m_desc << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        movie.display(os);
        return os;
    }
}