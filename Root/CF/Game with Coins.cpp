#include "stdio.h"
int max(int a,int b) { return a>b ? a : b; }
int main()
{
    int arr[110], i, k, n, ans;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        if(n<=2 || n%2 == 0)
        {
            printf("-1\n");
            continue;
        }
        ans = 0;
        for(i=(n-1)/2;i>=1;i--)
        {
            k = 0;
            k = arr[i*2];
            k = max(k , arr[i*2+1]);
            arr[i] = max(0,arr[i]-k);
            arr[i*2] = max(0,arr[i*2]-k);
            arr[i*2+1] = max(0,arr[i*2+1]-k);
            ans += k;
        }
        printf("%d\n",ans+arr[1]);
    }

    return 0;
}
