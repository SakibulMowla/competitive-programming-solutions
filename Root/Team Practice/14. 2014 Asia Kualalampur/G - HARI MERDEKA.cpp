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
const int inf = 1E9;
const ll mod = 1LL;

void failure (int);
void kmp (int x, int y);

#define SZ  210

vector <string> a(SZ);
int par[SZ][SZ];
int match[SZ][SZ];
int val[SZ];
int dp[SZ][SZ];
int char_cost[500];
int m;

int calc_cost (string &a){
    int sum = 0;
    for (int i = 0; i < sz(a); i++)
        sum += char_cost[a[i]];
    return sum;
}

int solve (int pre, int budget) {
    int &ret = dp[pre][budget];
    if(ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < m; i++) {
        int tmp = match[pre][i+1];
        string ss = a[i+1].substr(tmp);
        if(budget - calc_cost(ss) >= 0) {
            ret = max(ret, val[i+1] + solve(i+1, budget - calc_cost(ss)));
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, b;
        cin >> n >> m >> b;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            cin >> char_cost[c];
        }

        for (int i = 0; i < m; i++) {
            cin >> a[i+1] >> val[i+1];
        }

        for (int i = 0; i < m; i++) {
            failure(i+1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                kmp(i+1, j+1);
                cout << a[i+1] << " " << a[j+1] << " " << match[i+1][j+1] << '\n';
            }
            cout << ">>" << a[i+1] << " " << val[i+1] << '\n';
        }

        mem(dp, -1);
        cout << solve(0, b) << '\n';
    }

    return 0;
}


void failure (int x) {
    par[x][0] = 0;
    int k = 0;
    for (int i = 1; i < sz(a[x]); i++) {
        while (k > 0 && a[x][i] != a[x][k])
            k = par[x][k-1];
        if (a[x][i] == a[x][k])
            k++;
        par[x][i] = k;
    }
    return;
}

void kmp (int x, int y) {
    if (x == y) {
        match[x][y] = par[x][ sz(a[x])-1 ];
        return;
    }

    int k = 0;
    int cnt = 0;

    for (int i = 0; i < sz(a[x]); i++) {
        while (k > 0 && a[x][i] != a[y][k])
            k = par[y][k-1];
        if (a[x][i] == a[y][k])
            k++;
        if(k == sz(a[y])) {
            cnt++;
            k = par[y][k-1];
        }
    }

    val[x] += cnt * val[y];
    match[x][y] = k;
    return;
}
