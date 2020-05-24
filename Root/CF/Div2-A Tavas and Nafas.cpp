#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

string s[100];

void f (int n) {
	s[0] = "zero";      s[10] = "ten";
	s[1] = "one";		s[11] = "eleven";	 	 
	s[2] = "two";		s[12] = "twelve";
	s[3] = "three";		s[13] = "thirteen";
	s[4] = "four";		s[14] = "fourteen";
	s[5] = "five";		s[15] = "fifteen";
	s[6] = "six";		s[16] = "sixteen";
	s[7] = "seven";		s[17] = "seventeen";
	s[8] = "eight";		s[18] = "eighteen";
	s[9] = "nine";		s[19] = "nineteen";
	if (n < 20) {
		cout << s[n];
	} else if (n < 30) {
		cout << "twenty";
	} else if (n < 40) {
		cout << "thirty";
	} else if (n < 50) {
		cout << "forty";
	} else if (n < 60) {
		cout << "fifty";
	} else if (n < 70) {
		cout << "sixty";
	} else if (n < 80) {
		cout << "seventy";
	} else if (n < 90) {
		cout << "eighty";
	} else if (n < 100) {
		cout << "ninety";
	} 
	if (n > 20 && (n % 10)) cout << '-' << s[n%10];
	cout << '\n';
	return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int n;
	while (cin >> n) {
		f (n);
	}


    return 0;
}






