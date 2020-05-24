#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < vector <int> > appearance(n + 1, vector <int> ());
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        appearance[a[i]].pb(i + 1);
    }

    set <pii> pq;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int pre = appearance[a[i]][0];
        appearance[a[i]].erase(appearance[a[i]].begin());
        if (pq.find({-pre, a[i]}) == pq.end()) {
            if (pq.size() == k) {
                pq.erase(pq.begin());
            }
            ans++;
        } else {
            pq.erase(pq.find({-pre, a[i]}));
        }
        pq.insert({appearance[a[i]].size() == 0 ? -100000000 : -appearance[a[i]][0], a[i]});
    }

    cout << ans << endl;

    return 0;
}



