#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while (P > 0) {
        if (P & 1) R = (R * B) % M;
        P >>= 1;
        B = (B * B) % M;
    }
    return R;
}

const ll mod = 1E9+7;

#define SZ 100010

map <ll, ll> way;
struct data {
    ll e0, e1, e2, e3;
};

vector <ll> v;
vector <ll> adj[50010];
map <ll, int> mp;

int main() {
    ll n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    int p = 0;
    for (int i = 0; i < k; i++) {
        data u;
        scanf("%lld %lld %lld %lld", &u.e0, &u.e1, &u.e2, &u.e3);
        v.pb(u.e0);
        v.pb(u.e2);
        if (mp.find(u.e0) == mp.end()) {
            mp[ u.e0 ] = p++;
        }
        adj[ mp[ u.e0 ] ].pb(u.e2);
    }
    v.pb(0);
    v.pb(1);
    v.pb(n+1);
    v.pb(n+2);

    sort(v.begin(), v.end());
    Unique(v);

    for (int i = sz(v) - 1; i >= 0; i--) {
        if (v[i] >= n) {
            way[ v[i] ] = 1;
//        } else if (v[i] == 0) {
//            way[ v[i] ] = way[1];
        } else {
            way[ v[i] ] = (BigMod(m, v[i+1] - v[i], mod) * way[ v[i+1] ]) % mod;
        }
        if (mp.find(v[i]) != mp.end()) {
            for (int j = 0; j < sz(adj[ mp[ v[i] ] ]); j++) {
                way[ v[i] ] = way[ v[i] ] + way[ adj[ mp[ v[i] ] ][j] ];
                if (way[ v[i] ] >= mod) way[ v[i] ] -= mod;
            }
        }
        cout << ">> " << v[i] << ' ' << way[ v[i] ] << '\n';
    }

    printf("%lld\n", way[0]);


    return 0;
}






