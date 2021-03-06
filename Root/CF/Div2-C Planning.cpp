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

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<pii> a(n + 1);
    priority_queue<pii> pq;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].X;
        a[i].Y = i;
        if (i <= k) {
            pq.push(a[i]);
        }
    }

    vector<int> b(n + 1);
    ll cost = 0;

    for (int i = k + 1; i <= k + n; i++) {
        if (i <= n) {
            pq.push(a[i]);
        }
        b[pq.top().Y] = i;
        cost += (ll)(i - pq.top().Y) * pq.top().X;
        pq.pop();
    }

    cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
 
    return 0;
}




