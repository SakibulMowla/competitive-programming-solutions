#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

int cal(string s) {
	return (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
}

int main() {  
	string s;
	for (int i = 1; i < 10; i++) {
		s += to_string(i);
	}

	do {
		if (cal(s.substr(0, 3)) + cal(s.substr(3, 3)) == cal(s.substr(6, 3))) {
			cout << s << endl;
			break;
		}
	} while (next_permutation(s.begin(), s.end()));

    return 0;
}
