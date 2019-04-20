#include <iostream>
#include <vector>

constexpr int G = 3;

struct Grid {
  int x, y, c;
  Grid(int x, int y, int c) : x(x), y(y), c(c) {}
};

int main() {
  int N, C;
  std::cin >> N >> C;

  std::vector<std::vector<int>> D(C, std::vector<int>(C, 0));

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> D[i][j];
    }
  }

  std::vector<std::vector<int>> c(N, std::vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> c[i][j];
      c[i][j]--;
    }
  }

  std::vector<std::vector<int>> d(G, std::vector<int>(C));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int color = 0; color < C; color++) {
        d[(i + j) % G][color] += D[c[i][j]][color];
      }
    }
  }

  int answer = 1 << 30;

  for (int x = 0; x < C; x++) {
    for (int y = 0; y < C; y++) {
      for (int z = 0; z < C; z++) {
        if (x != y && y != z && z != x) {
          answer = std::min(answer, d[0][x] + d[1][y] + d[2][z]);
        }
      }
    }
  }

  std::cout << answer << std::endl;
}
