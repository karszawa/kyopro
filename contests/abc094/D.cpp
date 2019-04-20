#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  sort(A.begin(), A.end());

  for (int i = 0; i < N - 1; i++) {
    if (A[i+1] * 2 > A[A.size() - 1]) {
      std::cout << A[A.size() - 1] << " " << (A[i] >= A[A.size() - 1] - A[i+1] ? A[i] : A[i+1]) << std::endl;
      break;
    }
  }
}
