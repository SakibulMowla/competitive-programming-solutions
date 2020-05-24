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

#define SZ 200010

vector <int> v[SZ];
vector <int> ans;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int n;
	while (cin >> n) {
		for (int i = 0; i <= n; i++) {
			clr(v[i]);
		}
		
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			v[a].pb(i + 1);
		}
		
		int now = 0;
		clr(ans);
		
		while (now >= 0) {
			if (sz(v[now])) {
				ans.pb(v[now].back());
				v[now].pop_back();
				now++;
			} else {
				now -= 3;
			}
		}

		if (sz(ans) != n) {
			printf("Impossible\n");
		} else {
			printf("Possible\n");
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}


    return 0;
}






