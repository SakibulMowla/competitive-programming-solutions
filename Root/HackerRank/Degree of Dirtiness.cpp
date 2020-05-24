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

#define SZ 50010

int col[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        mem(col, 0);

        if (n == 1) {
            cout << 1 << " " << m - 1 << endl;
        } else if (m & 1) {
            int lft = 0, rht = n + 1;
            col[lft] = col[rht] = 1;
            for (int i = 0; i < (m - 1) / 2; i++) {
                if (col[lft+1] < col[lft]) {
                    col[lft+1]++;
                    lft++;
                } else {
                    lft = 1;
                    col[lft]++;
                }
                if (col[rht-1] < col[rht]) {
                    rht--;
                    col[rht]++;
                } else {
                    rht = n;
                    col[rht]++;
                }
            }
            if (col[lft+1] < col[lft]) {
                col[lft+1]++;
                lft++;
            } else {
                lft = 1;
                col[lft]++;
            }
            cout << lft << " " << col[lft] - 1 << endl;
        } else {
            int lft = 0, rht = n + 1;
            col[lft] = col[rht] = 1;
            for (int i = 0; i < m / 2; i++) {
                if (col[lft+1] < col[lft]) {
                    col[lft+1]++;
                    lft++;
                } else {
                    lft = 1;
                    col[lft]++;
                }
                if (col[rht-1] < col[rht]) {
                    rht--;
                    col[rht]++;
                } else {
                    rht = n;
                    col[rht]++;
                }
            }
            cout << rht << " " << col[rht] - 1 << endl;
        }
    }


    return 0;
}







