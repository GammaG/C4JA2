
#include "mydate.h"
#include <iostream>


using namespace MyDate;

/**
 * Wert des Tages wird zurückgegeben.
 * @brief MyDate::Days::value
 * @return
 */
 int Days::value() const {
    return m_day;
}

/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
 int Months::value() const {return m_month; }


/**
 *Gibt den Monat zurück
 * @brief value
 * @return
 */
 int Years::value() const {return m_year; }


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


Days::operator  int() const{
    return value();
}

Months::operator  int() const{
    return value();
}


Years::operator  int() const{
    return value();

}

/**
* Gibt zurück ob ein übergebenes Jahr ein Schaltjahr ist.
*/
bool MyDate::Date::isLeapYear( int y){
if(y%4==0){
         if(y%100==0){
                if(y%400==0){
                        return true;
                }
                else{
                        return false;
                    }
        }
        else{
            return true;
        }
       }

    return false;

}

/**
 * Gibt die Anzahl der Tage von einem übergebenen Monat zurück
 * @brief MyDate::Date::daysInMonth
 * @param m
 * @param y
 * @return
 */
MyDate::Days MyDate::Date::daysInMonth(Months m, Years y){
    switch(m){
    case 2: if(isLeapYear(y)&& y != 0){
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

/**
*  Methode addiert die gegebenen Tage auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator+= (const Days& lhs){
    int temp = this->days.value();
   temp += lhs.value();

   while(daysInMonth(this->months,this->years).value()<temp){
      temp -= daysInMonth(this->months,this->years).value();
       int month = this->months.value();
      month++;
      if(month > 12){
           int year = this->years.value();
          year++;
          month = 1;
            this->years.setYears(year);
      }

      this->months.setMonths(month);
   }

   this->days.setDays(temp);
    return *this;

}

/**
* Methode addiert einen Monat auf das Datum, zählt wenn notwendig das Jahr hoch
* & setzt die Tage auf das Maximum des aktuellen Monates
*/
MyDate::Date& MyDate::Date::operator+= (const Months& lhs){
    int month = this->months.value();
   month += lhs.value();

   while(month > 12){
       month -= 12;
       this->years.setYears(this->years+1);

   }


   this->months.setMonths(month);

   //hier wird die Anzahl der Tage auf der Max des aktuellen Monates gesetzt.
   if(daysInMonth(this->months,this->years).value() < this->days.value()){

       this->days.setDays(daysInMonth(this->months,this->years).value());

   }

   return *this;


}


/**
* Addiert gegebene Jahre auf das Datum
*/
MyDate::Date& MyDate::Date::operator+= (const Years& lhs){
    int temp = this->years.value();
   temp += lhs.value();

   this->years.setYears(temp);

return *this;
}


/**
* Fehlerbehandlung wenn kein spezieller Typ übergeben wird, gibt das unveränderte Datum zurück
*/
MyDate::Date& MyDate::Date::operator+= (const int& lhs){
   return *this;

}


/**
*  Methode subtrahiert die gegebenen Tage von dem Datum,
*  zählt wenn notwendig Jahr & Monat runter
*/
MyDate::Date& MyDate::Date::operator-= (const Days& lhs){
    int temp = this->days.value();
   temp -= lhs.value();

   while(temp<1){

       int month = this->months.value();
      month--;
      if(month < 1){
           int year = this->years.value();
          year--;
          month = 12;
            this->years.setYears(year);
      }

      this->months.setMonths(month);
      temp = daysInMonth(this->months,this->years).value() - temp;
   }

   this->days.setDays(temp);
   return *this;

}

/**
* Methode subtrahiert einen Monat von dem Datum, zählt wenn notwendig das Jahr runter
* & setzt die Tage auf das Maximum des aktuellen Monates
*/
MyDate::Date& MyDate::Date::operator-= (const Months& lhs){
    int month = this->months.value();
   month -= lhs.value();


   while(month > 12){
       month -= 12;
       this->years.setYears(this->years-1);

   }


   this->months.setMonths(month);

   //hier wird die Anzahl der Tage auf der Max des aktuellen Monates gesetzt.
   if(daysInMonth(this->months,this->years).value() < this->days.value()){

       this->days.setDays(daysInMonth(this->months,this->years).value());

   }

   return *this;


}


/**
* Subtrahiert gegebene Jahre von dem Datum
*/
MyDate::Date& MyDate::Date::operator-= (const Years& lhs){
    int temp = this->years.value();
   temp -= lhs.value();

   this->years.setYears(temp);

return *this;
}



/**
* Fehlerbehandlung wenn kein spezieller Typ übergeben wird, gibt das unveränderte Datum zurück
*/
MyDate::Date& MyDate::Date::operator-= (const int& lhs){
   return *this;

}


std::ostream& operator<<(std::ostream &lhs,const MyDate::Date &rhs){
    lhs << rhs.day().value() << "." << rhs.month().value() << "." << rhs.year().value();
    return lhs;
}


/**
*  Methode addiert die gegebenen Tage auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator+ (const Days& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs += rhs;
    return lhs;
}

/**
*  Methode dividiert die gegebenen Tage auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator- (const Days& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs -= rhs;
    return lhs;
}

/**
*  Methode addiert die gegebenen Monate auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator+ (const Months& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs += rhs;
    return lhs;
}

/**
*  Methode dividiert die gegebenen Monate auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator- (const Months& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs -= rhs;
    return lhs;
}


/**
*  Methode addiert die gegebenen Jahre auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator+ (const Years& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs += rhs;
    return lhs;
}

/**
*  Methode dividiert die gegebenen Jahre auf das Datum, zählt wenn notwendig Jahr & Monat hoch
*/
MyDate::Date& MyDate::Date::operator- (const Years& rhs)const{

    MyDate::Date lhs(this->day(),this->month(),this->year());
    lhs -= rhs;
    return lhs;
}

std::string& MyDate::Date::toString(){
    std::string temp = "";
    temp += this->days;
    temp += ".";
    temp += this->months;
    temp += ".";
    temp += this->years;

    return temp;
}

/**
 * Gibt zurück ob das übergebene Datum größer als das aktuelle ist.
 * @brief operator <
 * @param rhs
 * @return
 */
bool MyDate::Date::operator<(const MyDate::Date& rhs){
    if(this->years<rhs.years){
        return true;
    } else if(this->months<rhs.months){
        return true;
    } else if(this->days<rhs.days){
        return true;
    }
    return false;
}
