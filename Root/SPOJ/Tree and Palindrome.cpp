#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define pb push_back

template <class T> inline T gcd(T a, T b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

#define SZ 100010

vector <int>adj[SZ];
ll cnt[SZ];
int maxlvl;

void dfs(int u, int p, int lvl) {
    cnt[lvl]++;
    maxlvl = max(maxlvl, lvl);
    int i, j, k;
    k = sz(adj[u]);
    REP(i, k) {
        j = adj[u][i];
        if(j != p) dfs(j, u, lvl+1);
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int n, i, j, k;
    ll p, q, d;

    while(scanf("%d",&n) == 1) {
        REP1(i, 0, n){
            clr(adj[i]);
            cnt[i] = 0;
        }

        REP(i, n-1) {
//            scanf("%d %d",&j,&k);
            inp(j);
            inp(k);
            adj[j].pb(k);
            adj[k].pb(j);
        }

        p = 0;
        maxlvl = 0;
        dfs(1, -1, 0);

        p = 0LL;
        REP(i, maxlvl+1)
        p += (cnt[i]*(cnt[i]-1)) >> 1LL;

        q = ((ll)n*(ll)(n-1))>>1LL;
        d = gcd(p, q);

        printf("%lld/%lld\n",p/d, q/d);
    }

    return 0;
}












