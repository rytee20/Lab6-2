#include "Common.h"

int ControlCommand2();

Common::Common()
{
	availability = 0;
}

Common& Common::operator=(const Common& equal)
{
	availability = equal.availability;
	return *this;
}

void Common::add_data()
{
	bool not_ok = true;
	//cout << "Введите название товара: ";
	while (not_ok) {
		try
		{
			this->availability = ControlCommand2();
			not_ok = false;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Ошибка: " << ex.what() << std::endl;
			not_ok = true;
		}
	}
}

void Common::show_data()
{
	cout << availability << "\t\t";
}
