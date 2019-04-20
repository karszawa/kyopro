#include <iostream>
#include <vector>

std::vector<int> r(100);

void rec(const int N, const int M, const int D, int curr, int prev, int cost) {
  if (curr == M) {
    if (cost != 4) {
      return;
    }
    std::cout << cost << ": ";

    for (int i = 0; i < M; i++) {
      std::cout << r[i] << (i + 1 == M ? "\n" : ", ");
    }
  } else {
    for (int i = 1; i <= N; i++) {
      r[curr] = i;
      rec(N, M, D, curr + 1, i, cost + (std::abs(prev - i) == D ? 1 : 0));
    }
  }
}

int main() {
  int N, M, D;
  std::cin >> N >> M >> D;

  double answer = 1.0 * (D == 0 ? N : (N - D) * 2) / N / N * (M - 1);

  printf("%.10f\n", answer);
}
