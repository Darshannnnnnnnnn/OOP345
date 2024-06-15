#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

const size_t MAX_WORDS = 6;

namespace seneca {

    class SpellChecker {
        std::string m_bad[MAX_WORDS]{};
        std::string m_good[MAX_WORDS]{};
        size_t m_replaced[MAX_WORDS]{};
    public:
        SpellChecker() = default;
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out)const;
    };

}

#endif