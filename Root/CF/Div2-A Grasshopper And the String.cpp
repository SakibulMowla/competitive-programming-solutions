#include <iostream>
									
using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)				
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

bool isVowel (char ch) {
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'|| ch == 'Y';
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	string s;
	cin >> s;
	s += 'A';

	int jump = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		jump++;
		// cout << "Hello " << s[i] << " ";
		if (isVowel(s[i])) {
			ans = max(ans, jump);
			jump = 0;
			// cout << "World";
		}
		// cout << endl;
	}

	cout << ans << endl;

    return 0;
}






