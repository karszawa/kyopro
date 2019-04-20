#include <iostream>
#include <vector>

std::vector<int> bases = { 6, 9 };

int main() {
  int N;
  std::cin >> N;

  std::vector<int> dp(N + 1, 1 << 28);

  dp[0] = 0;

  for (int i = 0; i <= N; i++) {
    for (auto b : bases) {
      for (int y = 1; i + y <= N; y *= b) {
        dp[i + y] = std::min(dp[i + y], dp[i] + 1);
      }
    }
  }

  std::cout << dp[N] << std::endl;
}
