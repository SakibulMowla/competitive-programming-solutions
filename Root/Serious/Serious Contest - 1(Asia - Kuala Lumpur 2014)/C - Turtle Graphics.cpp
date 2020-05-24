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

struct data {
    int x, y, f;
};

int grid[510][510];
int cnt;

void _move (data &a, char ch) {
    if (ch == 'F') {
        if (a.f == 0) {
            a.y++;
        } else if (a.f == 1) {
            a.x++;
        } else if (a.f == 2) {
            a.y--;
        } else if (a.f == 3) {
            a.x--;
        }
        grid[a.x][a.y]++;
        if (grid[a.x][a.y] == 2) {
            cnt++;
        }
    } else if (ch == 'R') {
        if (a.f == 0) a.f = 1;
        else if (a.f == 1) a.f = 2;
        else if (a.f == 2) a.f = 3;
        else if (a.f == 3) a.f = 0;
    } else if (ch == 'L') {
        if (a.f == 0) a.f = 3;
        else if (a.f == 1) a.f = 0;
        else if (a.f == 2) a.f = 1;
        else if (a.f == 3) a.f = 2;
    }
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
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;

        mem(grid, 0);
        x += 128;
        y += 128;
        grid[x][y]++;
        data a;
        a.x = x;
        a.y = y;
        a.f = 0;

        cnt = 0;
        for (int i = 0; i < sz(s); i++) {
            _move(a, s[i]);
        }

        cout << "Case #" << cs + 1 << ": " << a.x-128 << " " << a.y-128 << " " << cnt << endl;
    }


    return 0;
}







