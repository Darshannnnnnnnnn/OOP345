/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Utilities.h"
#include "Station.h"
namespace seneca {
	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name; // customer's name
		std::string m_product; // product name
		size_t m_cntItem; // count of items in order
		Item** m_lstItem; // array of pointers to Items
		static size_t m_WidthField; // maximum width of field for display purposes

	public:
		CustomerOrder(); // default constructor
		CustomerOrder(const std::string& str); // custom 1-argument constructor
		CustomerOrder(const CustomerOrder& other); // copy constructor
		CustomerOrder& operator=(const CustomerOrder& other) = delete; // copy assignment operator
		CustomerOrder(CustomerOrder&& other) noexcept; // move constructor
		CustomerOrder& operator=(CustomerOrder&& other) noexcept; // move assignment operator
		~CustomerOrder(); // destructor

		bool isOrderFilled() const; //	checking if order is filled
		bool isItemFilled(const std::string& itemName) const; // checking if the specific item is filled
		void fillItem(Station& station, std::ostream& os); // fills an item in order
		void display(std::ostream& os) const; // displays order
	};
}
#endif // SENECA_CUSTOMERORDER_H