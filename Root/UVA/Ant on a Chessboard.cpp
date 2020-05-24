#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL n , sq , r , x , y;
    while(scanf("%lld",&n) == 1 && n)
    {
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
        printf("%lld %lld\n",x,y);
    }

    return 0;
}
