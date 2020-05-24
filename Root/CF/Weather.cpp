#include "stdio.h"
int min(int a,int b) {return a < b ? a : b;}
int arr[100000+5];
int main()
{
    int n,i,ans,m,p;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n) == 1)
    {
        m = p = 0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]) ;
            if(arr[i] <= 0) m++;
        }
        ans = n;
        for(i=1; i<n; i++)
        {
            if(arr[i] >= 0) p++;
            if(arr[i] <= 0) m--;
            ans = min(ans,m+p);
        }
        printf("%d\n",ans);
    }

    return 0;
}
