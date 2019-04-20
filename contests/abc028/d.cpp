#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
const double EPS = 1e-9;
#define MSG(a) cout << #a << " " << a << endl;

int main() {
	double N, K;
	cin >> N >> K;
	
	cout << setprecision(10) << ((K - 1) * (N - K) * 6 + (N - K) * 3 + (N - K) * 3 + 1) / N / N / N << endl;
}

// s/m/b (K - 1) * (N - K) * 6
// s/b/m 
// m/s/b
// m/b/s
// b/m/s
// b/s/m
// m/m/b (N - K) * 3
// m/b/m
// b/m/m
// s/m/m (N - K) * 3
// m/s/m
// m/m/s
// m/m/m 1
