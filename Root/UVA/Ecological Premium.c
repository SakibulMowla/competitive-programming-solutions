#include<stdio.h>

double main()
{
    long long int a,b,c,n,m,i,j,sum;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&m);
        sum=0;
        for(j=0;j<m;j++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            sum+=(a*b*c)/b;
        }
        printf("%lld\n",sum);
    }
    return 1.0;
}
