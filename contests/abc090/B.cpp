#include <iostream>
#include <string>
#include <sstream>

std::string to_string(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

bool palindrome(std::string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  int A, B;
  std::cin >> A >> B;

  int answer = 0;

  for (int i = A; i <= B; i++) {
    if (palindrome(to_string(i))) {
      answer++;
    }
  }

  std::cout << answer << std::endl;
}
