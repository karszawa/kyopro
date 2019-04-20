#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> f(N, 0), s(N, 0);

  for (int i = 0; i < N; i++) {
    int a;
    std::cin >> a;

    f[i] = a + (i == 0 ? 0 : f[i-1]);
  }

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  for (int i = N-1; i >= 0; i--) {
    s[i] = A[i] + (i == N-1 ? 0 : s[i+1]);
  }

  int answer = 0;

  for (int i = 0; i < N; i++) {
    answer = std::max(answer, f[i] + s[i]);
  }

  std::cout << answer << std::endl;
}
