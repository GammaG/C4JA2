#include "mydate.h"

/**
 * Wert des Tages wird zurückgegeben.
 * @brief MyDate::Days::value
 * @return
 */
unsigned int MyDate::Days::value() const {
    return MyDate::Days::m_day;
}

/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
unsigned int MyDate::Months::value() const {return m_month; }


/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
unsigned int MyDate::Years::value() const {return m_year; }


/**
 *Gibt den Tag des Datums zurück
  * @brief MyDate::Date::day
  * @return
  */
 MyDate::Days MyDate::Date::day() const {return days;}

 /**
  *Gibt den Monat des Datums zurück
  * @brief MyDate::Date::month
  * @return
  */
 MyDate::Months MyDate::Date::month() const { return months; }


 /** Gibt das Jahr des Datums zurück
 * @brief MyDate::Date::year
 * @return
 */
MyDate::Years MyDate::Date::year() const { return years; }
