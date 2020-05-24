#include <bits/stdc++.h>

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  210

int mat[SZ][SZ];
int col[20][2];

void pre () {
    col['A'][0] = 0, col['A'][1] = 5;
    col['B'][0] = 1, col['B'][1] = 6;
    col['C'][0] = 2, col['C'][1] = 7;
    col['D'][0] = 3, col['D'][1] = 8;
    col['E'][0] = 4, col['E'][1] = 9;
    mat[0]['A'] = 5, mat[0]['E'] = 4, mat[0]['B'] = 1;
    mat[1]['A'] = 0, mat[1]['B'] = 6, mat[1]['C'] = 2;
    mat[2]['B'] = 1, mat[2]['C'] = 7, mat[2]['D'] = 3;
    mat[3]['C'] = 2, mat[3]['D'] = 8, mat[3]['E'] = 4;
    mat[4]['D'] = 3, mat[4]['E'] = 9, mat[4]['A'] = 0;
    mat[5]['A'] = 0, mat[5]['C'] = 7, mat[5]['D'] = 8;
    mat[6]['B'] = 1, mat[6]['D'] = 8, mat[6]['E'] = 9;
    mat[7]['A'] = 5, mat[7]['C'] = 2, mat[7]['E'] = 9;
    mat[8]['A'] = 5, mat[8]['B'] = 6, mat[8]['D'] = 3;
    mat[9]['B'] = 6, mat[9]['C'] = 7, mat[9]['E'] = 4;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    mem(mat, -1);
    pre();

    string s, ans1, ans2;
    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> s;

        bool f1 = 1, f2 = 1;
        ans1 = ""; ans2 = "";

        int pre = col[s[0]][0];
        ans1 += char(pre+'0');
        for (int i = 1; i < sz(s); i++) {
            if (mat[pre][s[i]] != -1) {
                pre = mat[pre][s[i]];
                ans1 += char(pre+'0');
            } else {
                f1 = 0;
                break;
            }
        }

        pre = col[s[0]][1];
        ans2 += char(pre+'0');
        for (int i = 1; i < sz(s); i++) {
            if (mat[pre][s[i]] != -1) {
//                printf("pre = %d\n", pre);
                pre = mat[pre][s[i]];
//                printf(">>pre = %d\n", pre);
                ans2 += char(pre+'0');
            } else {
                f2 = 0;
                break;
            }
        }

        if (f1 == 0 && f2 == 0) cout << "-1\n";
        else if (f1 == 0) cout << ans2 << '\n';
        else if (f2 == 0) cout << ans1 << '\n';
        else {
            if (ans1[0] > ans2[0]) swap(ans1, ans2);
            cout << ans1 << '\n';
        }
    }

    return 0;
}




