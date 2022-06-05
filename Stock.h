#pragma once
#include "Common.h"
#include "Date.h"

using namespace std;

class Stock: public Common
{
	friend class Box;

protected:

	int sectionnumber;
	int amount;

public:

	Date arriveddate;

	Stock();

	Stock& operator=(const Stock& equal);
	friend bool operator>(Stock& Obj, Date& fdate);
	friend istream& operator>> (istream& in, Stock& equal);

	int GetSectionnumber();
	int GetAmount();

	void SetSectionnumber(int new_sectionnumber);
	void SetAmount(int new_amount);

	//void add_data(); // пережиток 4ой лабы
	void show_data(int favailability);
};
