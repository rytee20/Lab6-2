#include "Stock.h"

int ControlAmount(); 
int ControlSection();
int ControlYear();
int ControlMounth();
int ControlDay(int fyear, int fmounth);

int Stock::GetSectionnumber() { return sectionnumber; }
int Stock::GetAmount() { return amount; }

void Stock::SetSectionnumber(int new_sectionnumber) 
{
    sectionnumber = new_sectionnumber;
}
void Stock::SetAmount(int new_amount) {
    amount = new_amount;
}

Stock& Stock::operator=(const Stock& equal)
{
    sectionnumber = equal.sectionnumber;
    arriveddate.mounth = equal.arriveddate.mounth;
    arriveddate.year = equal.arriveddate.year;
    arriveddate.day = equal.arriveddate.day;
    amount = equal.amount;

    return *this;
}
bool operator>(Stock& Obj, Date& fdate)
{
    if ((fdate.year < Obj.arriveddate.year) || (fdate.year == Obj.arriveddate.year && fdate.mounth < Obj.arriveddate.mounth) || (fdate.year == Obj.arriveddate.year && fdate.mounth == Obj.arriveddate.mounth && fdate.day < Obj.arriveddate.day))
        return 1;
    else
        return 0;
}
istream& operator>> (istream& in, Stock& equal)
{
    bool not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.SetAmount(ControlAmount());
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.SetSectionnumber(ControlSection());
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.year = ControlYear();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.mounth = ControlMounth();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            equal.arriveddate.day = ControlDay(equal.arriveddate.year, equal.arriveddate.mounth);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    return in;
};

/*void Stock::add_data() //пережиток 4ой лабы теперь это все в перегрузке cin'a
{
    bool not_ok = true;
    while (not_ok)
    {
        try 
        { 
            this->sectionnumber = ControlSection(); 
            not_ok = false; 
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            this->amount = ControlAmount();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            this->arriveddate.year = ControlYear();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            this->arriveddate.mounth = ControlMounth();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            this->arriveddate.day = ControlDay(arriveddate.year, arriveddate.mounth);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }
}*/ 

void Stock::show_data(int favailability)
{
    if (favailability == 1) {
        cout << sectionnumber << "\t\t" << arriveddate.day << "." << arriveddate.mounth << "." << arriveddate.year << "\t\t" << amount;
    }
    else
    {
        cout << "ТОВАРА НЕТ В НАЛИЧИИ";
    }
}

Stock::Stock()
{
        sectionnumber = 0;
        amount = 0;
}
