#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() {
  int N;

  std::cin >> N;

  std::set<std::string> s;
  bool ok = true;
  std::string prev = "";

  for (int i = 0; i < N; i++) {
    std::string W;
    std::cin >> W;

    if (s.find(W) != s.end()) {
      ok = false;
    } else if (i != 0 && W[0] != prev[prev.size() - 1]) {
      ok = false;
    } else {
      prev = W;
      s.insert(W);
    }
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;
}
