#include <iostream>
#include <vector>
#include <numeric>

int gcd(unsigned a, unsigned b) {
  while(1) {
    if(a < b) std::swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main() {
  int N, X;

  std::cin >> N >> X;

  std::vector<int> x(N);

  for (int i = 0; i < N; i++) {
    std::cin >> x[i];
  }

  int answer = std::abs(x[0] - X);

  for (int i = 1; i < N; i++) {
    answer = gcd(answer, std::abs(x[i] - X));
  }

  std::cout << answer << std::endl;
}
