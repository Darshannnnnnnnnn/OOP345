#define _CRT_SECURE_NO_WARNINGS
#include"FoodOrder.h"
#include<iostream>
#include<iomanip>
#include <cstring>
#include <string>

double g_taxrate;
double g_dailydiscount;

namespace seneca {
	FoodOrder::FoodOrder()
	{
		m_custName[0] = '\0';
		m_foodDesc = nullptr;
		m_price = 0.0;
		m_dailySpecial = false;
	}
	FoodOrder::~FoodOrder()
	{
		delete[] m_foodDesc;
	}

	FoodOrder::FoodOrder(const FoodOrder& other)
		: m_price(other.m_price), m_dailySpecial(other.m_dailySpecial) {
		std::strcpy(m_custName, other.m_custName);

		// Allocate memory for m_foodDesc and copy the string
		m_foodDesc = new char[std::strlen(other.m_foodDesc) + 1];
		std::strcpy(m_foodDesc, other.m_foodDesc);
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& other) {
		if (this != &other) {
			// Copy member variables
			m_price = other.m_price;
			m_dailySpecial = other.m_dailySpecial;
			std::strcpy(m_custName, other.m_custName);

			// Deallocate previous memory if necessary
			delete[] m_foodDesc;

			// Allocate memory for m_foodDesc and copy the string
			m_foodDesc = new char[std::strlen(other.m_foodDesc) + 1];
			std::strcpy(m_foodDesc, other.m_foodDesc);
		}
		return *this;
	}
	void FoodOrder::read(std::istream& is)
	{
		if (is.good()) {
			char dailySpecial;
			std::string TfoodDesc;
			is.getline(m_custName, 11, ',');
			std::getline(is, TfoodDesc, ',');
			is >> m_price;
			is.ignore();
			is >> dailySpecial;
			is.ignore();
			m_dailySpecial = (dailySpecial == 'Y');

			// Deallocate previous memory if necessary
			delete[] m_foodDesc;

			// Allocate memory for m_foodDesc and copy the string
			m_foodDesc = new char[TfoodDesc.length() + 1];
			std::strcpy(m_foodDesc, TfoodDesc.c_str());

		}
	}
	void FoodOrder::display() const
	{
		static int counter = 0;
		counter++;

		std::cout.width(2);
		std::cout << std::left << counter << ". ";

		if (m_custName[0] == '\0') {
			std::cout << "No Order" << std::endl;
		}
		else {
			double priceTaxed = m_price * (1 + g_taxrate);
			std::cout.width(10);
			std::cout << std::left << m_custName << "|";
			std::cout.width(25);
			std::cout << std::left << m_foodDesc << "|";
			std::cout.width(12);
			std::cout << std::left << std::fixed << std::setprecision(2) << priceTaxed << "|";

			if (m_dailySpecial) {
				double priceSpecial = priceTaxed - g_dailydiscount;
				std::cout.width(13);
				std::cout << std::right << std::fixed << std::setprecision(2) << priceSpecial;
			}
			std::cout << std::endl;


		}
	}
}