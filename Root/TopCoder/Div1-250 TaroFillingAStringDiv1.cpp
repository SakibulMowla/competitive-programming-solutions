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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1E9+7;

#define SZ  100010

class TaroFillingAStringDiv1 {
public:
    inline ll funk (int n, bool same) {
        if (same) {
            if (n % 2 == 1) return 1;
            return n + 1;
        } else {
            if (n % 2 == 0) return 1;
            return n + 1;
        }
    }

    inline int getNumber(int N, vector <int> &position, string value) {
        vector < pair <int, char> > v;

        for (int i = 0; i < sz(position); i++) {
            v.pb({position[i], value[i]});
        }

        sort(v.begin(), v.end());

        ll ans = 1LL;
        for (int i = 1; i < sz(v); i++) {
            ans = (ans * funk(v[i].X - v[i-1].X - 1, v[i].Y == v[i-1].Y)) % mod;
        }

        return ans;
    }

};


