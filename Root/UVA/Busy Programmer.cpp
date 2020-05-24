#include <stdio.h>
#include <string.h>

typedef long long ll;

#define SZ 34

ll dp[SZ][SZ][SZ][2][2];


ll solve(int wrk1, int wrk2, int g, int strt, int now){
    ll &ret = dp[wrk1][wrk2][g][strt][now];
    if(ret != -1) return ret;

    if(!wrk1 && !wrk2) return (ll)(strt==now);

    int i;
    ret = 0LL;

    if(wrk1 == 0 && now==1) for(i=1; i<=wrk2; i++) ret += solve(wrk1, wrk2-i, g, strt, !now);
    else if(wrk2 == 0 && now==0) for(i=1; i<=wrk1; i++) ret += solve(wrk1-i, wrk2, g, strt, !now);
    else if(!now) for(i=1; i<=g && wrk1-i>=0; i++) ret += solve(wrk1-i, wrk2, g, strt, !now);
    else for(i=1; i<=g && wrk2-i>=0; i++) ret += solve(wrk1, wrk2-i, g, strt, !now);

    return ret;
}


int main() {
    memset(dp, -1, sizeof(dp));
    int test=0, D, G;

    while(scanf("%d %d",&D,&G) == 2){
        if(D==-1 && G==-1) break;
        if(D == 0) printf("Case %d: 1\n",++test);
        else if(G == 0) printf("Case %d: 0\n",++test);
        else printf("Case %d: %lld\n",++test, solve(D, D, G, 0, 0)+solve(D, D, G, 1, 1));
    }


    return 0;
}













