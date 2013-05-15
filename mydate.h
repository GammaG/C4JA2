#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>



namespace MyDate  {


class Days{
    unsigned int m_day;
public:

    Days(unsigned int i = 0) :m_day(i){ }

    unsigned int value() const;

    operator unsigned int() const;

    void setDays(unsigned int days){
        this->m_day = days;
    }

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


    void setMonths(unsigned int months){
        this->m_month = months;
    }

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


    void setYears(unsigned int years){
        this->m_year = years;
    }


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

    static bool isLeapYear(unsigned int y);
    static Days daysInMonth(Months m = 0, Years y = 0);


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

Date& operator+= (const Days& lhs);

Date& operator+= (const Months& lhs);

Date& operator+= (const Years& lhs);

Date& operator-= (const Days& lhs);

Date& operator-= (const Months& lhs);

Date& operator-= (const Years& lhs);

Date& operator+= (const unsigned int& lhs);

Date& operator-= (const unsigned int& lhs);


Date& operator+ (const Days& lhs)const;

Date& operator+ (const Months& lhs)const;

Date& operator+ (const Years& lhs)const;

Date& operator- (const Days& lhs)const;

Date& operator- (const Months& lhs)const;

Date& operator- (const Years& lhs)const;



};

}


std::ostream& operator<<(std::ostream &lhs,const MyDate::Date &rhs);



#endif // MYDATE_H
