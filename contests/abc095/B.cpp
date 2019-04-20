#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int N, X;
  std::cin >> N >> X;

  int mn = 1<<30, sm = 0;

  for (int i = 0; i < N; i++) {
    int m;
    std::cin >> m;

    mn = std::min(mn, m);
    sm += m;
  }

  std::cout << N + (X - sm) / mn << std::endl;
}
