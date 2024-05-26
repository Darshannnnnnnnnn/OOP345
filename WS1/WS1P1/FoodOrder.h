#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca {
	class FoodOrder {
		char m_custName[11];
		char m_foodDesc[26];
		double m_price;
		bool m_dailySpecial;
	public:
		FoodOrder();
		void read(std::istream &is);
		void display() const;

	};
}
#endif