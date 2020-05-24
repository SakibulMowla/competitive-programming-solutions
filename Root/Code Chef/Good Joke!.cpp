#include "bits/stdc++.h"

using namespace std;

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
typedef pair<pii , int> piii;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    vector <piii> v1, v2;

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        v1 = vector <piii>(n);
        v2 = vector <piii>(n);

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v1[i].X.X = v2[i].X.Y = x;
            v1[i].X.Y = v2[i].X.X = y;
            v1[i].Y = v2[i].Y = i + 1;
        }

        stable_sort(v1.begin(), v1.end());
        stable_sort(v2.begin(), v2.end());

        if (v1[0].Y > v1[n-1].Y) reverse(v1.begin(), v1.end());
        if (v2[0].Y > v2[n-1].Y) reverse(v2.begin(), v2.end());

        int cost1 = 0, cost2 = 0;
        for (int i = 1; i < n; i++) {
            cost1 += min(abs(v1[i].X.X - v1[i-1].X.X), abs(v1[i].X.Y - v1[i-1].X.Y));
            cost1 += min(abs(v2[i].X.X - v2[i-1].X.X), abs(v2[i].X.Y - v2[i-1].X.Y));
        }

        int dir = 1;
        if (cost2 < cost1) dir = 2;
        else if (cost1 == cost2) {
            for (int i = 0; i < n; i++)
                if (v1[i].Y > v2[i].Y) {
                    dir = 2;
                    break;
                }
        }

        int ans = 0;
        if (dir == 1) for (int i = 0; i < n; i++) ans ^= v1[i].Y;
        else for (int i = 0; i < n; i++) ans ^= v2[i].Y;

        cout <<  ans  << '\n';
    }


    return 0;
}




