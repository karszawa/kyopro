#include <iostream>

long long int S(long long int N) {
  int s = 0;

  for (long long int n = N; n > 0; n /= 10) {
    s += n % 10;
  }

  return s;
}

int main() {
  long long int K;
  std::cin >> K;

  long long int s = 1, d = 1;

  for (int i = 0; i < K; i++) {
    std::cout << s << std::endl;

    while (1.0 * (s + d) / S(s + d) > 1.0 * (s + 2 * d) / S(s + 2 * d)) {
      d *= 10;
    }

    s += d;
  }
}
