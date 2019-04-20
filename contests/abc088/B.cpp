#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  sort(A.begin(), A.end(), std::greater<int>());

  int answer = 0;

  for (int i = 0; i < A.size(); i++) {
    answer += (i % 2 == 0 ? 1 : -1) * A[i];
  }

  std::cout << answer << std::endl;
}
