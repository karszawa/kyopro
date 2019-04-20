#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;

  std::cout << (A + B == 15 ? '+' : (A * B == 15 ? '*' : 'x')) << std::endl;
}
