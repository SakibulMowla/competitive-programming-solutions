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

    int r, c;
    scanf("%d %d", &r, &c);

    vector < vector <int> > a(r + 1, vector <int> (c + 1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector < vector <int> > sum(r + 1, vector <int> (c + 1, 0));
    for (int i = 1; i <= r; i++) {
        for (int j = 1, tmp = 0; j <= c; j++) {
            tmp += a[i][j];
            sum[i][j] = tmp + sum[i-1][j];
        }
    }

    int q;
    scanf("%d", &q);

    for (int cs = 0; cs < q; cs++) {
        int x, y;
        scanf("%d %d", &x, &y);

        vector < vector <int> > row(r + 1, vector <int> (c + 1));
        for (int i = 1; i <= r; i++) {
            deque < pair<int, int> > window;
            for (int j = 1; j <= c; j++) {
                while (!window.empty() && window.back().first <= a[i][j])
                    window.pop_back();
                window.push_back({a[i][j], j});

                while(window.front().second <= j - y)
                    window.pop_front();

                if (j >= y)
                    row[i][j - y + 1] = window.front().first;
            }
        }

        int ans = numeric_limits <int> :: max();

        for (int j = 1; j + y - 1 <= c; j++) {
            deque < pair<int, int> > window;
            for (int i = 1; i <= r; i++) {
                while (!window.empty() && window.back().first <= row[i][j])
                    window.pop_back();
                window.push_back({row[i][j], i});

                while(window.front().second <= i - x)
                    window.pop_front();

                if (i >= x) {
                    int p = x * y * window.front().first;

                    int rb = i - x + 1;
                    int re = i;
                    int cb = j;
                    int ce = j + y - 1;

                    int q = sum[re][ce] - sum[rb-1][ce] - sum[re][cb-1] + sum[rb-1][cb-1];

                    ans = min(ans, p - q);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}





