static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day) {
  int i, leap;

  // error checking: year
  if (year < 1)
    return -1;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  // error checking: month
  if (month < 1 || month > 12)
    return -1;
  // error checking: day
  if (day < 1 || day > daytab[leap][i])
    return -1;
  // calculate day
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}
// month_day: set month, day from day of year
void month_day(int year, int yearday, int *month_ptr, int *day_ptr) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  // check for valid yearday
  int max_days = leap ? 366 : 365;
  if (yearday > max_days) {
    *month_ptr = -1;
    *day_ptr = -1;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *month_ptr = i;
  *day_ptr = yearday;
}
