#include <iostream>
#include <cmath>

int main() {
  int A, B, C, K;
  std::cin >> A >> B >> C >> K;

  int m = std::max(A, std::max(B, C));

  std::cout << A + B + C + 2 * std::pow(2, K-1) * m - m << std::endl;
}
