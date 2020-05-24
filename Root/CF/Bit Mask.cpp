#include "stdio.h"
#define ui unsigned long long int

int main()
{
    ui i,l,r,n,m,tmp;
    while(scanf("%llu %llu %llu",&n,&l,&r) == 3)
    {
        m = 0;
        for(i=32; ; i--)
        {
            tmp = m | (1LLU << i);
            if( tmp <= l || ( tmp <= r && ( (1LLU << i) & ~n) ) )
                m = tmp;
            if(i == 0) break;
        }
        printf("%llu\n",m);
    }

    return 0;
}
