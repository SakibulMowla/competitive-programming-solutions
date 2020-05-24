using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define MAX 150
#define MAX1 55

typedef long long ll;
const ll inf  = (1LL<<30);

ll dp[MAX+5][MAX][MAX1] , original_money, coke;

ll solve(ll coke_left, ll five_left, ll ten_left)
{
    ll &ret = dp[coke_left][five_left][ten_left];

    if(ret != -1) return ret;
    if(coke_left == 0) return ret = 0;

    ll one_left = original_money - (8LL*(coke - coke_left)) - (5LL*five_left) - (10LL*ten_left);

    ret = inf;

    if(one_left >= 8) ret = min(ret , 8LL + solve(coke_left-1 , five_left, ten_left));
    if(ten_left >= 1) ret = min(ret , 1LL + solve(coke_left-1 , five_left, ten_left-1));
    if(five_left >= 2) ret = min(ret , 2LL + solve(coke_left-1 , five_left-2, ten_left));
    if(one_left >= 3 && five_left >= 1) ret = min(ret , 4LL + solve(coke_left-1, five_left-1, ten_left));
    if(ten_left >= 1 && one_left >= 3) ret = min(ret , 4LL + solve(coke_left-1, five_left+1, ten_left-1));

    return ret;
}

int main()
{
    ll t, i, j, k, one, five, ten;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&coke, &one, &five, &ten);
        original_money = one + (five*5LL) + (ten*10LL);

        for(i=0;i<=coke;i++)
            for(j=0;j<=five+50;j++)
                for(k=0;k<=ten;k++)
                    dp[i][j][k] = -1;

        printf("%lld\n", solve(coke, five, ten));
    }

    return 0;
}
