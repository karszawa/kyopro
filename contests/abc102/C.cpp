#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
  long long int N;
  std::cin >> N;

  std::vector<long long int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
    A[i] -= i + 1;
  }

  std::sort(A.begin(), A.end());

  long long int answer = 0, mid = A[N / 2];

  for (int j = 0; j < N; j++) {
    answer += std::abs(A[j] - mid);
  }

  std::cout << answer << std::endl;
}
