#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 100010

int arr[SZ];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,n,ans;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr+1 , arr+n+1);
        ans = inf;
        j = 1;
        for(i=1;i<n;i++)
        {
            while(j<n && arr[j+1] <= 2*arr[i]) j++;
            ans = min(ans , i+n-j-1);
        }
        printf("%d\n",ans);
    }


    return 0;
}
