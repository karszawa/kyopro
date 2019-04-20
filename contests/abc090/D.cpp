#include <iostream>
#include <vector>

int main() {
  long long int N, K;
  std::cin >> N >> K;

  if (K == 0) {
    std::cout << N * N << std::endl;
    return 0;
  }

  long long int answer = 0;

  for (int b = K+1; b <= N; b++) {
    const int p = N / b;
    const int r = N % b;

    answer += p * std::max(0LL, b - K);
    answer += std::max(0LL, r - K + 1);
  }

  std::cout << answer << std::endl;
}
