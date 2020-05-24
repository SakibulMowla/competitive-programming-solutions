#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "map"
#include "iostream"
using namespace std;

#define SZ 1010
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef pair<ll , ll> pii;

ll dp[SZ][SZ];
map <pii , ll> M;

int main()
{
    ll t,r,c,i,j,k;
    char str[1000],*ch;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&r,&c);
        M.clear();
        for(i=1;i<=r;i++) for(j=1;j<=c;j++) dp[i][j] = 0;
        dp[1][1] = 1;
        for(i=0;i<r;i++)
        {
            scanf(" %[^\n]",str);
            ch = strtok(str," ");
            j = atoi(ch);
            ch = strtok(NULL," ");
            while(ch)
            {
                k = atoi(ch);
                M[MP(j,k)] = 1;
                dp[j][k] = 0;
                ch = strtok(NULL," ");
            }
        }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            {
                if(M.find(MP(i,j)) != M.end() ) continue;
                dp[i][j] += dp[i][j-1] + dp[i-1][j];
            }
        printf("%lld\n",dp[r][c]);
        if(t) printf("\n");
    }

    return 0;
}
