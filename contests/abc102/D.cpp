#include <iostream>
#include <vector>

long long int N, cs[200010];

bool check(int l, int m, int r) {
  if (l >= m || m >= r) return true;
  long long int curr = std::abs((cs[r] - cs[m]) - (cs[m] - cs[l]));
  long long int next = std::abs((cs[r] - cs[m + 1]) - (cs[m + 1] - cs[l]));
  return curr > next;
}

long long int maximum(int l, int m, int r) {
  long long int p1 = cs[l], p2 = cs[m] - cs[l], p3 = cs[r] - cs[m], p4 = cs[N] - cs[r];
  return std::max(p1, std::max(p2, std::max(p3, p4)));
}

long long int minimum(int l, int m, int r) {
  long long int p1 = cs[l], p2 = cs[m] - cs[l], p3 = cs[r] - cs[m], p4 = cs[N] - cs[r];
  return std::min(p1, std::min(p2, std::min(p3, p4)));
}

int main() {
  std::cin >> N;
  std::vector<int> A(N+1);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i+1];
    cs[i+1] = A[i+1] + cs[i];
  }

  long long int answer = 1LL << 60, l = 1, r = 3;

  for (int i = 2; i < N - 1; i++) {
    while (check(0, l, i)) l++;
    while (check(i, r, N)) r++;

    // std::cout << l << " " << i << " " << r << " " << maximum(l, i, r) << " " << minimum(l, i, r) << std::endl;

    answer = std::min(answer, maximum(l, i, r) - minimum(l, i, r));
  }

  std::cout << answer << std::endl;
}
