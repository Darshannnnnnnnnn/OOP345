#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

namespace seneca {

    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::invalid_argument("Bad file name!");
        }

        for (size_t i = 0; i < MAX_WORDS && file; ++i) {
            file >> m_bad[i] >> m_good[i];
            m_replaced[i] = 0;
        }

        if (file.fail() && !file.eof()) {
            throw std::runtime_error("Error reading file!");
        }
        file.close();
    }

    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < MAX_WORDS; ++i) {
            size_t pos = text.find(m_bad[i]);
            while (pos != std::string::npos) {
                text.replace(pos, m_bad[i].length(), m_good[i]);
                ++m_replaced[i];
                pos = text.find(m_bad[i], pos + m_good[i].length());
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (size_t i = 0; i < MAX_WORDS; ++i) {
            out << std::setw(15) << std::right << m_bad[i] << ": "
                << m_replaced[i] << " replacements" << std::endl;
        }
    }

}
