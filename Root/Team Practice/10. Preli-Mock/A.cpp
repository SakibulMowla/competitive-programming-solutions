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

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 100007LL;

#define SZ  1010


int cnt[2][30];
char txt[1010], pat[1010];

ll nCr[SZ][SZ];
ll fact[SZ];

void pre() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) nCr[i][j] = 1LL;
            else if(i == j) nCr[i][j] = 1LL;
            else if(j == 1) nCr[i][j] = i % mod;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % mod;
        }
    }
    fact[0] = 1LL;
    for (int i = 1; i < 1001; i++) {
        fact[i] = ((ll)i * fact[i-1]) % mod;
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    pre();

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf(" %s %s", txt, pat);
        int len1 = strlen(txt), len2 = strlen(pat);

        mem(cnt, 0);
        for (int i = 0; i < len1; i++) {
            cnt[0][txt[i]-'A']++;
        }
        for (int i = 0; i < len2; i++) {
            cnt[1][pat[i]-'A']++;
        }

        bool f = 1;
        for (int i = 0; i < len2; i++) {
            if(cnt[0][ pat[i]-'A' ] < cnt[1][ pat[i]-'A' ]) {
                f = 0;
                break;
            }
        }

        if(!f) {
            printf("HERE\n");
            printf("Case %d: 0\n", cs+1);
            continue;
        }

        ll ans = ( nCr[len1][len2] * fact[len1-len2+1] ) % mod;
        printf("%lld %lld\n", nCr[len1][len2], fact[len1-len2+1]);
        printf("Case %d: %lld\n", cs+1, ans);
    }

    return 0;
}












