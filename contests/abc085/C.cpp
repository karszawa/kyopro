#include <iostream>

int main() {
  int N, Y;
  std::cin >> N >> Y;

  if ([&] {
    for (int i = 0; i * 10000 <= Y && i <= N; i++) {
      for (int j = 0; i * 10000 + j * 5000 <= Y && i + j <= N; j++) {
        for (int k = 0; i * 10000 + j * 5000 + k * 1000 <= Y && i + j + k <= N; k++) {
          if (i * 10000 + j * 5000 + k * 1000 == Y && i + j + k == N) {
            std::cout << i << " " << j << " " << k << std::endl;
            return false;
          }
        }
      }
    }

    return true;
  }()) {
    std::cout << "-1 -1 -1" << std::endl;
  }
}
