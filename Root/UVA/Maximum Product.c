#include<stdio.h>

int n,num[20];
long long func()
{
    int i,j;
    long long max,mul;
    max=0;
    for(i=0; i<n; i++)
    {
        mul=1;
        for(j=i; j<n; j++)
        {
            mul*=num[j];
            if(mul>max)
                max=mul;
        }
    }
    return max;
}
int main()
{
    int i,t=0;
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
            scanf("%d",&num[i]);
        printf("Case #%d: The maximum product is %lld.\n\n",++t,func());
    }
    return 0;
}
