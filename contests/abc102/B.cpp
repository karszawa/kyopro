#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int mx = 0, mn = 1 << 30;

  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;

    mx = std::max(mx, a);
    mn = std::min(mn, a);
  }

  std::cout << mx - mn << std::endl;
}
