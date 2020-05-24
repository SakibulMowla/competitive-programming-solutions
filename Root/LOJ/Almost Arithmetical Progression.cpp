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
#define SZ 4010

int arr[SZ];

int main()
{
    int n,i,j,k,cnt,flag1,flag2,ans,q;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        ans = 1;
        for(i=2;i<=n;i++)
        {
            q = arr[i] - arr[i-1];
            flag1 = 1;
            flag2 = 0;
            k = i;
            cnt = 1;
            while(k<=n)
            {
                if(flag1 % 2 ==1)
                {
                    j = arr[k-1] + q;
                    if(arr[k] != j)
                    {
                        k++;
                        continue;
                    }
                    cnt++;
                    flag1++;
                    flag2++;
                }
                else if(flag2 % 2 == 1)
                {
                    j = arr[k-1] - q;
                    if(arr[k] != j)
                    {
                        k++;
                        continue;
                    }
                    cnt++;
                    flag1++;
                    flag2++;
                }

                k++;
            }
            if(cnt > ans) ans = cnt;
        }
        printf("%d\n",ans);
    }


    return 0;
}
