#include <iostream>
#include <vector>

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
};

std::istream &operator>>(std::istream &is, Point &point) {
  is >> point.x >> point.y;

  return is;
}

int main() {
  int N;
  std::cin >> N;

  std::vector<Point> r(N), b(N);

  for (int i = 0; i < N; i++) {
    std::cin >> r[i];
  }

  for (int i = 0; i < N; i++) {
    std::cin >> b[i];
  }

  sort(b.begin(), b.end(), [](const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });

  sort(r.begin(), r.end(), [](const Point& a, const Point& b) {
    return a.y > b.y || (a.y == b.y && a.x > b.x);
  });

  std::vector<bool> used(N, false);
  int answer = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (b[i].x > r[j].x && b[i].y > r[j].y && !used[j]) {
        used[j] = true;
        answer++;
        break;
      }
    }
  }

  std::cout << answer << std::endl;
}
