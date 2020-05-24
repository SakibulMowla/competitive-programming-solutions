#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cur_l,cur_r,best_l,best_r,i,n,ans;
    scanf("%d",&n);
    scanf("%d %d",&best_l,&best_r);
    ans = 1;
    for(i=2;i<=n;i++)
    {
        scanf("%d %d",&cur_l,&cur_r);
        if(cur_l <= best_l || cur_r >= best_r)
        {
            if(cur_l <= best_l && cur_r >= best_r)
            {
                ans = i;
                best_l = cur_l;
                best_r = cur_r;
            }
            else if(cur_l < best_l)
            {
                best_l = cur_l;
                ans = -1;
            }
            else if(cur_r > best_r)
            {
                best_r = cur_r;
                ans = -1;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}

