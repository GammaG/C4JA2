
#include "mydate.h"
#include <iostream>


using namespace MyDate;

/**
 * Wert des Tages wird zurückgegeben.
 * @brief MyDate::Days::value
 * @return
 */
unsigned int Days::value() const {
    return m_day;
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

/**
* Gibt zurück ob ein übergebenes Jahr ein Schaltjahr ist.
*/
bool MyDate::Date::isLeapYear(Years y){
    return (y%4) == 0;

}

/**
* Gibt die Anzahl der Tage von einem übergebenen Monat zurück
*/
MyDate::Days MyDate::Date::daysInMonth(Months m, Years y){
    switch(m){
    case 2: if(isLeapYear(y)){
            return Days(29); break;
            }
            else {
            return Days(28); break;
            }
    case 4: return Days(30); break;
    case 6: return Days(30); break;
    case 9: return Days(30); break;
    case 11: return Days(30); break;
    default: return Days(31); break;

    }

}


MyDate::Date* MyDate::Date::operator+= (const Days& lhs){
   unsigned int temp = this->days.value();
   temp += lhs.value();

   if(daysInMonth(this->months,this->years).value()<temp){
      temp -= daysInMonth(this->months,this->years).value();
      unsigned int month = this->months.value();
      month++;
      if(month > 12){
          unsigned int year = this->years.value();
          year++;
          month = 1;
            this->years.setYears(year);
      }

      this->months.setMonths(month);
   }

   this->days.setDays(temp);
    return this;

}


MyDate::Date* MyDate::Date::operator+= (const Months& lhs){
   unsigned int month = this->months.value();
   month += lhs.value();

   if(month > 12){
       month = 1;
       unsigned int year = this->years.value();
       year++;

       this->years.setYears(year);

   }


   this->months.setMonths(month);

   //hier wird die Anzahl der Tage auf der Max des aktuellen Monates gesetzt.
   if(daysInMonth(this->months,this->years).value() < this->days.value()){

       this->days.setDays(daysInMonth(this->months,this->years).value());

   }

   return this;


}


MyDate::Date* MyDate::Date::operator+= (const Years& lhs){
   unsigned int temp = this->years.value();
   temp += lhs.value();

   this->years.setYears(temp);


}



MyDate::Date* MyDate::Date::operator+= (const unsigned int& lhs){
   return this;

}


