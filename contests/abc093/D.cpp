#include <iostream>
#include <unordered_set>

int main() {
  int Q;
  std::cin >> Q;

  for (int i = 0; i < Q; i++) {
    long long int A, B;
    std::cin >> A >> B;

    if (A > B) { std::swap(A, B); }

    std::unordered_set<int> s;
    for (int i = B-1; i >= 1; i--) {
      long long int j = A * B / i;

      while (s.find(j) != s.end() && j >= 1) { j--; }

      if (j >= 1) { s.insert(j); }
    }

    std::cout << s.size() << std::endl;
  }
}
