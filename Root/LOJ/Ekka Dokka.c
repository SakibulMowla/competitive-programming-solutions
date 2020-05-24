#include <stdio.h>

int main()
{
    unsigned long long n,m,w,i,j,k;
    scanf("%llu",&k);
    for(i=0;i<k;i++)
    {
        scanf("%llu",&w);
        if(w%2==1)
            printf("Case %llu: Impossible\n",i+1);
        else
        {
            for(n=2;;n+=2)
            {
                if(w%n==0)
                {
                    m=w/n;
                    if(m%2==1)
                    break;
                }
            }
            printf("Case %llu: %llu %llu\n",i+1,m,n);
        }
    }

    return 0;
}
