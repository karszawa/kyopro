#include <iostream>
#include <string>

int main() {
  std::string S;
  int W;

  std::cin >> S >> W;

  for (int i = 0; i < S.size(); i += W) {
    std::cout << S[i];
  }

  std::cout << std::endl;
}
