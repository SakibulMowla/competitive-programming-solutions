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


int main()
{
    int i, j, k, t, n, test=0;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        k = 0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            if(j > k)
                k = j;
        }

        printf("Case %d: %d\n",++test,k);
    }

    return 0;
}

