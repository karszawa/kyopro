#include <iostream>
#include <map>

int main() {
  int N;
  std::cin >> N;

  std::map<int ,int> m;

  for (int i = 0; i < N; i++) {
    int A;
    std::cin >> A;
    m[A]++;
  }

  int answer = 0;

  for (auto p : m) {
    if (p.second >= p.first) {
      answer += p.second - p.first;
    } else {
      answer += p.second;
    }
  }

  std::cout << answer << std::endl;
}
