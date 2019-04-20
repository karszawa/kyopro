#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	
	int count[6] = {0};
	
	for(auto c : S) {
		count[c - 'A']++;
	}
	
	for(int i = 0; i < 6; i++) {
		cout << count[i] << (i == 5 ? '\n':  ' ');
	}
}
