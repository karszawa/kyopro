#include <iostream>
#include <vector>
#include <string>
#include <queue>

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> S(H);

  for (int i = 0; i < H; i++) {
    std::cin >> S[i];
  }

  std::vector<std::vector<int>> costs(H, std::vector<int>(W, 1 << 30));
  std::queue<std::pair<int, int>> que;

  costs[0][0] = 0;

  for (que.push(std::make_pair(0, 0)); !que.empty(); que.pop()) {
    int x = que.front().first, y = que.front().second;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (nx >= 0 && nx < W && ny >= 0 && ny < H && S[ny][nx] == '.') {
        if (costs[ny][nx] > costs[y][x] + 1) {
          costs[ny][nx] = costs[y][x] + 1;
          que.push(std::make_pair(nx, ny));
        }
      }
    }
  }

  if (costs[H-1][W-1] == (1 << 30)) {
    std::cout << -1 << std::endl;
  } else {
    int dots = 0;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        dots += (S[i][j] == '.' ? 1 : 0);
      }
    }

    std::cout << dots - costs[H-1][W-1] - 1 << std::endl;
  }
}
