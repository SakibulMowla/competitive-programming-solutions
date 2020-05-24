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
    cin >> n;

    vector < vector <int> > bids(n + 1, vector <int> ());
    vector <int> highestBid(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int id, amt;
        cin >> id >> amt;
        bids[id].pb(amt);
        highestBid[id] = max(highestBid[id], amt);
    }

    set <pii> ms;

    for (int i = 1; i <= n; i++) if (highestBid[i]) {
        ms.insert({highestBid[i], i});
    }

//    for (auto it: ms) {
//        cout << ">> " << it.X << ' ' << it.Y << endl;
//    }

    int q;
    cin >> q;

    for (int cs = 0; cs < q; cs++) {
        int m;
        cin >> m;

        vector <int> fire(m);
        for (auto &x: fire) {
            cin >> x;
            if (highestBid[x]) {
                ms.erase({highestBid[x], x});
            }
        }

        if (sz(ms) == 0) {
            cout << 0 << ' ' << 0 << endl;
        } else if (sz(ms) == 1) {
            cout << ms.begin()->Y << ' ' << bids[ms.begin()->Y][0] << endl;
        } else {
            int best = prev(ms.end())->Y, secondBest = prev(prev(ms.end()))->Y;
            int lo = 0, hi = sz(bids[best]) - 1, ans;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (bids[best][mid] > highestBid[secondBest]) {
                    ans = bids[best][mid];
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            cout << best << ' ' << ans << endl;
        }

        for (auto &x: fire) {
            if (highestBid[x]) {
                ms.insert({highestBid[x], x});
            }
        }
    }

    return 0;
}





