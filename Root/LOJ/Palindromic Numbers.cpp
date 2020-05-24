#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define mem(a,b) memset(a, b, sizeof(a))


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 20

int len;
int num[SZ];

void prepare(ll n) {
    len = 0;
    if(!n) {
        num[len++] = n;
        return;
    }
    while(n) {
        num[len++] = n % 10;
        n /= 10;
    }
    reverse(num, num+len);
    return;
}

ll dp[SZ][2][2];

ll solve(int indx, int flag, int flag2) {
    if(indx == (len/2)+(len%2)) {
        if(flag == 0 || flag2 == 0)
            return 1LL;
        return 0LL;
    }

    ll &ret = dp[indx][flag][flag2];
    if(ret != -1) return ret;

    int i, strt, lim, nflag, nflag2;

    ret = 0;
    lim = flag ? num[indx] : 9;
    strt = ( (indx != 0) || (indx == 0 && len == 1) ) ? 0 : 1;

    for(i = strt; i <= lim; i++) {
        /// First Flagging
        if(flag == 1 && i == num[indx]) nflag = 1;
        else nflag  = 0;

        /// Second Flagging
        if(i > num[len-indx-1]) nflag2 = 1;
        else if(i < num[len-indx-1]) nflag2 = 0;
        else nflag2 = flag2;

        ret += solve(indx+1, nflag, nflag2);
    }

    return ret;
}

ll store[SZ];

ll calc(ll n) {
    if(n < 0) return 0LL;

    prepare(n);
    mem(dp, -1);

    ll ans = solve(0, 1, 0);
//    printf("n = %lld ans = %lld\n", n, ans);

    for(int i = 1; i < len; i++)
        ans += store[i];

    return ans;
}

void pre_calculate() {
    int i;
    store[0] = 0;

    for(i = 1; i<= 18; i++) {
        mem(dp, -1);
        num[i-1] = 9;
        len = i;
        store[i] = solve(0, 1, 0);
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    pre_calculate();

    int test=0, t;
    ll n, m;

    scanf("%d",&t);

    while(t--){
        scanf("%lld %lld",&n,&m);
        if(n > m) swap(n, m);
        printf("Case %d: %lld\n", ++test, calc(m)-calc(n-1));
    }

    return 0;
}








