#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long int l = 0, r = 0, p = 0, answer = 0;

    while (r < N) {
        if ((p ^ A[r]) == p + A[r]) {
            p += A[r];
            r++;
            answer += r - l;
        } else if (l == r) {
            r++;
        } else {
            p -= A[l];
            l++;
        }
    }

    cout << answer << endl;
}