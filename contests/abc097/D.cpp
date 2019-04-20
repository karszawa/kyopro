#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct UnionFind {
  vector<int> data;

  UnionFind(int N) : data(N, -1) { }

  bool unite(int x, int y) {
    x = root(x); y = root(y);

    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }

    return x != y;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> ps(N);

  for (int i = 0; i < N; i++) {
    cin >> ps[i];
  }

  UnionFind tree(N);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    tree.unite(x - 1, y - 1);
  }

  int answer = 0;

  for (int i = 0; i < N; i++) {
    if (tree.root(i) == tree.root(ps[i] - 1)) {
      answer++;
    }
  }

  cout << answer << endl;
}
