#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int pt = 0, px = 0, py = 0;
  bool yes = true;

  for (int i = 0; i < N; i++) {
    int t, x, y;
    std::cin >> t >> x >> y;

    const int d = std::abs(x - px) + std::abs(y - py);
    const int td = t - pt;

    if (d <= td && d % 2 == td % 2) {
      // nop
    } else {
      yes = false;
    }

    pt = t, px = x, py = y;
  }

  std::cout << (yes ? "Yes" : "No") << std::endl;
}
