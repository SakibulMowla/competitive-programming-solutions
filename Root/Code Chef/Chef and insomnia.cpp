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

int a[SZ];
vector <int> v[SZ];
vector <int> mark[SZ];
int l[SZ];
int r[SZ];
int found[SZ];

vector <int> factor[SZ];
int rr[SZ];

vector <int> prime;
int arr[SZ];

void sieve () {
    int k = sqrt(100010);
    for (int i = 3; i <= k; i += 2) {
        for (int j = i * i; j <= 100000; j += i + i) {
            arr[j] = 1;
        }
    }
    prime.pb(2);
    for (int i = 3; i <= 100000; i += 2) {
        if (!arr[i]) {
            prime.pb(i);
        }
    }
    return;
}

vector <int> now;
int cnt[SZ];

void factorize(int n) {
    clr(now);
    for (int i = 0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            cnt[prime[i]] = 0;
            now.pb(prime[i]);
            while (n % prime[i] == 0) {
                n /= prime[i];
                cnt[prime[i]]++;
            }
        }
    }
    if (n != 1) {
        now.pb(n);
        cnt[n] = 1;
    }
    return;
}

void bctk (int pos, int n, int val) {
    if (pos == -1) {
        if (r[val]) {
            factor[n].pb(val);
            rr[n]++;
        }
        return;
    }
    int k = 1;
    bctk(pos - 1, n, val);
    for (int i = 0; i < cnt[now[pos]]; i++) {
        k *= now[pos];
        bctk(pos - 1, n, val * k);
    }

    return;
}

void init (int k) {
    sieve();
    for (int i = 1; i <= 100000; i++) if (i + k <= 100000 && r[i + k]) {
        factorize(i);
        bctk(sz(now) - 1, i, 1);
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v[a[i]].pb(i);
        r[a[i]]++;
    }

    init(k);

    int indx = 0;

    for (int i = 1; i <= n; i++) {
        l[a[i]]++;
        if (a[i] == k) {
            int j;
            for (j = max(indx, i + 1); j <= n; j++) {
                if (a[j] > k) {
                    mark[i].pb(i);
                    mark[j].pb(i);
                    break;
                }
            }
            indx = j;
        } else if (a[i] > k) {
            a[i] -= k;
            int j;
            int mx = 1E6;

            for (int j = 0; j < rr[a[i]]; j++) {
                int f = factor[a[i]][j];
                if (f > k && l[f] != r[f]) {
                    mx = min(mx, v[f][l[f]]);
                }
            }

            if (mx != 1E6) {
                mark[i].pb(i);
                mark[mx].pb(i);
            }
        }
    }

    int pre = 1;
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (sz(mark[i])) {
            for (int j = 0; j < sz(mark[i]); j++) {
                if (!found[mark[i][j]]) {
                    found[mark[i][j]] = i;
                } else {
                    pre = max(pre, found[mark[i][j]] + 1);
                }
            }
        }
        ans += (ll)(i - pre + 1);
    }

    printf("%lld\n", ans);

    return 0;
}







