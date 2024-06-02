/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 2nd June 2024
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>
#include <iostream>

namespace seneca {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);
		Book(const Book& other);
		Book& operator=(const Book& other);
		bool operator<(const Book& other) const;
		bool operator>(const Book& other) const;

		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}

#endif // SENECA_BOOK_H
