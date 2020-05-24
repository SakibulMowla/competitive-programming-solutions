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


int dist[1010], weit[1010];

int main()
{
    int t, limit,n, i, j, k, ans, trash;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&limit,&n);

        for(i=0;i<n;i++)
            scanf("%d %d",&dist[i],&weit[i]);

        ans = trash = 0;

        for(i=0;i<n;i++)
        {
            if(trash + weit[i] == limit)
            {
                trash = 0;
                ans += (dist[i] << 1);
            }
            else if(trash + weit[i] > limit)
            {
                trash = weit[i];
                ans += (dist[i] << 1);
            }
            else
            {
                trash += weit[i];
            }
        }

        if(trash)
            ans += (dist[n-1] << 1);

        printf("%d\n",ans);
    }

    return 0;
}


