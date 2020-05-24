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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector <pii> a(n);
        set <int> ms;

        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
            ms.insert(a[i].X);
        }

        map <int, int> r2v, v2r;
        int cnt = 0;

        for (auto it: ms) {
            r2v[it] = cnt++;
            v2r[cnt-1] = it;
        }

        vector <set <pii>> info(cnt);

        for (int i = 0; i < n; i++) {
            info[r2v[a[i].X]].insert({a[i].Y, i});
        }

        bool found = false;
        int a1, a2, a3;

        for (int i = 1; i < cnt; i++) {
            if (sz(info[i]) > 1) {
                auto itr = info[i].begin();
                a1 = itr->Y;
                itr = next(itr);
                a2 = itr->Y;
                itr = info[i-1].begin();
                a3 = itr->Y;
                found = true;
                break;
            }
            if (sz(info[i-1]) > 1) {
                auto itr = info[i-1].begin();
                a1 = itr->Y;
                itr = next(itr);
                a2 = itr->Y;
                itr = info[i].begin();
                a3 = itr->Y;
                found = true;
                break;
            }
        }

        if (!found) {
            for (int i = 2; i < cnt; i++) {
                auto itr1 = info[i-2].begin();
                auto itr2 = info[i-1].begin();
                auto itr3 = info[i].begin();
                int x1 = v2r[i-2], x2 = v2r[i-1], x3 = v2r[i];
                int y1 = itr1->X, y2 = itr2->X, y3 = itr3->X;
                int h1 = x1 - x2, h2 = x2 - x3;
                int l1 = y1 - y2, l2 = y2 - y3;
//                h1 /= __gcd(abs(h1), abs(l1));
//                l1 /= __gcd(abs(h1), abs(l1));
//                h2 /= __gcd(abs(h2), abs(l2));
//                l2 /= __gcd(abs(h2), abs(l2));
                if ((ll)h1 * (ll)l2 != (ll)l1 * (ll)h2) {
                    a1 = itr1->Y;
                    a2 = itr2->Y;
                    a3 = itr3->Y;
                    break;
                }
            }
        }

        cout << a1 + 1 << ' ' << a2 + 1 << ' ' << a3 + 1 << endl;
    }


    return 0;
}





