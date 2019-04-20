#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> es(N), ws(N);

    for (int i = 0; i < N; i++) {
        es[i] = (i == 0 ? 0 : es[i-1]) + (S[i] == 'W');
        ws[N-i-1] = (i == 0 ? 0 : ws[N-i]) + (S[N-i-1] == 'E');
    }

    int best = 1 << 30;

    for (int i = 0; i < N; i++) {
        int ec = (i == 0 ? 0 : es[i-1]);
        int wc = (i + 1 == N ? 0 : ws[i+1]);

        best = min(best, ec + wc);
    }

    cout << best << endl;
}
