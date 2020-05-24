#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;

#define SZ 1010

ll mot , n , t[110] , w[110];
ll dp[110][220];

ll solve(ll indx,ll thic,ll ache)
{
    if(indx == n)
    {
        if(thic >= mot - ache)
            return thic;
        return inf;
    }
    ll &ret = dp[indx][thic];
    if(ret != -1) return ret;
    ret = inf;
    if(thic >= mot - ache)
        return ret = thic;
    ret = min(ret , min(solve(indx+1,thic+t[indx],ache+w[indx]) , solve(indx+1,thic,ache)));
    return ret;
}

//%I64d
int main()
{
    ll i,j,k,m,l1,l2,len,p,q,p1,q1;
    vector <ll> one,two;
    while(cin >> n)
    {
        l1 = l2 = 0ll;
        mot = 0ll;
        for(i=0;i<n;i++)
            cin >> t[i] >> w[i] , mot += w[i];
        memset(dp,-1,sizeof(dp));
        cout << solve(0ll,0ll,0ll) << "\n";

    }

    return 0;
}
