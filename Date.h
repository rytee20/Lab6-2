#pragma once
#include <iostream>
using namespace std;

class Date
{
public:

    int day;
    int mounth;
    int year;

    Date& operator=(const Date& equal);

    Date();
};
