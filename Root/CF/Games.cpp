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
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

int main()
{
    int i,j,k,n,h[SZ],g[SZ];
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&h[i],&g[i]);
        }
        k = 0;
//        int cnt = 0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
//                cnt++;
                if(h[i] == g[j]) k++;
                if(g[i] == h[j]) k++;
            }
        }
        printf("%d\n",k);
    }

    return 0;
}
