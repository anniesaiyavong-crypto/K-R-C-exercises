static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day) {
  int leap;
  char *p;
  // error checking
  if (year < 1 || month < 1 || month > 12 || day < 1)
    return -1;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  // point to the first address of leap row
  p = daytab[leap];
  // when day value exceed its month
  if (day > *(p + month))
    return -1;

  p++;

  // calculate day
  while (--month > 0)
    day += *p++;

  return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *month_ptr, int *day_ptr) {
  int leap;
  char *p;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  // check for valid yearday
  int max_days = leap ? 366 : 365;
  if (yearday > max_days) {
    *month_ptr = -1;
    *day_ptr = -1;
    return;
  }
  // // point to the second address of leap row
  p = daytab[leap] + 1;

  while (yearday > *p)
    yearday -= *p++;

  *month_ptr = p - daytab[leap];
  *day_ptr = yearday;
}
