#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010


class AliceGame {
public:
	long long findMinimumValue(long long x, long long y) {
        ll sum = x + y;
        double d = sqrt((double)sum);
        if ((ll)d*(ll)d != sum) return -1LL;

        ll n = (ll)d;
        ll tmpx = x;
        ll cnt = 0LL;

        for (ll i = 2LL*n - 1LL; i >= 1LL; i -= 2LL) {
            if (tmpx - i >= 0LL && tmpx - i != 2LL)
                tmpx -= i, cnt++;
        }

        if (tmpx != 0LL) return -1LL;
        return cnt;
	}
};
