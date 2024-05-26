#include"FoodOrder.h"
#include<iostream>
#include<iomanip>
#include <cstring>

double g_taxrate;
double g_dailydiscount;

namespace seneca {
	FoodOrder::FoodOrder()
	{
		m_custName[0] = '\0';
		m_foodDesc[0] = '\0';
		m_price = 0.0;
		m_dailySpecial = false;
	}
	void FoodOrder::read(std::istream& is)
	{
		if (is.good()) {
			char dailySpecial;
			is.getline(m_custName, 11, ',');
			is.getline(m_foodDesc, 26, ',');
			is >> m_price;
			is.ignore();
			is >> dailySpecial;
			is.ignore();
			m_dailySpecial = (dailySpecial == 'Y');

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
				std::cout << std::left  <<std::fixed<< std::setprecision(2)<< priceTaxed << "|";
				
				if (m_dailySpecial) {
					double priceSpecial = priceTaxed - g_dailydiscount;
					std::cout.width(13);
					std::cout << std::right <<std::fixed<<std::setprecision(2)<< priceSpecial;
				}
				std::cout << std::endl;


			}
	}
}