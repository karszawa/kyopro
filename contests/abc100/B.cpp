#include <iostream>

int main() {
  int D, N;
  std::cin >> D >> N;

  if (D == 0) {
    if (N == 100) {
      std::cout << 101 << std::endl;
    } else {
      std::cout << N << std::endl;
    }
  } else if (D == 1) {
    if (N == 100) {
      std::cout << 10100 << std::endl;
    } else {
      std::cout << N * 100 << std::endl;
    }
  } else {
    if (N == 100) {
      std::cout << 1000100 << std::endl;
    } else {
      std::cout << N * 10000 << std::endl;
    }
  }
}
