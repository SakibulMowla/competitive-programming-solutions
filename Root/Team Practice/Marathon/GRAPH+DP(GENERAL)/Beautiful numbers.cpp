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

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define SZ  20

ll dp[SZ][48][2520]; /// indx, flag, LCM, mod by LCM(8, 9, 5, 7)
int num[SZ];
int len;

void init(ll n) {
    len = 0;
    while(n) {
        num[len++] = n%10;
        n /= 10;
    }
//    reverse(num, num+len);
    return;
}

int mp[2530];

void prepare() {
    int k = -1;
    for(int i = 1; i <= 2520; i++) {
        if(2520 % i == 0)
            k++;
        mp[i] = k;
    }
    return;
}

///iterating index through len-1 to -1 so that it can be memoized
///if it was iterated 0 to len-1 it couldn't be memoized because len is different for different numbers

ll solve(int indx, int flag, int lcm, int rem) {
    if(indx == -1)
        return (ll)(rem % lcm == 0);

    if(flag == 0 && dp[indx][ mp[lcm] ][rem] != -1)
        return dp[indx][ mp[lcm] ][rem];

    ll ret = 0LL;
    int lim = flag ? num[indx] : 9;

    for(int i = 0; i <= lim; i++) {
        ret += solve(indx-1, (flag&&i==lim), i ? lcm/__gcd(lcm, i)*i : lcm, (rem*10+i)%2520); /// 8 * 9 * 5 * 7 = 2520
    }

    return flag ? ret : dp[indx][ mp[lcm] ][rem] = ret;
}

ll calc(ll n) {
    init(n);
    return solve(len-1, 1, 1, 0);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    prepare();
    mem(dp, -1);

    int t;
    ll n, m;

    scanf("%d", &t);

    while(t--) {
        scanf("%I64d %I64d", &n, &m);
        printf("%I64d\n", calc(m) - calc(n-1));
    }

    return 0;
}








