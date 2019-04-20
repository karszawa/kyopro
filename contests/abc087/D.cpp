#include <iostream>
#include <vector>

const int MAX_N = 100000;
std::vector<std::pair<int, int>> g[MAX_N];
int visited[MAX_N], cost[MAX_N];

bool dfs(int v) {
  visited[v] = 1;

  for (const auto& e : g[v]) {
    int u = e.first, d = e.second;

    if (visited[u]) {
      if (cost[v] + d != cost[u]) {
        return false;
      }

      continue;
    }

    cost[u] = cost[v] + d;

    if (!dfs(u)) {
      return false;
    }
  }

  return true;
}

int main() {
  int N, M;
  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int L, R, D;
    std::cin >> L >> R >> D;

    g[L-1].emplace_back(R-1, D);
    g[R-1].emplace_back(L-1, -D);
  }

  bool yes = true;

  for (int i = 0; yes && i < N; i++) {
    if (!visited[i] && !dfs(i)) {
      yes = false;
    }
  }

  std::cout << (yes ? "Yes" : "No") << std::endl;
}
