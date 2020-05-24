#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int i,j,m,k,dist,oil,,good[1010];
    vector <int> d,s;
    while(scanf("%d %d",&m,&k) == 2)
    {
        d.clear();
        s.clear();
        memset(good,0,sizeof(good));
        for(i=0;i<m;i++)
        {
            scanf("%d",&j);
            d.push_back(j);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&j);
            s.push_back(j);
        }
        good[0] = s[0];
        for(i=1;i<m;i++)
        {
            good[i] = max(good[i-1],s[i]);
        }
        oil = 0;
        dist = 0;
        for(i=0;i<m;i++)
        {
            oil += s[i];
            while(oil < d[i])
            {
                oil += good[i];
                dist += k;
            }
            oil -= d[i];
            dist += d[i];
        }
        printf("%d\n",dist);
    }

    return 0;
}
