#include <bits/stdc++.h>

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

#define SZ  110

int dp[4097][281][4];
int col[4097][281][4];
int a[3][12];
int cnt;

int solve(int mask, int left, int last, int n) {
    if (mask == 0) return 0;
    int &ret = dp[mask][left][last];
    if (col[mask][left][last] == cnt) return ret;
    col[mask][left][last] = cnt;

    ret = 0;
    for (int i = 0; i < 3; i++) if (i != last) {
        for (int j = 0; j < n; j++) if ((mask >> j) & 1) {
            if (left - a[i][j] >= 0) {
                ret = max(ret, 1 + solve(mask & ~(1 << j), left - a[i][j], i, n));
            }
        }
    }

    return ret;
}

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
//    cin >> t;
    inp(t);

    for (int cs = 0; cs < t; cs++) {
        int n;
//        cin >> n;
        inp(n);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
//                cin >> a[i][j];
                inp(a[i][j]);
            }
        }

        ++cnt;
        printf("%d\n", solve((1 << n) - 1, 280, 3, n));
    }

    return 0;
}

