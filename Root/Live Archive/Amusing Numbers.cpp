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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

string num;

void pre (ll mid) {
    int len = 0;
    while (mid) {
        len++;
        mid /= 10LL;
    }
    return len;
}

bool f (ll mid, string &s) {
    num = s;
    int len = pre(mid);
    while (sz(num) < len) num
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int m;
    char k[12];

    while (cin >> k >> m) {
        if (atoi(k) > m) {
            cout << "0\n";
            continue;
        }

        string tmp = k;
        ll lo = m;
        ll hi = 5E18;
        ll ans;

        while (lo <= hi) {
            ll mid = (lo + hi) >> 1LL;
            if (f(mid, tmp)) {
                ans = mid;
                hi = mid - 1LL;
            } else lo = mid + 1LL;
        }

        cout << ans;
    }


    return 0;
}


