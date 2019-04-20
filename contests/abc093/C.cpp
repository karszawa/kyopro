#include <iostream>

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;

  int answer = 0;

  while (A != B || B != C || A != C) {
    if (A > B) { std::swap(A, B); }
    if (B > C) { std::swap(B, C); }
    if (A > B) { std::swap(A, B); }

    if (A + 2 <= C) {
      A += 2;
    } else {
      A += 1;
      B += 1;
    }

    answer++;
  }

  std::cout << answer << std::endl;
}
