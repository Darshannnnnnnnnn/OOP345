/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 2nd June 2024
*/
#include "Book.h"
#include <iomanip>

namespace seneca {
	Book::Book() {
		m_title = "";
		m_numChapters = 0;
		m_numPages = 0;
	}
	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) {
		m_title = title;
		m_numChapters = nChapters;
		m_numPages = nPages;
	}

	//part 2
	bool Book::operator<(const Book& other) const {
		double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
		double pagesPerChapter2 = other.m_numPages / static_cast<double>(other.m_numChapters);
		return pagesPerChapter < pagesPerChapter2 ? true : false;
	}

	bool Book::operator>(const Book& other) const {
		double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
		double pagesPerChapter2 = other.m_numPages / static_cast<double>(other.m_numChapters);
		return pagesPerChapter > pagesPerChapter2 ? true : false;
	}

	std::ostream& Book::print(std::ostream& os) const {
		if (m_title != "") {
			std::string collect = m_title;
			collect.append(",");
			collect.append(std::to_string(m_numChapters));
			collect.append(",");
			collect.append(std::to_string(m_numPages));
			//os << std::setw(53) << std::right << m_title << ',' << m_numChapters << ',' << m_numPages;
			os << std::setw(56) << std::right << collect;
			double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
			os << " | (" << std::left << std::fixed << std::setprecision(6) << pagesPerChapter << ")    ";
			os << std::defaultfloat;
		}
		else {
			os << "| Invalid book data";
		}

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		return bk.print(os);
	}

	Book::Book(const Book& other) {
		m_title = other.m_title;
		m_numChapters = other.m_numChapters;
		m_numPages = other.m_numPages;
	}

	Book& Book::operator=(const Book& other) {
		m_title = other.m_title;
		m_numChapters = other.m_numChapters;
		m_numPages = other.m_numPages;
		return *this;
	}


}
