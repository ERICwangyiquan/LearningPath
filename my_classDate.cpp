#include "my_classDate.h"


// 获取某年某月的天数
int GetMonthDay(int year, int month)
{
  static int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int day = days[month];
  if(month == 2 && ((year%4==0 && year%100!=0) || year%400 == 0))
  {
    day += 1;
  }
  return day;
}

  // 全缺省的构造函数
Date::Date(int year, int month, int day)
{
  _year = year;
  _month = month;
  _day = day;
}

//2nd method
// Date::Date(int year, int month, int day)
//   :_year(year)
//   ,_month(month)
//   ,_day(day)
// {}


  // 拷贝构造函数
// d2(d1)
Date::Date(const Date& d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;  
}

  // 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
  return *this;
}

  // destructor
Date::~Date()
{
  ;
  //free those allocated memory
}

  // 日期+=天数
Date& Date::operator+=(int day)
{
  _day += day;
  while(_day > GetMonthDay(_year, _month))
  {
    _day -= GetMonthDay(_year, _month);
    _month++;
    if(_month == 13)
    {
      _month = 1;
    }
  }
  return *this;
}

  // 日期+天数
Date Date::operator+(int day) 
{
  Date temp(*this);
  temp += day;
  return temp;
}

  // 日期-天数
Date Date::operator-(int day) 
{
  Date temp(*this);
  temp -= day;
  return temp;
}

   // 日期-=天数
Date& Date::operator-=(int day)
{
  _day -= day;
  while(_day <= 0)
  {
    _month--;
    if(_month == 0)
    {
      _month = 12;
    }
    _day += GetMonthDay(_year,  _month);
  }
  return *this;
}

  // 前置++
Date& Date::operator++()
{
  _day++;
  if(_day == GetMonthDay(_year, _month))
  {
    _day = 1;
    _month++;
    if(_month == 13)
    {
      _year++;
      _month = 1;
    }
  }
  return *this;
}

  // 后置++
Date Date::operator++(int)
{
  Date temp(*this);
  ++(*this);
  return temp;
}

  // 后置--
Date Date::operator--(int)
{
  Date temp = *this;
  _day--;
  if(_day == 0)
  {
    _month--;
    if(_month == 0)
    {
      _month = 12;
      _year--;
    }
    _day = GetMonthDay(_year, _month);
  }
  return temp;
}

  // 前置--
Date& Date::operator--()
{
  _day--;
  return *this;
}
  // >运算符重载
bool Date::operator>(const Date& d)
{
  if(_year>d._year)
  {
    return true;
  }
  if(_year==d._year && _month>d._month)
  {
    return true;
  }
  if(_year==d._year && _month==d._month && _day>d._day)
  {
    return true;
  }
  else
  {
    return false;
  }
}

  // ==运算符重载
bool Date::operator==(const Date& d)
{
  return _year==d._year && _month==d._month && _day==d._day;
}

  // >=运算符重载
inline bool Date::operator>=(const Date& d)
{
  return *this>d || *this==d;
}
   
  // <运算符重载
bool Date::operator < (const Date& d)
{
  return !(*this>=d);
}

   // <=运算符重载
bool Date::operator<=(const Date& d)
{
  return !(*this>d);
}

  // !=运算符重载
bool Date::operator!=(const Date& d)
{
  return !(*this==d);
}

  // 日期-日期 返回天数
int Date::operator-(const Date& d)
{
  int flag = 0;
  Date max = *this;
  Date min = d;
  if(*this < d)
  {
    max = d;
    min = *this;
    flag = -1;
  }
  int day = 0;
  while(min<max)
  {
    ++min;
    ++day;
  }
  return day * flag;
}
