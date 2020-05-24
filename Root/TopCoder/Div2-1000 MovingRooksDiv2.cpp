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

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 16777216+10

int eight[12];
int ans, N;
int dp[SZ];

void init(){
    int i;
    eight[0] = 1;
    REP1(i, 1, 10)
        eight[i] = 8 * eight[i-1];
}

int get_bit(int mask, int pos){
    return (mask / eight[pos]) % 8;
}

int set_bit(int mask, int pos, int bit){
    int tmp =(mask / eight[pos]) % 8;
    mask -= tmp * eight[pos];
    mask += bit * eight[pos];
    return mask;
}

int solve(int mask){
//    printf("mask %d\n",mask);
    if(mask == ans) return 1;
    int &ret = dp[mask];
    if(~ret) return ret;

    int i, j, c1, c2, tmp;
    ret = 0;

    REP(i, N){
        c1 = get_bit(mask, i);
        bool f = 0;
        for(j=i+1; j<N; j++){
            c2 = get_bit(mask, j);
            if(c1 > c2){
                tmp = mask;
                tmp = set_bit(tmp, i, c2);
                tmp = set_bit(tmp, j, c1);
                ret = max(ret, solve(tmp));
                f = 1;
            }
        }
//        if(f) break;
    }

    return ret;
}

class MovingRooksDiv2 {
public:
	string move(vector <int> Y1, vector <int> Y2) {
        init();

        int i, mask = 0;
        ans = 0;

        N = sz(Y1);
        REP(i, N){
            ans = set_bit(ans, i, Y2[i]);
            mask = set_bit(mask, i, Y1[i]);
        }

//        printf("ANS %d %d %d\n",ans,get_bit(ans, 0),get_bit(ans, 1));

        mem(dp, -1);
        mask = solve(mask);

        if(mask) return "Possible";
        return "Impossible";
	}
};
