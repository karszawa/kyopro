#include <iostream>

int main() {
  long long int N, M;
  std::cin >> N >> M;

  if (N > M) {
    std::swap(N, M);
  }

  if (N == 1) {
    if (M == 1) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << M - 2 << std::endl;
    }
  } else {
    std::cout << (N - 2) * (M - 2) << std::endl;
  }
}
