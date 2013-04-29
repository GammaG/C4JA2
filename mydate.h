#ifndef MYDATE_H
#define MYDATE_H


namespace MyDate  {


class Days{
    unsigned int m_day = 0;
public:
    Days();
    unsigned int value() const {return m_day; }
};


class Months{
    unsigned int m_month = 0;
public:
    Months();
    unsigned int value() const {return m_month; }

};

class Years {
    unsigned int m_year = 0;
public:
    Years();
    unsigned int value() const {return m_year; }

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
