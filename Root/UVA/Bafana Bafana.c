#include<stdio.h>

int main()
{
    int a,i,t,n,k,p;

    scanf("%d",&t);

    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d",&n,&k,&p);
        if(k+p>n)
        {
            a=(k+p)%n;
            if(a==0)
                printf("Case %d: %d\n",i,n);
            else
                printf("Case %d: %d\n",i,a);
        }
        else
            printf("Case %d: %d\n",i,k+p);
    }

    return 0;
}
