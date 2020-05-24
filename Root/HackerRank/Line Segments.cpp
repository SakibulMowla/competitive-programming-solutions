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

bool comp (pii a, pii b) {
    if (a.X == b.X) {
        return a.Y > b.Y;
    }
    return a.X < b.X;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <pii> v(n);
    multiset <int> ms;

    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
        ms.insert(v[i].Y);
    }

    sort(v.begin(), v.end(), comp);

    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        ms.erase(ms.find(v[i].Y));
        if (*ms.begin() <= v[i].Y) {
            ans--;
        }
    }

    cout << ans << endl;


    return 0;
}


/*
3
1 5
3 4
2 6
*/




