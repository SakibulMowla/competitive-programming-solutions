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
const ll mod = 1E9;


#define SZ 1000010

vector <ll> fun (ll n) {
    vector <ll> v;
    if (n == 0) {
        v.pb(0);
        v.pb(1);
        return v;
    }
    n = 8 * n + 1;
    double d = sqrt((double)n);
    if (d - (ll)d > 0) {
        v.pb(-1);
        return v;
    }
    n = (ll)d;
    n--;
    if (n & 1) {
        v.pb(-1);
        return v;
    }
    v.pb(n / 2 + 1);
    return v;
}

ll solve (ll b, ll c, ll zeros, ll ones) {
    ll zo = 0, oz = ones * zeros;
    if (b - zo != oz - c) {
        return -1;
    } else {
        ll last = 0, mid = -1;
        for (ll i = 1; i <= ones; i++) {
            if (oz - zeros >= c && zo + zeros <= b) {
                last++;
                oz -= zeros;
                zo += zeros;
            } else {
                ll tmp = oz - c;
                if (tmp != 0) {
                    mid = tmp;
                    oz -= tmp;
                    zo += tmp;
                }
            }
        }
        if (oz == c && zo == b) {
            ones -= last;
            if (mid != -1) ones--;
            while (ones) {
                printf("1");
                ones--;
            }
            for (int i = 1; i <= zeros; i++) {
                printf("0");
                if (i == mid) printf("1");
            }
            while (last) {
                printf("1");
                last--;
            }
            printf("\n");
        } else {
            return -1;
        }
    }
    return 1;
}

int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    ll a, b, c, d;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);

    if (a + b + c + d == 0) {
        printf("1\n");
        return 0;
    }

    vector <ll> zeros = fun(a), ones = fun(d);
    bool flag = false;

    for (auto x: zeros) {
        for (auto y: ones) {
            if (x == -1 || y == -1) break;
            if (solve(b, c, x, y) != -1) {
                flag = true;
                break;
            }
        }
    }
    if (!flag) printf("Impossible\n");

    return 0;
}





