#include <iostream>
#include <vector>
#include <string>

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> S(H);

  for (int i = 0; i < H; i++) {
    std::cin >> S[i];
  }

  bool ng = false;

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '.') {
        continue;
      }

      bool ok = false;

      for (int i = 0; i < 4; i++) {
        const int ny = y + dy[i];
        const int nx = x + dx[i];

        if (ny >= 0 && ny < H && nx >= 0 && nx < W && S[ny][nx] == '#') {
          ok = true;
          break;
        }
      }

      if (!ok) {
        ng = true;
        goto end;
      }
    }
  }

end:
  std::cout << (ng ? "No" : "Yes") << std::endl;
}
