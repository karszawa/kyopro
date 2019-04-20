struct UnionFind {
  std::vector<int> data;
  UnionFind(int size) : data(size, -1) {}

  void unite(int i, int j) {
    i = root(i);
    j = root(j);

    if (i != j) {
      data[i] += data[j];
      data[j] = i;
    }
  }

  void root(int i) {
    if (data[i] < 0) {
      return i;
    } else {
      return data[i] = root(data[i]));
    }
  }

  bool same(int i, int j) {
    return root(i) == root(j);
  }
}
