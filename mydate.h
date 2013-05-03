#ifndef MYDATE_H
#define MYDATE_H



namespace MyDate  {


class Days{
    unsigned int m_day;
public:

    Days(unsigned int i = 0) :m_day(i){ }


    unsigned int value() const {return m_day; }

    friend bool operator== (const unsigned int& i,const Days& lhs){

    return i == lhs.value();

    }


};


class Months{
    unsigned int m_month;
public:
    Months(unsigned int i = 0) :m_month(i){ }
    unsigned int value() const {return m_month; }
    friend bool operator== (const unsigned int& i,const Months& lhs){

    return i == lhs.value();

    }

};

class Years {
    unsigned int m_year;
public:
    Years(unsigned int i = 0) :m_year(i){ }
    unsigned int value() const {return m_year; }
    friend bool operator== (const unsigned int& i,const Years& lhs){

    return i == lhs.value();

    }

};

class Date {
    Days days;
    Months months;
    Years years;
public:
    Date();
    Days day() const {return days;}
    Months month() const { return months; }
    Years year() const { return years; }


};



}



#endif // MYDATE_H
