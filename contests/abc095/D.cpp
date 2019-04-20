#include <iostream>
#include <vector>

int main() {
  int N, C;
  std::cin >> N >> C;

  std::vector<long long int> xs(N), vs(N);

  for(int i = 0; i < N; i++) {
    std::cin >> xs[i] >> vs[i];
  }

  std::vector<long long int> rv(N), lv(N);

  for (int i = 1; i < N; i++) {
    rv[i] = rv[i-1] + vs[i-1];
    lv[i] = lv[i-1] + vs[N-i];
  }

  long long int answer = 0;

  for(int i = 1; i < N; i++) {
    answer = std::max(answer, rv[i] - xs[i]);
    answer = std::max(answer, lv[i] - xs[i]);

    std::cout << "R(" << i << ") : " << rv[i] - xs[i-1] << std::endl;
    std::cout << "L("  << i << ") : " << lv[i] - xs[i-1] << std::endl;

    for (int j = 1; i + j < N; j++) {
      answer = std::max(answer, rv[i] + lv[j] - xs[i] * 2 - (N - xs[N - j]));
      answer = std::max(answer, lv[i] + rv[j] - xs[i] - (N - xs[N - j]) * 2);

      std::cout << "R(" << i << "), L(" << j << ") : " << rv[i] + lv[j] - xs[i-1] * 2 - (N - xs[N - j]) << std::endl;
      std::cout << "R(" << j << "), L(" << i << ") : " << lv[i] + rv[j] - xs[i-1] - (N - xs[N - j]) * 2 << std::endl;
    }
  }

  std::cout << answer << std::endl;
}
