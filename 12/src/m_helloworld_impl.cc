export module mainmodule:helloworld;

import <string>;

export namespace date{

class Date {
public:
  Date(int day, int month, int year);
  int get_day() const { return day_; }
  void set_day(int day);
  int get_month() const { return month_; }
  void set_month(int month);
  int get_year() const { return year_; }
  void set_year(int year);

private:
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  set_year(year);
  set_month(month);
  set_day(day);
}

void Date::set_day(int day) {
    int day__;
    if (Date::get_month() >= 8 && Date::get_month() <= 12) {
      if (Date::get_month()%2 == 0)
      {
          day__ = 31;
      } else {
          day__ = 30;
      }
    } else if (Date::get_month() < 8 && Date::get_month() >= 1) {
      if (Date::get_month() == 2) {
          if (Date::get_year()%4 == 0)
          {
              day__ = 29;
          } else {
              day__ = 28;
          }
      }
      else if (Date::get_month()%2 != 0) {
          day__ = 31;
      } else {
          day__ = 30;
      }
    }
    if (day >= 1 && day <= day__)
    {
        day_ = day;
    }
}

void Date::set_month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::set_year(int year) {year_ = year;}

};