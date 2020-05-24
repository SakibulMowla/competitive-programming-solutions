#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1E7;
const ll mod = 1LL;

#define SZ 20
#define SZ1 75000

bool chk(int n){
    return (n>=0 && n<=3600);
}

int convert (int n) {
    if (n < 0) n = 0;
    if (n > 3600) n = 3600;
    return n;
}

int dp[SZ1+10];
int coin[SZ];

queue <int> Q;

void BFS (int n) {
    while (!Q.empty()) Q.pop();
    Q.push(0);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < n; i++) {
            int v = u + coin[i];
            v = convert(v);
            if(dp[v] > dp[u] + 1) {
                dp[v] = 1 + dp[u];
                Q.push(v);
            }
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, val;
        scanf("%d %d", &n, &val);

        for (int i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
        }

        if(val == 0) {
            printf("0 0\n");
            continue;
        }

        sort(coin, coin+n);
        reverse(coin, coin+n);

        dp[0] = 0;
        for (int i = 1; i <= SZ1; i++) {
            dp[i] = inf;
        }

        BFS(n);

        int ans1, ans2;
        for (int i = val; i <= SZ1; i++) {
            if(dp[i] != inf) {
                ans1 = dp[i];
                ans2 = i - val;
                break;
            }
        }

        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}









