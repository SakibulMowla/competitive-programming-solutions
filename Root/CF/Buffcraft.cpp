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


#define SZ 100010

bool comp (pll a, pll b) {
    return a.X > b.X;
}

pll d[50000+10], p[50000+10];

int main() {
//    #if defined JESI
        freopen("buffcraft.in", "r", stdin);
        freopen("buffcraft.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    ll b;
    int k, cd, cp;
    cin >> b >> k >> cd >> cp;

    for (int i = 1; i <= cd; i++) {
        cin >> d[i].X;
        d[i].Y = i;
    }

    for (int i = 1; i <= cp; i++) {
        cin >> p[i].X;
        p[i].Y = i;
    }

    sort(d + 1, d + cd + 1, comp);
    sort(p + 1, p + cp + 1, comp);

    for (int i = 2; i <= cd; i++) {
        d[i].X += d[i-1].X;
    }

    for (int i = 2; i <= cp; i++) {
        p[i].X += p[i-1].X;
    }

    ll ans = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i <= min(k, cd); i++) {
        int j = min(k - i, cp);
        if ((b + d[i].X) * (100LL + p[j].X) > ans) {
            ans = (b + d[i].X) * (100LL + p[j].X);
            cnt1 = i;
            cnt2 = j;
        }
    }

    cout << cnt1 << ' ' << cnt2 << endl;

    if (cnt1) {
        for (int i = 1; i <= cnt1; i++) {
            if (i - 1) cout << ' ';
            cout << d[i].Y;
        }
        cout << endl;
    }

    if (cnt2) {
        for (int i = 1; i <= cnt2; i++) {
            if (i - 1) cout << ' ';
            cout << p[i].Y;
        }
        cout << endl;
    }

    return 0;
}





