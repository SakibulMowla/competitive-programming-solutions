#include <iostream>
#include <vector>
									
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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> lft(n), rht(n);
	int lsum = 0, rsum = 0;

	for (int i = 0; i < n; i++) {
		cin >> lft[i] >> rht[i];
		lsum += lft[i];
		rsum += rht[i];
	}

	int indx = 0, best = abs(lsum - rsum);
	for (int i = 0; i < n; i++) {
		if (best < abs((lsum - lft[i] + rht[i]) - (rsum - rht[i] + lft[i]))) {
			indx = i + 1;
			best = abs((lsum - lft[i] + rht[i]) - (rsum - rht[i] + lft[i]));
		}
	}

	cout << indx << endl;

    return 0;
}

/*
3
5 6
8 9
10 3
*/




