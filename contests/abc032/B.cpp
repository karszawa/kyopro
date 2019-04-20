#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string s;
	int k;
	
	cin >> s >> k;
	
	set<string> dictionary;
	
	for(int i = 0; i + k <= s.size(); i++) {
		dictionary.insert(s.substr(i, k));		
	}
	
	cout << dictionary.size() << endl;
}
