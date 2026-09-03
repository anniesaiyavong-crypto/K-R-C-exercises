char *month_name(int n) {
  static char *name[] = {"Illegal month", "Jan",  "Feb",  "Mar", "Apr",
                         "May",           "June", "July", "Aug", "Sep",
                         "Oct",           "Nov",  "Dec"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}
