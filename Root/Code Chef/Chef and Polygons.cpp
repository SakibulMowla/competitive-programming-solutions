#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define pb push_back

#define x first
#define y second

typedef pair <double , double> pdd;
typedef pair <double , int> pdi;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

bool comp (pdi a, pdi b) {
    return a.x < b.x;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <pdd> polygon[n];

        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                double x, y;
                cin >> x >> y;
                polygon[i].pb({x, y});
            }
            polygon[i].pb({polygon[i][0].x, polygon[i][0].y});
        }

        vector <pdi> area;

        for (int i = 0; i < n; i++) {
            double tmp = 0;
            for (int j = 1; j < sz(polygon[i]); j++) {
                tmp += (polygon[i][j-1].x * polygon[i][j].y) - (polygon[i][j-1].y * polygon[i][j].x);
            }
            if (tmp < 0) tmp = -tmp;
            area.pb({tmp, i});
        }

        sort(area.begin(), area.end(), comp);

        vector <int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            ans[area[i].y] = i;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }


    return 0;
}





