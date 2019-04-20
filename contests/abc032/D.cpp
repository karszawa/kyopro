#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int N, W;
int vv[200], ww[200];

long long int solve1() {
	vector<pair<int, int>> A, B;
	 
	for(int i = 0; i < (1 << 15); i++) {
		int av = 0, aw = 0, bv = 0, bw = 0;
		
		for(int j = 0; j < 15; j++) {
			if(i & (1 << j)) {
				av += vv[j]; aw += ww[j];
				bv += vv[15 + j]; bw += vv[15 + j];
			}
		}
		
		A.push_back(make_pair(av, aw));
		B.push_back(make_pair(bv, bw));
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	long long int best = 0;
	
	for(auto p : A) {
		long long int pv = p.first, pw = p.second;
		int pp = upper_bound(B.begin(), B.end(), [](pair<int, int> a, pair<int, int> b) {
			return (a.second != b.second ? a.second > b.second : a.first > b.first);  
    }) - B.begin();
		
		best = max(best, pv + max_element(B.begin(), B.begin() + pp)->second);
	}
	
	cout << best << endl;
}

long long int solve2() {
	int M = accumulate(vv, vv + N, 0);
	vector<long long int> dp(M + 1);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= M; j++) {
			
		}
	}
}

int main() {
	cin >> N >> W;
	
	for(int i = 0; i < N; i++) {
		cin >> vv[i] >> ww[i];
	}

	if(N <= 30) {
		cout << solve1() << endl;
	} else if(*max_element(ww, ww + N) <= 1000) {
		
	} else {
		
	}
}
