#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca {
	class FoodOrder {
		char m_custName[11];
		char* m_foodDesc;
		double m_price;
		bool m_dailySpecial;
	public:
		FoodOrder();
		~FoodOrder();
		FoodOrder(const FoodOrder& other); 
		FoodOrder& operator=(const FoodOrder& other); 
		void read(std::istream& is);
		void display() const;
	};
}
#endif