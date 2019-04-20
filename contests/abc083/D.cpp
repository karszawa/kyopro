#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  int t = S.size(), N = S.size();

  for (int i = 1; i < N; i++) {
    if (S[i] != S[i-1]) {
      t = std::min(t, std::max(i, N - i));
    }
  }

  std::cout << t << std::endl;
}
