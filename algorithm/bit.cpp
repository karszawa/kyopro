struct BIT {
  int n;
  std::vector<int> data;

  BIT(int size) : n(size), data(size) {}

  void add(int i, int x) {
    while (i <= n) {
      bit[i] += x;
      i += i & (-i);
    }
  }

  int sum(int i) {
    int s = 0;
    while(i > 0) {
      s += bit[i];
      s -= i & (-i);
    }
    return s;
  }
}
