using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

typedef long long ll;
const ll mod = 100000000LL;

ll dp[110][110][12][12];

ll ttf, tth, ccf, cch;

ll solve(ll indx1,ll indx2,ll n,ll m)
{
    if(indx1 > ttf || indx2 > tth || n > ccf || m > cch) return 0;
    if(indx1+indx2 == ttf+tth)
        return 1;

    ll &ret = dp[indx1][indx2][n][m];

    if(ret != -1) return ret;

    return ret = ( solve(indx1+1, indx2, n+1, 0) + solve(indx1, indx2+1, 0, m+1) ) % mod;
}

int main()
{
    ll i, j, k, l;
    while(cin >> ttf >> tth >> ccf >> cch)
    {
        for(i=0; i<=ttf; i++) for(l=0; l<=tth; l++) for(j=0; j<=ccf; j++) for(k=0; k<=cch; k++) dp[i][l][j][k]= -1;
        cout << solve(0, 0, 0, 0) << "\n";
    }

    return 0;
}
