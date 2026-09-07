#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
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
// canonrect: canonicalize coordiantes of rectangle
struct rect canonrect(struct rect r) {
  struct rect temp;

  temp.p1.x = min(r.p1.x, r.p2.x);
  temp.p2.x = min(r.p1.x, r.p2.x);
  temp.p1.y = min(r.p1.x, r.p2.x);
  temp.p2.y = min(r.p1.x, r.p2.x);
}
