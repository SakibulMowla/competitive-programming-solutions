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
    int i,j,k,l,n,ans;
    while(1 == scanf("%d",&n))
    {
        ans = 0;
        i = 0
        while(n--)
        {
            scanf("%d",&j);
            ans += abs(i - j) + 2;
            i = j;
        }
        printf("%d\n",ans);
    }

    return 0;
}
