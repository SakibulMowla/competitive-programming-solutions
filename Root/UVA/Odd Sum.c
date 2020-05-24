#include<stdio.h>

int main()
{
    int sum,i,j,n,a,b;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        sum=0;
        for(j=a;j<=b;j++)
        {
            if(j%2==1)
                sum+=j;
        }
        printf("Case %d: %d\n",i+1,sum);
    }

    return 0;
}
