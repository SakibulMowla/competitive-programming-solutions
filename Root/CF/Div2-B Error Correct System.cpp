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

#define SZ 200

int mat[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int cnt = 0;
	int indx1 = -1, indx2 = -1;
	
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			cnt++;
			mat[s[i]][t[i]] = i + 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (mat[t[i]][s[i]]) {
				indx1 = i + 1;
				indx2 = mat[t[i]][s[i]];
				cnt -= 2;
				goto Hell;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			for (int j = 'a'; j <= 'z'; j++) {
				if (mat[t[i]][j]) {
					indx1 = i + 1;
					indx2 = mat[t[i]][j];
					cnt = cnt - 1;
					goto Hell;
				}
			}
		}
	}

	Hell:;
	cout << cnt << '\n' << indx1 << ' ' << indx2 << '\n';


    return 0;
}

/*
4
abba
caba
*/




