#include "Storage.h"

double ControlCost();
char* ControlName();

double Storage::GetCost() { return cost; }
char* Storage::GetName() { return name; }

void Storage::SetCost(double new_cost) {
    cost = new_cost;
}
void Storage::SetName(char* new_name) {
    name = new_name;
}

/*void Storage::add_data() //пережиток 4ой лабы
{
    bool not_ok = true;
    cout << "Введите название товара: ";
    while (not_ok) {
        try
        {
            this->name = ControlName();
            not_ok = false;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Ошибка: " << ex.what() << std::endl;
            not_ok = true;
        }
    }

    not_ok = true;
    while (not_ok)
    {
        try
        {
            this->cost = ControlCost();
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }
}*/

void Storage::show_data()
{
    cout << name << "\t\t" << cost << "\t\t";
}

Storage::Storage()
{
    name = new char[5];
    strcpy(name, "mane");
    cost = 0.0;
}

Storage& Storage::operator=(const Storage& equal)
{
    name = equal.name;
    cost = equal.cost;
    return *this;
}
istream& operator>> (istream& in, Storage& equal)
{
    char* tmpname = new char[50];
    bool not_ok = true;
    //cout << "Введите название товара: ";
    while (not_ok) {
        try
        {
            tmpname = ControlName();
            equal.SetName(tmpname);
            not_ok = false;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Ошибка: " << ex.what() << std::endl;
            not_ok = true;
        }
    }

    double tmpcost;
    not_ok = true;
    while (not_ok)
    {
        try
        {
            tmpcost = ControlCost();
            equal.SetCost(tmpcost);
            not_ok = false;
        }

        catch (const std::exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
            not_ok = true;
        }
    }

    return in;
}
