// coordinate point
struct point {
  int x;
  int y;
};
// rectangle point
struct rect {
  struct point p1;
  struct point p2;
};
// assign value to point
struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;

  return temp;
}
struct point addpoint(struct point p1, struct point p2) {
  p1.x += p2.x;
  p1.y += p2.y;

  return p1;
}

struct rect screen;
struct point middle;
struct point makepoint(int, int);

int main() {
  screen.p1 = makepoint(7, 9);
  screen.p2 = makepoint(10, 15);

  middle = makepoint((screen.p1.x + screen.p2.x) / 2,
                     (screen.p1.y + screen.p2.y) / 2);
}
