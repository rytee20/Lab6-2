#pragma once
#include "Common.h"
#include "Date.h"

double ControlCost();
char* ControlName();

using namespace std;

class Storage: public Common
{
    friend class Box;

protected:

    char* name;
    double cost;
    //int amount;

public:

    Storage& operator=(const Storage& equal);
    friend istream& operator>> (istream& in, Storage& equal);

    double GetCost();
    char* GetName();
    //int GetAmount();

    void SetCost(double new_cost);
    void SetName(char* new_name);

    //void add_data(); // пережиток 4ой лабы
    void show_data();

    Storage();
};
