#include "bits/stdc++.h"

using namespace  std;

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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

int grid[SZ][SZ];
string s;
int lastx, lasty;

int new_face (int face, char now) {
    if (face == 0) {
        if (now == 'R') face = 2; else face = 3;
    } else if (face == 1) {
        if (now == 'R') face = 3; else face = 2;
    } else if (face == 2) {
        if (now == 'R') face = 1; else face = 0;
    } else if (face == 3) {
        if (now == 'R') face = 0; else face = 1;
    }
    return face;
}

pii co_ordinate (pii p, int face) {
    if (face == 0) p.Y++;
    else if (face == 1) p.Y--;
    else if (face == 2) p.X++;
    else if (face == 3) p.X--;
    return p;
}

void dfs (int x, int y, int face, int pos) {
//    printf("%d %d %d\n", x, y, pos);
    lastx = x, lasty = y;
    grid[x][y]++;
    while (pos < sz(s) && (s[pos] == 'R' || s[pos] == 'L')) {
        face = new_face(face, s[pos]);
        pos++;
    }
    if (pos < sz(s)) {
        pii p = co_ordinate(MP(x, y), face);
        dfs(p.X, p.Y, face, pos+1);
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int x, y;
        cin >> x >> y >> s;

        mem(grid, 0);
        int cnt = 0;

        dfs(x, y, 0, 0);

        for (int i = 0; i < 70; i++)
            for (int j = 0; j < 70; j++)
                if (grid[i][j] > 1)
                    cnt++;

        cout << "Case #" << cs+1 << ": " << lastx << " " << lasty << " " <<  cnt << '\n';
    }

    return 0;
}







