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
        i = n;
        while(i-1 >=1 && arr[i-1] < arr[i] ) i--;
        ans = i - 1;
        printf("%d\n",ans);
    }

    return 0;
}
