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
    static bool isLeapYear(Years y);
    static Days daysInMonth(Months m, Years y);

    /**
     * Gibt zurück ob die zwei Datums identisch sind
     */
    friend bool operator== (const Date& lhs,const Date& rhs){

        if(lhs.days.value() == rhs.days.value()
           && lhs.months.value() == rhs.months.value()
           && lhs.years.value() == rhs.years.value()){
            return true;
        }
    return false;

    }

    /**
      * Gibt zurück ob die beiden Datums sich unterscheiden
      */
    friend bool operator!= (const Date& lhs,const Date& rhs){

        if(lhs.days.value() != rhs.days.value()
           || lhs.months.value() != rhs.months.value()
           || lhs.years.value() != rhs.years.value()){
            return true;
        }
    return false;

    }

    /**
    * Gibt zurück ob das erste datum kleiner ist als das Zweite.
    */
    friend bool operator< (const Date& lhs,const Date& rhs){

        if(lhs.years.value()<rhs.years.value()){
            return true;
        } else if(lhs.months.value()<rhs.months.value()){
            return true;
        } else if(lhs.days.value()<rhs.days.value()){
            return true;
        }


    return false;

    }


    friend Date& operator+= (const Days& lhs){
       unsigned int temp = this->days.value();
       temp += lhs.value();
       free(this->days);
       if(daysInMonth(this->months,this->years).value()<temp){
          temp -= daysInMonth(this->months,this->years).value();
          unsigned int month = this->months.value();
          month++;
          if(month > 12){
              month = 1;
              unsigned int year = this->years.value();
              year++;
              free(this->years);
              this->Years(year);
          }
          free(this->months);
          this->Months(month);

       }

       this->Days(temp);
        return this;

    }

    friend Date& operator+= (const Months& lhs){
       unsigned int temp = this->months.value();
       temp += lhs.value();
       free(this->months);

       if(month > 12){
           month = 1;
           unsigned int year = this->years.value();
           year++;
           free(this->years);
           this->Years(year);
       }
       free(this->months);

       this->Months(temp);

       //hier wird die Anzahl der Tage auf der Max des aktuellen Monates gesetzt.
       if(daysInMonth(this->months,this->years).value() < this->days.value()){
           free(this->days);
           this->Days(daysInMonth(this->months,this->years).value());

       }

       return this;


    }


    friend Date& operator+= (const Years& lhs){
       unsigned int temp = this->years.value();
       temp += lhs.value();
       free(this->years);

       this->Years(temp);


    }

    friend Date& operator+= (unsigned int& lhs){
       return this;

    }


};

}

/**
std::ostream& operator<<(std::ostream &lhs,const MyDate::Date &rhs){
    lhs << rhs.day().value() << "." << rhs.month().value() << "." << rhs.year().value();
    return lhs;
}
*/

#endif // MYDATE_H
