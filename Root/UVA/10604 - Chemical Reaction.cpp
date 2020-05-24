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

#define SZ 11

struct data {
    int cm;
    ll ht;
};

data mat[6][6];

int now;
int col[SZ][SZ][SZ][SZ][SZ][SZ];
ll dp[SZ][SZ][SZ][SZ][SZ][SZ];
int m;

int aa[6];

ll solve (int a, int b, int c, int d, int e, int f) {
    ll &ret = dp[a][b][c][d][e][f];
    if (col[a][b][c][d][e][f] == now) return ret;
    col[a][b][c][d][e][f] = now;
    if (a + b + c + d + e + f == 1) return ret = 0;

    ret = numeric_limits <ll>::max();
    ret = 1E15;

    for (int i = 0; i < 6; i++) if (aa[i]) {
        aa[i]--;
        for (int j = 0; j < 6; j++) if (aa[j]) {
            aa[j]--;
            aa[mat[i][j].cm]++;
            ret = min(ret, mat[i][j].ht + solve(aa[0], aa[1], aa[2], aa[3], aa[4], aa[5]));
            aa[mat[i][j].cm]--;
            aa[j]++;
        }
        aa[i]++;
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d %lld", &mat[i][j].cm, &mat[i][j].ht);
                mat[i][j].cm--;
            }
        }

        mem(aa, 0);

        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int b;
            scanf("%d", &b);
            aa[--b]++;
        }

        now++;
        printf("%lld\n", solve(aa[0], aa[1], aa[2], aa[3], aa[4], aa[5]));

        char ch;
        scanf(" %c", &ch);
    }


    return 0;
}







