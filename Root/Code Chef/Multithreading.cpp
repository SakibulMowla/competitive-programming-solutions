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
    int i,j,k,n,ans;
    while(scanf("%d",&n) == 1)
    {
        k = 0;
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        for(i=1;i<=n;i++)
        {
            if(i == n)
            {
                ans = n-1;
                break;
            }
            j = i;
            while(j+1 <= n && arr[j] < arr[j+1])
            {
                j++;
                if(j == n)
                {
                    ans = i - 1;
                    k = 1;
                    break;
                }
            }
            if(k == 1) break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
