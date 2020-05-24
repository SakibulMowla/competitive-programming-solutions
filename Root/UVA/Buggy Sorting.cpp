#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 1010


int main()
{
    int n,i;
    while(scanf("%d",&n) == 1)
    {
        if(n == 1 || n == 2)
        {
            printf("-1\n");
            continue;
        }
        printf("%d",n);
        for(i=n-1;i>=1;i--)
            printf(" %d",i);
        printf("\n");
//        for(i=1;i<=n;i++)
//            scanf("%d",&arr[i]);
//        for(i=1;i<=n-1;i++)
//        {
//            for(j=i;j<=n-1;j++)
//            {
//                if(arr[j] > arr[j+1])
//                {
//                    tmp = arr[j];
//                    arr[j] = arr[j+1];
//                    arr[j+1] = tmp;
//                }
//            }
////        }
//        for(i=1;i<=n;i++)
//            printf("%d ",arr[i]);
    }

    return 0;
}
