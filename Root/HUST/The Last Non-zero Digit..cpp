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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


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

ll BigMod(ll B,ll P,ll M) {
    ll R=1%M;
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ  20000010
#define SZ1  2000010

bool arr[SZ];
int prime[SZ1];
int cnt;

void sieve() {
    int i, j, k;

    k = sqrt(SZ);

    for(i=3; i<=k; i+=2)
        if(!arr[i])
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;

    cnt = 0;
    prime[cnt++] = 2;

    for(i=3; i<SZ; i+=2)
        if(!arr[i])
            prime[cnt++] = i;
}

int occur(int num, int div) {
    int cnt = 0;

    while(num >= div) {
        cnt += num / div;
        num /= div;
    }

    return cnt;
}

int main() {
#if defined JESI
//    freopen("1.txt","r",stdin);
//    freopen("myout.txt","w",stdout);
#endif // defined

    sieve();

    int i, n, r, ans, tmp;

    while(scanf("%d %d",&n,&r) == 2) {
        ans = 1;

        for(i=0; i<cnt && prime[i]<=n; i++) {
            if(prime[i] == 2 || prime[i] == 5) continue;
            ans = (ans * BigMod(prime[i], occur(n, prime[i])-occur(n-r, prime[i]), 10) ) % 10;
        }

        tmp = (occur(n, 2) - occur(n-r, 2)) - (occur(n, 5) - occur(n-r, 5));
        if(tmp > 0) ans = (ans * BigMod(2, tmp, 10)) % 10;
        else if(tmp < 0) ans = (ans * BigMod(5, -tmp, 10)) % 10;

        printf("%d\n",ans);
    }

    return 0;
}



/*
5 1
ans = 5
*/








