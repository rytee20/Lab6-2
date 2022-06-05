#include "Date.h"

Date::Date()
{
    day = 0;
    mounth = 0;
    year = 0;
}

Date& Date::operator=(const Date& equal)
{
    day = equal.day;
    mounth = equal.mounth;
    year = equal.year;
    return *this;
}
