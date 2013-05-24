/**
 *
 *  C++ für Java-Programmierer
 *  Testtreiber zur Aufgabe 2, "MyDate"
 *  Autor: Hartmut Schirmacher, http://hschirmacher.beuth-hochschule.de
 *
*/

#include <iostream>
#include <assert.h>
#include "mydate.h"
#include "mydate_map.h"

using namespace std;
using namespace MyDate;

int main()
{
    cout << "Starting Unit Tests for Day, Month, Year, Date..." << endl;

    {
        // Day, Month, Year are just type-safe wrappers for unsigned int
        Days myday;
        assert(myday.value() == 0);

        Months mymonth(12);
        assert(mymonth.value() == 12);

        // have you declared your getters const??? :-)
        const Years CONST_YEAR(2012);
        assert(CONST_YEAR.value() == 2012);

        // test implicit conversion to unsigned int (operator unsigned int())
        assert(0 == myday);
        assert(12 == mymonth);
        assert(2012 == CONST_YEAR);
        Date x(1,1,2012);
        assert(x.daysInMonth(Months(2),Years(2012)).value()==29);
    }


    {
        // static member function Date::daysInMonth()
        int days_feb = Date::daysInMonth(2);
        cout << "February normally has " << days_feb << " days." << endl;
        assert(days_feb == 28);

        int days_feb_2400 = Date::daysInMonth(Months(2),Years(2400));
        cout << "In year 2400, February will have " << days_feb_2400 << " days." << endl;
        assert(days_feb_2400 == 29);
    }

    {
        // Date constructor, getters, and stream output
        Date d1;
        cout << "Date1: " << d1 << endl;
        assert(d1.day() == 0);
        assert(d1.month() == 0);
        assert(d1.year() == 0);
    }

    {
        // comparison of two dates
        Date d2(1, 1, 2013);
        cout << "Date2: " << d2 << endl;
        Date d3(28, 2, 2013);
        cout << "Date3: " << d3 << endl;
        cout << "Date2 == Date3: " << (d2==d3) << endl;
        assert(! (d2 == d3));
        cout << "Date2 != Date3: " << (d2!=d3) << endl;
        assert(d2 != d3);
        cout << "Date2 < Date3: " << (d2<d3) << endl;
        assert(d2<d3);
        cout << "Date3 < Date3: " << (d3<d2) << endl;
        assert(!(d3<d2));
    }

    {
        // static member function Date::isLeapYear()
        cout << "Is 1999 a leap year: " << Date::isLeapYear(1999) << endl;
        assert(!Date::isLeapYear(1999));
        cout << "Is 2000 a leap year: " << Date::isLeapYear(2000) << endl;
        assert(Date::isLeapYear(2000));
        cout << "Is 2100 a leap year: " << Date::isLeapYear(2100) << endl;
        assert(!Date::isLeapYear(2100));
    }

    {
        Date d3(28, 2, 2013);

        // add one day
        d3 += Days(1);
        cout << "Date3 +1d: " << d3 << endl;
        assert(d3 == Date(1,3,2013));

        // add many days (multiple months)
        int manydays = 31+30+31+30+31+31; // March ... August
        d3 += Days(manydays);
        cout << "Date3 +" << manydays << "d: " << d3 << endl;
        assert(d3 == Date(1,9,2013));

        // add more days (so year is changed)
        int evenmoredays = 480;
        d3 += Days(evenmoredays);
        cout << "Date3 +" << evenmoredays << "d: " << d3 << endl;
        assert(d3.year() == 2014);

        // does += return the correct return type and value?
        Date x(1,1,2012);
        Date y = x+=Days(4); // should work!!!
        cout << x << " + 4d = " << y <<endl;
        assert(x == Date(5,1,2012));

    }


    {
        Date d3(1,1,2015);

        // add months
        Months m3 = d3.month();
        d3 += Months(2);
        cout << "Date3 +2m:" << d3 << endl;
        assert(d3.month() == m3+2);

        // add years
        Years y3 = d3.year();
        d3 += Years(20);
        cout << "Date3 +20y:" << d3 << endl;
        assert(d3.year() == y3+20);

        // verifizieren Sie, dass die folgende Zeile NICHT compiliert,
        // und kommentieren Sie sie dann aus
        d3 += 1;
        // er compliert aber ändert nichts am objekt
    }

    {
        // non-mutating addition operators
        const Date dd(31,12,2012);
        Date dd2 = dd + Days(1);
        cout << dd << " + 1 day = " << dd2 << endl;
        assert(dd2 == Date(1,1,2013));

        Date dd3 = dd + Months(4);
        cout << dd << " + 4 months = " << dd3 << endl;
        assert(dd3 == Date(30,4,2013));

        Date dd4 = dd + Years(1000);
        cout << dd << " + 1000 years = " << dd4 << endl;
        assert(dd4 == Date(31,12,3012));

        // mixed units
        Date dd5 = dd + Days(2) + Months(3) + Years(5);
        cout << dd << " + 2d + 3m + 5y = " << dd5 << endl;
        assert(dd5 == Date(2,4,2018));

    }


    {
        cout << "From here on 2.2" << endl;

        Date d1(27,5,2013);
        Date d2(27,6,2013);
        Date d3(6,7,2014);
        Date d4(13,2,2012);
        Date d5(1,1,2000);
        Date d6(13,3,2012);
        Date d7(29,5,2013);

        cout << "The Dates:" << endl;
        cout << d1 << endl;
        cout << d2 << endl;
        cout << d3 << endl;
        cout << d4 << endl;
        cout << d5 << endl;
        cout << d6 << endl;
        cout << d7 << endl;

        Map m;

        m[d1];
        cout << "Should be 1 is: "  << m[d1] << endl;
        m[d2];
        m[d3];
        m[d4];
        m[d5];
        m[d6];
        m[d7];
        cout << "Should be 5 is: "  << m[d5] << endl;

        cout << "Change message of " << d2 << " to 19" << endl;
        m.setMessage(d2,19);
        cout << "Should be 19 is: " << m[d2] << endl;

        cout << "Map clone to const Map begins" << endl;
        const Map mc = m;

        const Date dc1(13,2,2012);
        const Date dc2(25,3,2000);
        cout << "New Dates are:" << endl;
        cout << dc1 << endl;
        cout << dc2 << endl;

        cout << "Should be 4 is: "  << mc[dc1] << endl;
        cout << "Should be not in List" << mc[dc2] << endl;

    }


    cout << "all tests completed." << endl;
    cout << "Cya, I'm done here" << endl;

    return 0;
}

