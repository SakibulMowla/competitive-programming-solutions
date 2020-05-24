// CERC 2012
// Problem B: Who wants to live forever?
// O(n) solution
// Author: Arkadiusz Pawlik

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool die(string s) {
	s += "0";
	int n = s.size();
	int l = ((n ^ (n-1)) + 1) / 2;
	int cnt = n / l;
	for (int i = 1; i < cnt; ++i) {
		for (int k = 0; k < l-1; ++k) {
			if (s[i*l+k] != s[i*l-2-k]) return false;
		}
		if (s[i*l-1] != '0') return false;
	}
	return true;
}

string ft(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (i % 3 == 2) continue;
		s[i] = (s[i] == '1') ? '0' : '1';
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if (die(s)) cout << "DIES" << endl;
		else cout << "LIVES" << endl;
	}
}
