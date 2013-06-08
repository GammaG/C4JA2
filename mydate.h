#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>



namespace MyDate  {


class Days{
     int m_day;
public:

    Days( int i = 0) :m_day(i){ }

    int value() const;

    operator  int() const;

    void setDays( int days){
        this->m_day = days;
    }

    friend bool operator== (const int& i,const Days& rhs){

        return i == rhs.value();

        }
};


class Months{
     int m_month;
public:
    Months( int i = 0) :m_month(i){ }
     int value() const;

    operator  int() const;


    void setMonths( int months){
        this->m_month = months;
    }

    friend bool operator== (const  int& i,const Months& lhs){

    return i == lhs.value();

    }

};

class Years {
     int m_year;
public:
    Years( int i = 0) :m_year(i){ }
     int value() const;

    operator  int() const;


    void setYears( int years){
        this->m_year = years;
    }


    friend bool operator== (const  int& i,const Years& lhs){

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

    static bool isLeapYear( int y);
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


Date& operator+= (const Days& lhs);

Date& operator+= (const Months& lhs);

Date& operator+= (const Years& lhs);

Date& operator-= (const Days& lhs);

Date& operator-= (const Months& lhs);

Date& operator-= (const Years& lhs);

Date& operator+= (const  int& lhs);

Date& operator-= (const  int& lhs);


Date& operator+ (const Days& lhs)const;

Date& operator+ (const Months& lhs)const;

Date& operator+ (const Years& lhs)const;

Date& operator- (const Days& lhs)const;

Date& operator- (const Months& lhs)const;

Date& operator- (const Years& lhs)const;

bool operator<(const Date& rhs);

std::string& toString();

};

}


std::ostream& operator<<(std::ostream &lhs,const MyDate::Date &rhs);



#endif // MYDATE_H
