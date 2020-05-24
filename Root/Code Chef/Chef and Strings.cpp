#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

#define SZ 1000010

char s[SZ];
ll a[4][SZ];
ll b[4][4];
ll d[4][4][SZ];
ll e[4][4][SZ];

inline int cal (char c) {
    if (c == 'c') return 0;
    if (c == 'h') return 1;
    if (c == 'e') return 2;
    if (c == 'f') return 3;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    scanf("%s", s + 1);
    int n = strlen(s + 1);

    for (register int i = 1; i <= n; i++) {
        a[0][i] = a[0][i-1];
        a[1][i] = a[1][i-1];
        a[2][i] = a[2][i-1];
        a[3][i] = a[3][i-1];
        if (s[i] == 'c') a[0][i]++;
        else if (s[i] == 'h') a[1][i]++;
        else if (s[i] == 'e') a[2][i]++;
        else a[3][i]++;
    }

    for (register int i = 0; i < 4; i++) {
        for (register int j = 0; j < 4; j++) if (i != j) {
            for (register int k = 1; k <= n; k++) {
                e[i][j][k] = e[i][j][k-1];
                if ((i == 0 && s[k] == 'c') || (i == 1 && s[k] == 'h') || (i == 2 && s[k] == 'e') || (i == 3 && s[k] == 'f')) {
                    b[i][j] += a[j][n] - a[j][k];
                }
                if ((j == 0 && s[k] == 'c') || (j == 1 && s[k] == 'h') || (j == 2 && s[k] == 'e') || (j == 3 && s[k] == 'f')) {
                    e[i][j][k] += a[i][k-1];
                }
            }
            for (register int k = n; k >= 1; k--) {
                d[i][j][k] = d[i][j][k+1];
                if ((i == 0 && s[k] == 'c') || (i == 1 && s[k] == 'h') || (i == 2 && s[k] == 'e') || (i == 3 && s[k] == 'f')) {
                    d[i][j][k] += a[j][n] - a[j][k];
                }
            }
        }
    }

    int qq;
    scanf("%d", &qq);

    while (qq--) {
        char c1, c2;
        int l, r;
        scanf(" %c %c", &c1, &c2);
        inp(l);
        inp(r);
        int p = cal(c1);
        int q = cal(c2);

        ll ans = b[p][q];
        ans -= a[p][l-1] * (a[q][r] - a[q][l-1]);
        ans -= (a[p][r] - a[p][l-1]) * (a[q][n] - a[q][r]);
        ans -= a[p][l-1] * (a[q][n] - a[q][r]);
        ans -= e[p][q][l-1];
        ans -= d[p][q][r+1];

        printf("%lld\n", ans);
    }

    return 0;
}






