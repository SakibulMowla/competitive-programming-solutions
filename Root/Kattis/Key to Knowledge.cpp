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

struct Solve {
    int n, m;
    int n1, n2;
    int lim1, lim2;
    vector <pii> a;
    vector <ll> mark;
    ll gTotal;
    vector <pll> Half1, Half2;
    int one;

    Solve (int n, int m): n(n), m(m), a(n, {0, 0}), mark(n) {
        n1 = m / 2;
        n2 = m - n1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n1; j++) {
                char ch;
                cin >> ch;
                a[i].X = (a[i].X << 1) | (ch-'0');
            }
            for (int j = 0; j < n2; j++) {
                char ch;
                cin >> ch;
                a[i].Y = (a[i].Y << 1) | (ch-'0');
            }
            cin >> mark[i];
        }
        process();
        ll ans = FindAns();
        if (ans != 1) {
            cout << ans << " solutions" << endl;
        } else {
            for (int i = m - 1; i >= 0; i--) {
                if (one & (1<<i)) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
    }

    void process () {
        gTotal = 0;
        for (int i = 0; i < n; i++) {
            gTotal = (gTotal << 5) | mark[i];
        }

        lim1 = (1 << n1);
        lim2 = (1 << n2);

        for (int mask = 0; mask < lim1; mask++) {
            ll Hmark = 0;
            for (int i = 0; i < n; i++) {
                ll cnt = 0;
                for (int j = 0; j < n1; j++) {
                    if ((mask&(1<<j)) == (a[i].X&(1<<j))) cnt++;
                }
                Hmark = (Hmark << 5) | cnt;
            }
            Half1.pb({Hmark, (ll)mask});
        }

        for (int mask = 0; mask < lim2; mask++) {
            ll Hmark = 0;
            for (int i = 0; i < n; i++) {
                ll cnt = 0;
                for (int j = 0; j < n2; j++) {
                    if ((mask&(1<<j)) == (a[i].Y&(1<<j))) cnt++;
                }
                Hmark = (Hmark << 5) | cnt;
            }
            Half2.pb({Hmark, (ll)mask});
        }

        sort(Half1.begin(), Half1.end());
        sort(Half2.begin(), Half2.end());

        return;
    }

    ll FindAns () {
        ll ans = 0;
        for (int i = 0, j = lim2 - 1; i < lim1 && j >= 0; ) {
            ll offer = Half1[i].X + Half2[j].X;
            if (offer == gTotal) {
                one = ((Half1[i].Y << n2) | Half2[j].Y);
                ll k1 = 1, k2 = 1;
                while (i+1 < lim1 && Half1[i+1].X == Half1[i].X) i++, k1++;
                while (j-1 >= 0 && Half2[j-1].X == Half2[j].X) j--, k2++;
                ans += k1 * k2;
                i++;
                j--;
            } else if (offer < gTotal) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    #if defined JESI
//        freopen("K.in", "r", stdin);
//        freopen("1.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;
        Solve Task(n, m);
    }

    return 0;
}

