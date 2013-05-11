#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
#include "mydate.h"



namespace MyDate  {


class Days{
    unsigned int m_day;
public:

    Days(unsigned int i = 0) :m_day(i){ }

    unsigned int value() const;

    operator unsigned int() const;

    friend bool operator== (const unsigned int& i,const Days& rhs){

        return i == rhs.value();

        }
};


class Months{
    unsigned int m_month;
public:
    Months(unsigned int i = 0) :m_month(i){ }
    unsigned int value() const;

    operator unsigned int() const;

    friend bool operator== (const unsigned int& i,const Months& lhs){

    return i == lhs.value();

    }

};

class Years {
    unsigned int m_year;
public:
    Years(unsigned int i = 0) :m_year(i){ }
    unsigned int value() const;

    operator unsigned int() const;

    friend bool operator== (const unsigned int& i,const Years& lhs){

    return i == lhs.value();

    }

};

class Date {
    Days days;
    Months months;
    Years years;
public:
    Date(Days days = 0, Months months = 0, Years years = 0)
        :days(days),
        months(months),
        years(years)
    {}

    Days day() const;
    Months month() const;
    Years year() const;

};

}

/**
std::ostream& operator<<(std::ostream &lhs,const MyDate::Date &rhs){
    lhs << rhs.day().value() << "." << rhs.month().value() << "." << rhs.year().value();
    return lhs;
}
*/

#endif // MYDATE_H
