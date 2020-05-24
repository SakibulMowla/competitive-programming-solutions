#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

//#include <bits/stdc++.h>

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
const ll mod = 1LL;

#define SZ  1000010

//bool arr[SZ];
bool ok[SZ];

//bool palin(int n) {
//    char s[8];
//    int len = sprintf(s, "%d", n);
//    for (int i = 0; i < len/2; i++) {
//        if(s[i] != s[len-i-1])
//            return 0;
//    }
//    return 1;
//}
//
//void sieve () {
//    for (int i = 3; i <= 1E6; i+=2)
//        if(!arr[i])
//            for (ll j = (ll)i*(ll)i; j <= 1E6; j += i+i)
//                arr[j] = 1;
//    ok[1] = ok[2] = 1;
//    for (int i = 3; i <= 1E6; i+=2)
//        if(!arr[i] && palin(i))
//        {
//            ok[i] = 1;
//            printf("%d\n", i);
//        }
//    return;
//}



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ok[1] = 1;ok[3] = 1;ok[5] = 1;ok[7] = 1;ok[11] = 1;ok[101] = 1;ok[131] = 1;ok[151] = 1;ok[181] = 1;ok[191] = 1;ok[313] = 1;ok[353] = 1;ok[373] = 1;ok[383] = 1;ok[727] = 1;ok[757] = 1;ok[787] = 1;ok[797] = 1;ok[919] = 1;ok[929] = 1;ok[10301] = 1;ok[10501] = 1;ok[10601] = 1;ok[11311] = 1;ok[11411] = 1;ok[12421] = 1;ok[12721] = 1;ok[12821] = 1;ok[13331] = 1;ok[13831] = 1;ok[13931] = 1;ok[14341] = 1;ok[14741] = 1;ok[15451] = 1;ok[15551] = 1;ok[16061] = 1;ok[16361] = 1;ok[16561] = 1;ok[16661] = 1;ok[17471] = 1;ok[17971] = 1;ok[18181] = 1;ok[18481] = 1;ok[19391] = 1;ok[19891] = 1;ok[19991] = 1;ok[30103] = 1;ok[30203] = 1;ok[30403] = 1;ok[30703] = 1;ok[30803] = 1;ok[31013] = 1;ok[31513] = 1;ok[32323] = 1;ok[32423] = 1;ok[33533] = 1;ok[34543] = 1;ok[34843] = 1;ok[35053] = 1;ok[35153] = 1;ok[35353] = 1;ok[35753] = 1;ok[36263] = 1;ok[36563] = 1;ok[37273] = 1;ok[37573] = 1;ok[38083] = 1;ok[38183] = 1;ok[38783] = 1;ok[39293] = 1;ok[70207] = 1;ok[70507] = 1;ok[70607] = 1;ok[71317] = 1;ok[71917] = 1;ok[72227] = 1;ok[72727] = 1;ok[73037] = 1;ok[73237] = 1;ok[73637] = 1;ok[74047] = 1;ok[74747] = 1;ok[75557] = 1;ok[76367] = 1;ok[76667] = 1;ok[77377] = 1;ok[77477] = 1;ok[77977] = 1;ok[78487] = 1;ok[78787] = 1;ok[78887] = 1;ok[79397] = 1;ok[79697] = 1;ok[79997] = 1;ok[90709] = 1;ok[91019] = 1;ok[93139] = 1;ok[93239] = 1;ok[93739] = 1;ok[94049] = 1;ok[94349] = 1;ok[94649] = 1;ok[94849] = 1;ok[94949] = 1;ok[95959] = 1;ok[96269] = 1;ok[96469] = 1;ok[96769] = 1;ok[97379] = 1;ok[97579] = 1;ok[97879] = 1;ok[98389] = 1;ok[98689] = 1;

    int n;
    while(1) {
        inp(n);
        printf("%d\n", 2*n);
        if(ok[n]) break;
    }

    return 0;
}













