#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000009LL;

#define SZ 520

ll dp[10][SZ][SZ];
ll ncr[SZ][SZ];

void pre(){
    int i, j;
    for(i=0; i<=512; i++){
        for(j=0; j<=i; j++){
            if(i == j) ncr[i][j] = 1LL;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
        }
    }
}

ll solve(int k, int indx, int rem){
    if(rem == 0) return 1LL;
    if(indx == 0) return 0LL;

    ll &ret = dp[k][indx][rem];
    if(~ret) return ret;

    int i, j;
    ret = 0LL;

    for(i=0; i<=min(rem,k); i++){
        ret = (ret + ( ncr[rem][i] * solve(k, indx-1, rem-i) ) % mod )  % mod;
    }

    return ret;
}

int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    pre();
    memset(dp, -1, sizeof(dp));

    int test=0, t, i, j, k, n, m, d, pre, now;
    ll ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&d,&k);
        ans = 1;

        scanf("%d", &pre);

        ans = 1LL;
        for(i=0; i<d; i++){
            scanf("%d",&now);
            ans = (ans * solve(k, pre, now)) % mod;
            pre = now;
        }

        printf("Case %d: %lld\n",++test,ans);
    }

    return 0;
}

