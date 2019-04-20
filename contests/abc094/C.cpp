#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> X(N);

  for (int i = 0; i < N; i++) {
    std::cin >> X[i];
  }

  std::vector<int> sorted(X);
  sort(sorted.begin(), sorted.end());

  int l = sorted[X.size() / 2 - 1], h = sorted[X.size() / 2];

  for (int i = 0; i < N; i++) {
    if (X[i] <= l) {
      std::cout << h << std::endl;
    } else {
      std::cout << l << std::endl;
    }
  }
}
