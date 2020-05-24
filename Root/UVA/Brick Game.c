#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[1000],m,n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&arr[j]);
        }
        k=(m/2)+1;
        printf("Case %d: %d\n",i,arr[k]);
    }

    return 0;
}
