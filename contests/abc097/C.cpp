#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin >> S;

  int K;
  cin >> K;

  vector<string> cs;

  for (int i = 0; i < S.size(); i++) {
    for (int j = 1; j <= K && i + j <= S.size(); j++) {
      cs.push_back(S.substr(i, j));
    }
  }

  sort(cs.begin(), cs.end());
  unique(cs.begin(), cs.end());

  cout << cs[K-1] << endl;
}
