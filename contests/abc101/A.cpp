#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  int answer = 0;

  for (auto s : S) {
    answer += (s == '+' ? 1 : -1);
  }

  std::cout << answer << std::endl;
}
