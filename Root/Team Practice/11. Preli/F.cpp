#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1000000007LL;

#define SZ  40

vector <pll> val;
vector <ll> need[40];
ll arr[SZ];
ll fact[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1LL;
    for (int i = 1; i < 35; i++)
        fact[i] = ((ll)i * fact[i-1]) % mod;

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        ll k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int n1 = n / 2, n2 = n - n1;

        clr(val);
        for (int i = 0; i < 20; i++)
            clr(need[i]);

        for (int mask = 0; mask < (1<<n1); mask++) {
            ll tmp = 0LL;
            for (int j = 0; j < n1; j++)
                if(mask & (1<<j))
                    tmp += arr[j];
            val.pb(MP(tmp, (ll)__builtin_popcount(mask)));
        }

        for (int mask = 0; mask < (1<<n2); mask++) {
            ll tmp = 0LL;
            for (int j = 0; j < n2; j++)
                if(mask & (1<<j))
                    tmp += arr[n1+j];
            need[__builtin_popcount(mask)].pb(tmp);
        }

        for (int i = 0; i < n2; i++)
            sort(need[i].begin(), need[i].end());

        ll ans = 0LL;

        for (int i = 0; i < sz(val); i++) {
            if(val[i].X > k) continue;

            ll sum1 = val[i].X;
            ll cnt1 = val[i].Y;
            ll sum2 = k - sum1;

            for (int j = 0; j <= n2; j++) {
                int it1 = lower_bound(need[j].begin(), need[j].end(), sum2) - need[j].begin();
                int it2 = lower_bound(need[j].begin(), need[j].end(), sum2+1) - need[j].begin();

                ll tmp = (fact[(int)cnt1+j] * fact[n-(int)cnt1-j]) % mod;
                tmp = (tmp * (it2-it1)) % mod;

                ans = (ans + tmp) % mod;
            }
        }

        cout << "Case " << cs+1 << ": " << ans << '\n';
    }

    return 0;
}




