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
#define SZ1 300010

vector <int> g[SZ];
vector <string> edge[SZ];
char pat[SZ1];
char s[SZ1];
int len;
int par[SZ1];
int dp[SZ1][26];

void pre_process(int n) {
    int i, k;

    k = 0;
    par[0] = 0;

    for(i=1; i<n; i++) {
        while(k>0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }
    return;
}

int track (int k, char c) {
    int &ret = dp[k][c-'a'];
    if (ret != -1) return ret;

    while(k > 0 && c != pat[k])
        k = par[k-1];
    if(c == pat[k])
        k++;

    return ret = k;
}

int dfs (int v, int p, int mtch) { //node, parent, match
    int ans = 0;
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u != p) {
            int k = mtch;
            for (int j = 0; j < sz(edge[v][i]); j++) {
                k = track(k, edge[v][i][j]);
                if(k == len) {
                    ans++;
                    k = par[k-1];
                }
            }
            ans += dfs(u, v, k);
        }
    }
    return ans;
}



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int n;
//    cin >> n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d %s", &p, s);
        g[p].pb(i);
        edge[p].pb(s);
    }

    scanf("%s", pat);
    len = strlen(pat);
    pre_process(len);
    memset(dp, -1, sizeof dp);

    cout << dfs(1, 1, 0) << endl;

    return 0;
}





