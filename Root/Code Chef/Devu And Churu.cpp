#include <bits/stdc++.h>

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

#define SZ 1000010

struct data {
	int v, idx;
};

bool comp (data a, data b) {
	return a.v < b.v;
}

data a[SZ];

struct data1 {
	char c1, c2;
	int k;
};

data1 q[SZ];

int x[2 * SZ];
int xsz;

ll cnt[2 * SZ];
char s[SZ];
set <int> ms1;

int p[SZ];
int sz[SZ];
bool flag[SZ];

int get(int x) {
    return x == p[x] ? x : (p[x] = get(p[x]));
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        sz[x] += sz[y];
        p[y] = x;
    }
}

int main() {
    int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].v);
		a[i].idx = i + 1;
		x[i] = a[i].v;
	}

	for (int i = 0; i < m; i++) {
		scanf(" %c %d %c", &q[i].c1, &q[i].k, &q[i].c2);
        x[n + i] = q[i].k;
	}

	sort(x, x + n + m);
	xsz = unique(x, x + n + m) - x;

	sort(a, a + n, comp);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
        flag[i] = true;
    }

    for (int i = 0; i < n; i++) {
        int idx = a[i].idx;

        int l = 1, r = 1;

        if (idx > 1 && !flag[idx - 1]) {
            l = get(idx - 1);
            l = sz[l] + 1;
        }
        if (idx + 1 <= n && !flag[idx + 1]) {
            r = get(idx + 1);
            r = sz[r] + 1;
        }

        cnt[int(lower_bound(x, x + xsz, a[i].v) - x)] += (ll)l * (ll)r;

        if (idx > 1 && !flag[idx - 1]) unite(idx - 1, idx);
        if (idx + 1 <= n && !flag[idx + 1]) unite(idx + 1, idx);
        flag[idx] = false;
    }

	for (int i = 1; i <= xsz; i++) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; i < m; i++) {
		ll tot;
		q[i].k = (int)(lower_bound(x, x + xsz, q[i].k) - x);
		if (q[i].c1 == '>') {
			tot = cnt[xsz] - cnt[q[i].k];
		} else if (q[i].c1 == '=') {
			tot = cnt[q[i].k] - (q[i].k ? cnt[q[i].k - 1] : 0);
		} else {
			tot = (q[i].k ? cnt[q[i].k - 1] : 0);
		}
		char c;
		if (tot & 1) c = 'D';
		else c = 'C';
		if (q[i].c2 == 'C') {
			if (c == 'C') c = 'D';
			else c = 'C';
		}
		s[i] = c;
	}
	s[m] = '\0';
	printf("%s\n", s);
	return 0;
}



