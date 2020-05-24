#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9 + 7;


#define SZ 1000010

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

struct Solve {
    int n;
    int k;
    vector <ll> f;
    vector <int> a;
    vector <int> cnt;

    Solve (int n, int k): n(n), k(k), a(n), f(2 * n + 1, 1) {
        for (int i = 1; i <= 2 * n; i++) f[i] = (f[i - 1] * i) % mod;
        for (auto &x: a) cin >> x;

        int kp = min(k, n);
        cnt = vector <int> (kp + 2, 0);
        int dist = 0;
        ll ansp = 0;

        for (int l = 0, r = 0; r < n; r++) {
            if (a[r] <= kp) {
                cnt[a[r]]++;
                if (cnt[a[r]] == 1) dist++;
                if (dist == k) {
                    while (l + 1 <= r && (a[l] > kp || (a[l] <= kp && cnt[a[l]] != 1))) {
                        cnt[a[l]]--;
                        l++;
                    }
                    ansp = (ansp + C(2 * (n - r + l) - 1, n - r + l)) % mod;
                    if (a[l] <= kp) {
                        cnt[a[l]]--;
                        if (cnt[a[r]] == 0) dist--;
                    }
                    l++;
                }
            }
        }

        cout << (C(2 * n - 1, n) - ansp + mod) % mod << endl;
    }

    ll C(int n, int r) {

    }
};


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    Solve sol(n, k);

    return 0;
}




