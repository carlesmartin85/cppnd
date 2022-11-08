import <iostream>;
import <cassert>;
import mainmodule;
int main() {
  date::Date date(29, 8, 1981);
  assert(date.get_day() == 29);
  assert(date.get_month() == 8);
  assert(date.get_year() == 1981);
}