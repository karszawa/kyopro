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
	vector<int> numbers(5);
	for(auto &n : numbers) {
		cin >> n;
	}
	
	vector<int> candidates;
	while(next_permutation(numbers.begin(), numbers.end())) {
		candidates.push_back(numbers[0] + numbers[1] + numbers[2]);
	}
	
	sort(candidates.begin(), candidates.end(), greater<int>());
	candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
	
	cout << candidates[2] << endl;
}
