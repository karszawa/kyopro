#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int bits = 0;

  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;

    bits += __builtin_popcount((a & (-a)) - 1);
  }

  std::cout << bits << std::endl;
}
