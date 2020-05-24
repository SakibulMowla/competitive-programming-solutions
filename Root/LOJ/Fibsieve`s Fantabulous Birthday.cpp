#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef long long LL;

int main()
{
    LL t , test , n , sq , r , x , y;
    t = 0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        sq = ceil( sqrt(n) );
        r = sq * sq - n;
        if(r < sq)
        {
            y = r + 1;
            x = sq;
        }
        else
        {
            x = 2 * sq - r - 1;
            y = sq;
        }
        if(sq % 2 == 1)
            swap(x,y);
        printf("Case %lld: %lld %lld\n",++t,x,y);
    }

    return 0;
}
