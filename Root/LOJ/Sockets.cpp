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
#define SZ 1010

vector <int> input;

int main()
{
    int i,j,k,n,m,ans,space;

    while(scanf("%d %d %d",&n,&m,&k) == 3)
    {
        input.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            input.push_back(j);
        }
        sort(input.rbegin(),input.rend());
        ans = i = 0;
        space = k;
        while(space < m && i < n)
        {
            space--;
            ans++;
            space+=input[i++];
        }
        if(space >= m)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }


    return 0;
}
