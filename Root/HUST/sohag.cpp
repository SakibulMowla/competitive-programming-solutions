#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;

int deg[100010];

int main()
{
    int i, j, k, n, m, one, two, more, b, r, s;

    while(scanf("%d %d",&n,&m) == 2)
    {
        memset(deg, 0, sizeof(int)*(n+2));

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            deg[j]++;
            deg[k]++;
        }

        one = two = more = b = r = s = 0;

        for(i=1;i<=n;i++)
        {
            if(deg[i] == 1) one++;
            else if(deg[i] == 2) two++;
            else more++;
        }

        if(two == n)
            r = 1;
        else if(two == n-2 && one == 2)
            b = 1;
        else if(one == n-1)
            s = 1;

        if(r + b + s != 1)
            printf("unknown topology\n");
        else if(b)
            printf("bus topology\n");
        else if(r)
            printf("ring topology\n");
        else if(s)
            printf("star topology\n");
    }

    return 0;
}





