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
const ll mod = (1E9)+7LL;
const ll mod1 = 2LL * ((1E9)+6LL);


#define SZ 200010

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

vector <ll> cnt(200010, 1);
ll lft[SZ], rht[SZ];


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);



    int n;
    cin >> n;

    vector <ll> a(n);

    for (auto &x: a) {
        cin >> x;
        cnt[x]++;
    }

    lft[1] = 1, rht[200001] = 1;
    for (int i = 2; i <= 200000; i++) lft[i] = (cnt[i] * lft[i-1]) % mod1;
    for (int i = 200000; i >= 1; i--) rht[i] = (cnt[i] * rht[i+1]) % mod1;

    ll ans = 1;

    for (int i = 2; i <= 200000; i++) if (cnt[i] > 1) {
        ll tpow = ((cnt[i] * (cnt[i] - 1LL)) / 2LL) % mod1;
        tpow = (tpow * lft[i-1]) % mod1;
        tpow = (tpow * rht[i+1]) % mod1;
        ans = (ans * BigMod((ll)i, tpow, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}

