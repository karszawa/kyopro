#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;	
	
	vector<int> s(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		
		if(s[i] == 0) {
			cout << n << endl;
			return 0;
		}
	}
	
	int f = 0, l = 0, best = 0;
	long long int product = s[0];
	
	while(true) {
		if(product <= k) {
			best = max(best, f - l + 1);
			f++;
			
			if(f == s.size()) {
				break;
			}
			
			product *= s[f];
		} else {
			if(f == l) {
				f++;
				l++;
				
				if(f == s.size()) {
					break;
				}
				
				product = s[f];
			} else {
				product /= s[l];
				l++;
			}
		}
	}
	
	cout << best << endl;
}
