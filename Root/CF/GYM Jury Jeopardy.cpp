#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<pii , int> piii;

#define SZ 310

piii getDir (int now, char ch, pii p) {
    if(now == 1) {
        if(ch == 'R') now = 2, p.X += 1, p.Y += 0;
        else if(ch == 'L') now = -2, p.X += -1, p.Y += 0;
        else if(ch == 'F') now = 1, p.X += 0, p.Y += 1;
        else if(ch == 'B') now = -1, p.X += 0, p.Y += -1;
    } else if(now == -1) {
        if(ch == 'R') now = -2, p.X += -1, p.Y += 0;
        else if(ch == 'L') now = 2, p.X += 1, p.Y += 0;
        else if(ch == 'F') now = -1, p.X += 0, p.Y += -1;
        else if(ch == 'B') now = 1, p.X += 0, p.Y += 1;
    } else if(now == 2) {
        if(ch == 'R') now = -1, p.X += 0, p.Y += -1;
        else if(ch == 'L') now = 1, p.X += 0, p.Y += 1;
        else if(ch == 'F') now = 2, p.X += 1, p.Y += 0;
        else if(ch == 'B') now = -2, p.X += -1, p.Y += 0;
    } else {
        if(ch == 'R') now = 1, p.X += 0, p.Y += 1;
        else if(ch == 'L') now = -1, p.X += 0, p.Y += -1;
        else if(ch == 'F') now = -2, p.X += -1, p.Y += 0;
        else if(ch == 'B') now = 2, p.X += 1, p.Y += 0;
    }
    return MP(p, now);
}

char a[SZ][SZ];
string s;
int N;

void dfs (int pos, int now, pii p) {
    a[p.X][p.Y] = '.';
    if(pos == N) return;

    piii nxt = getDir(now, s[pos], p), tmp;

    if(s[pos] == 'R') return dfs(pos+1, nxt.Y, nxt.X);

    tmp = getDir(now, 'R', p);
    a[tmp.X.X][tmp.X.Y] = '#';

    if(s[pos] == 'F') return dfs(pos+1, nxt.Y, nxt.X);

    tmp = getDir(now, 'F', p);
    a[tmp.X.X][tmp.X.Y] = '#';

    if(s[pos] == 'L') return dfs(pos+1, nxt.Y, nxt.X);

    tmp = getDir(now, 'L', p);
    a[tmp.X.X][tmp.X.Y] = '#';

    return dfs(pos+1, nxt.Y, nxt.X);
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    FAST
    int t;
    cin >> t;
    cout << t << '\n';

    for (int cs = 0; cs < t; cs++) {
        cin >> s;
        N = sz(s);
        for (int i = 0; i < 300; i++) for (int j = 0; j < 300; j++) a[i][j] = '@';
        dfs(0, 1, MP(100, 0));

        int mxr = 0, mxc = 0;
        int mnr = 300, mnc = 300;

        for (int i = 0; i < 300; i++) for (int j = 0; j < 300; j++) if(a[i][j] == '.' || a[i][j] == '#') {
            mxr = max(mxr, i);
            mxc = max(mxc, j);
            mnr = min(mnr, i);
            mnc = min(mnc, j);
        }

        cout << (mxr-mnr+1) << ' ' << (mxc-mnc+1) << '\n';
        for (int i = mnr; i <= mxr; i++) {
            for (int j = mnc; j <= mxc; j++) {
                if(a[i][j] == '@') cout << '#';
                else cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}



