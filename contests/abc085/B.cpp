#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> D(N);
  for (int i = 0; i < N; i++) {
    std::cin >> D[i];
  }

  std::sort(D.begin(), D.end());
  std::cout << std::unique(D.begin(), D.end()) - D.begin() << std::endl;
}
