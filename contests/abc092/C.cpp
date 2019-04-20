#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  int planned_price = 0;

  for (int i = 0; i <= N; i++) {
    planned_price += std::abs(((i == N ? 0 : A[i]) - (i == 0 ? 0 : A[i-1])));
  }

  for (int i = 0; i < N; i++) {
    const int prev = (i == 0 ? 0 : A[i-1]);
    const int crnt = (i + 1 == N ? 0 : A[i+1]);

    std::cout << planned_price - std::abs(A[i] - prev) - std::abs(crnt - A[i]) + std::abs(crnt - prev) << std::endl;
  }
}
