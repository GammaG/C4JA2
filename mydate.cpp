#include "mydate.h"
#include <iostream>


using namespace MyDate;

/**
 * Wert des Tages wird zurückgegeben.
 * @brief MyDate::Days::value
 * @return
 */
unsigned int Days::value() const {
    return Days::m_day;
}

/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
unsigned int Months::value() const {return m_month; }


/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
unsigned int Years::value() const {return m_year; }


/**
 *Gibt den Tag des Datums zurück
  * @brief MyDate::Date::day
  * @return
  */
 Days Date::day() const {return days;}

 /**
  *Gibt den Monat des Datums zurück
  * @brief MyDate::Date::month
  * @return
  */
 Months Date::month() const { return months; }


 /** Gibt das Jahr des Datums zurück
 * @brief MyDate::Date::year
 * @return
 */
Years Date::year() const { return years; }


Days::operator unsigned int() const{
    return value();
}

Months::operator unsigned int() const{
    return value();
}


Years::operator unsigned int() const{
    return value();

}






