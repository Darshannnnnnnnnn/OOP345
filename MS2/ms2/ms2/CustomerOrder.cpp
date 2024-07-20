/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 19th July 2024
*/
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
namespace seneca {
	size_t CustomerOrder::m_WidthField = 0; // initializing static member for field width
	// default constructor
	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}
	// parameterized constructor
	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities util; // creating an instance of Utilities to prase string
		size_t next_pos = 0; // initializing position for next token
		bool more = true; // flag to check if there are more tokens

		m_name = util.extractToken(str, next_pos, more); // extracting customer name
		m_product = util.extractToken(str, next_pos, more); // extracting product name
		m_cntItem = 0; // initializing item count
			
		std::vector<std::string> items; // vector to store item names
		// looping to extract all item names
		while (more) {
			items.push_back(util.extractToken(str, next_pos, more)); // extracting item names
		}

		m_cntItem = items.size(); // setting item count
		m_lstItem = new Item * [m_cntItem]; // allocating memory for items
		// looping to create Item objects
		for (size_t i = 0; i < m_cntItem; ++i) {
			m_lstItem[i] = new Item(items[i]); // creating an Item object
		}
		// updating field widh if neccessary
		if (util.getFieldWidth() > m_WidthField) {
			m_WidthField = util.getFieldWidth();
		}
	}
	// copy constructor - not allowed
	CustomerOrder::CustomerOrder(const CustomerOrder& other) {
		throw std::runtime_error("Copy constructor not allowed");
	}
	// move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept : CustomerOrder() {
		*this = std::move(other); // using move assignment operator
	}
	// move assignment operator
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
		// checking for self-assignment
		if (this != &other) {
			// if there are items, deleting them
			if (m_lstItem) {
				for (size_t i = 0; i < m_cntItem; ++i) {
					delete m_lstItem[i]; // deleting each item 
				}
				delete[] m_lstItem; // deleting item array
			}
			m_name = other.m_name; // move customer name
			m_product = other.m_product; // move product name
			m_cntItem = other.m_cntItem; // move item count
			m_lstItem = other.m_lstItem; // move item list

			other.m_name = ""; // resetting other object's name
			other.m_product = ""; // resetting other object's product name
			other.m_cntItem = 0; // resetting other object's item count
			other.m_lstItem = nullptr; // resetting other object's item list
		}
		return *this; // returning current object
	}
	// destructor
	CustomerOrder::~CustomerOrder() {
		// checking if there are items, deleting item
		if (m_lstItem) {
			for (size_t i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i]; // deleting each item
			}
			delete[] m_lstItem; // deleting item array
		}
	}
	// checking if order is filled
	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; ++i) {
			// checking if any item is not filled
			if (!m_lstItem[i]->m_isFilled) {
				return false; // returning false
			}
		}
		return true; // all items are filled, returning true
	}
	// checking if a specific item is filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
				return false; // if item is found and not filled, returning false
			}
		}
		return true; // item is either filled or not found, returning false
	}
	// filling an item from station
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		// looping through items
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
				// checking if station has quantity
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber(); // getting serial number
					m_lstItem[i]->m_isFilled = true; // marking item as filled
					station.updateQuantity(); // updating station's quantity
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					return; // Exit after filling the item to prevent multiple fills
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					return; // Exit if the station cannot fill the item
				}
			}
		}
	}
	// displays order details
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl; // displaying customer and product name
		// looping through items
		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
				<< std::setw(m_WidthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName << " - "
				<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl; // displaying item details
		}
	}
}