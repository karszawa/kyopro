#include <iostream>
#include <vector>

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::cout << (N - 1 + K - 2) / (K - 1) << std::endl;
}
