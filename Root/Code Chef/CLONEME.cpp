#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;

#define SZ  100010

ll a[SZ];
ll mod[] = {1000001857, 999996247};
ll base[] = {29, 41};
ll bp[SZ][2];

struct data {
	int lim;
	ll m1, m2;
};

data tree[4 * SZ];
vector <ll> store[4 * SZ];

void build(int node, int b, int e) {
	if (b == e) {
		store[node].pb()
	}
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    //ios::sync_with_stdio(false);

	bp[0][0] = 1;
	bp[0][1] = 1;
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < 2; j++) {
			bp[i][j] = (bp[i - 1][j] * base[j]) % mod[j];
		}
	}

	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	while (q--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		int r = b - a + 1;
		bool flag = true;

		while (r > 1) {
			;
		}

		printf("%s\n", flag? "YES": "NO");
	}


    return 0;
}



