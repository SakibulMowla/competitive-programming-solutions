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

ll val[30];
ll sum[SZ];
vector <int> adj[30];
unordered_map <ll, ll> mp;

ll solve (vector <int> &v) {
    if (sz(v) < 2) return 0;

    clr(mp);

    for (int i = 1; i < sz(v); i++) {
        mp[ sum[ v[i]-1 ] - sum[ v[0] ] ]++;
    }

    ll need = 0;
    ll ans = mp[need];

    for (int i = 1; i < sz(v); i++) {
        mp[ sum[ v[i]-1 ] - sum[ v[0] ] ]--;
        need += sum[ v[i] ] - sum[ v[i-1] ];
        ans += mp[need];
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    for (int i = 0; i < 26; i++) {
        cin >> val[i];
    }

    string s;
    cin >> s;

    for (int i = 0; i < sz(s); i++) {
        adj[s[i]-'a'].pb(i+1);
        sum[i+1] = sum[i] + val[s[i]-'a'];
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += solve(adj[i]);
    }

    cout << ans << '\n';

    return 0;
}





