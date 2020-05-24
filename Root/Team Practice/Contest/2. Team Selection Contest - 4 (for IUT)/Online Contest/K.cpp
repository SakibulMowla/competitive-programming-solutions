#include <cstdio>
#include <vector>
#include <algorithm>

#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(a) ((int)(a).size())
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

int t, n;
VVI v;
VI x;

int dfs(int u, int p) { // busyness, total node
    int a = 0, a2 = 0;
    for(int i = 0; i < sz(v[u]); i++) if(v[u][i] != p) {
        int tmp = dfs(v[u][i], u);
        a += tmp;
        a2 += tmp * tmp;
    }
    int b = n - a - 1;
    x[u] = (a + b) * (a + b) - (a2 + b * b);
    return a + 1;
}

int main() {
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        v = VVI(n);
        x = VI(n);
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[a-1].pb(b-1);
            v[b-1].pb(a-1);
        }
        dfs(0, -1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, x[i]);
        }
        printf("Case #%d: %d\n", cs, ans / 2);
    }

    return 0;
}
