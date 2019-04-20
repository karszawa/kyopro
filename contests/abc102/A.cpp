#include <iostream>

int main() {
  int N;
  std::cin >> N;

  std::cout << (N % 2 == 0 ? N : N * 2) << std::endl;
}
