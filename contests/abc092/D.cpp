#include <iostream>
#include <vector>
#include <string>

const int K = 50;
const char BLACK = '#';
const char WHITE = '.';

int main() {
  int A, B;
  std::cin >> A >> B;

  std::vector<std::string> m;

  for (int i = 0; i < 2 * K; i++) {
    m.push_back(std::string(2 * K, i < K ? BLACK : WHITE));
  }

  for (int i = 0; i < A - 1; i++) {
    const int y = 2 * (i / (K / 2));
    const int x = 2 * (i % (K / 2));

    m[y][x] = WHITE;
  }

  for (int i = 0; i < B - 1; i++) {
    const int y = 2 * K - 1 - 2 * (i / (K / 2));
    const int x = 2 * (i % (K / 2));

    m[y][x] = BLACK;
  }

  std::cout << 2 * K << " " << 2 * K << std::endl;

  for (int y = 0; y < 2 * K; y++) {
    std::cout << m[y] << std::endl;
  }
}
