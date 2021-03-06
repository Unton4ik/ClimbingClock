/*
   file: RTClib_CRoC.cpp
   auth: anton r

   created:  06/04/2020
   modified: 16/07/2020
*/

#include "RTClib_CRoC.h"

/*
   Determines if one DateTimeWrapper object is less than the other
*/
bool DateTimeWrapper::operator<(const DateTime &other)
{
   return (
      yOff + 2000 < other.year() || (
      yOff + 2000 == other.year() && (
      m < other.month() || (
      m == other.month() && (
      d < other.day() || (
      d == other.day() && (
      hh < other.hour() || (
      hh == other.hour() && (
      mm < other.minute() || (
      mm == other.minute() &&
      ss < other.second() ) ) ) ) ) ) ) ) ) );
}

bool DateTimeWrapper::operator>(const DateTime &other)
{
   return (DateTimeWrapper) other < *this;
}

bool DateTimeWrapper::operator==(const DateTime &other)
{
   return (
      other.year()   == yOff + 2000 &&
      other.month()  == m    &&
      other.day()    == d    &&
      other.hour()   == hh   &&
      other.minute() == mm   &&
      other.second() == ss);
}

bool DateTimeWrapper::operator<=(const DateTime &other)
{
   return (*this < other) || (*this == other);
}

bool DateTimeWrapper::operator>=(const DateTime &other)
{
   return (*this > other) || (*this == other);
}