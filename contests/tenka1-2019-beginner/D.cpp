#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int MOD = 998244353;
int memo[301][301 * 301 + 1] = {0};

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N, 0);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  const int S = std::accumulate(A.begin(), A.end(), 0);

  std::vector<int> f(N, 0), g(N, 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S; j++) {

    }
  }
}
