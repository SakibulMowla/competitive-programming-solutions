#include<stdio.h>

int main()
{
    int n,a,b,c,i,j,arr[10000],k,sum,d;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        for(j=0; j<a; j++)
        {
            scanf("%d",&arr[j]);
        }
        while(1)
        {
            sum=0;d=0;
            for(k=0; k<b && k<a; k++)
            {
                sum+=arr[k];
                d++;
            }
            if(sum<=c)
                break;
            else b--;

        }
        printf("Case %d: %d\n",i,d);
    }
    return 0;
}
