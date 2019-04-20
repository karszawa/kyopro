#include <iostream>
#include <vector>
constexpr int MAX_N = 999;

int main() {
  int A, B;
  std::cin >> A >> B;

  std::vector<int> towers(MAX_N + 1);

  for (int i = 1; i <= MAX_N; i++) {
    towers[i] = towers[i-1] + i;
  }

  for (int i = 1; i <= MAX_N; i++) {
    const int x = towers[i] - A;

    if (x == towers[i + 1] - B) {
      std::cout << x << std::endl;
      break;
    }
  }
}
