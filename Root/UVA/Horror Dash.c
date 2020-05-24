#include<stdio.h>

int main()
{
    int n,m,i,j,x[100],p;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p=0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&x[j]);
            if(x[j]>p)
                p=x[j];
        }
        printf("Case %d: %d\n",i,p);
    }

    return 0;
}
