#include <iostream>
#include <cmath>

int main() {
  long long int X, Y;
  std::cin >> X >> Y;

  int answer = 0;

  for (long long int x = X; x <= Y; x *= 2) {
    answer++;
  }

  std::cout << answer << std::endl;
}
