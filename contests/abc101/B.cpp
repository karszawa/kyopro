#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int s = 0;

  for (int n = N; n > 0; n /= 10) {
    s += n % 10;
  }

  std::cout << (N % s == 0 ? "Yes" : "No") << std::endl;
}
