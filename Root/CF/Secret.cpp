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

typedef long long ll;
#define inf 1<<28
#define SZ 1010

int main()
{
    ll n,k,i,j,m;
    while(scanf("%I64d %I64d",&n,&k) == 2)
    {
        if(n / k < 3)
        {
            printf("-1\n");
            continue;
        }
        m = 0;
        j = 0;
        while(m != n)
        {
            j++;
            if(j == 2)
                for(i=1; i<=k && m!=n; i++)
                {
                    if(i == k) printf("%I64d ",1);
                    else printf("%I64d ",i+1);
                    m++;
                }

            else
                for(i=1; i<=k && m!=n; i++)
                {
                    printf("%I64d ",i);
                    m++;
                }
        }
        printf("\n");
    }

    return 0;
}
