#include <iostream>
#include <vector>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::vector<int>> A(H, std::vector<int>(W));
  std::vector<std::pair<int, int>> answer;

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      std::cin >> A[y][x];
    }
  }

  int x = 0, y = 0;
  while (true) {
    int ny = (y % 2 == 0 ? y + (x + 1 == W) : y + (x == 0));
    int nx = (y % 2 == 0 ? (x + 1 == W ? x : x + 1) : (x == 0 ? x : x - 1));

    if (ny >= H) {
      break;
    }

    if (A[y][x] % 2 == 1) {
      A[ny][nx] += 1;

      answer.push_back(std::make_pair(y, x));
    }

    x = nx;
    y = ny;
  }

  std::cout << answer.size() << std::endl;

  for (int i = 0; i < answer.size(); i++) {
    int y = answer[i].first;
    int x = answer[i].second;
    int ny = (y % 2 == 0 ? y + (x + 1 == W) : y + (x == 0));
    int nx = (y % 2 == 0 ? (x + 1 == W ? x : x + 1) : (x == 0 ? x : x - 1));

    std::cout << y + 1 << " " << x + 1 << " " << ny + 1 << " " << nx + 1 << std::endl;
  }
}
