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

struct data
{
    int num , indx;
};

vector <data> input;

bool comp(data p,data q)
{
    return p.num < q.num;
}N

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j,k;
    vector <int> ans;
    data u;
    while(scanf("%d",&n) == 1)
    {
        input.clear();
        ans.clear();
        for(i=1;i<=2*n;i++)
        {
            scanf("%d",&u.num);
            u.indx = i;
            input.push_back(u);
        }
        sort(input.begin(),input.end(),comp);
        for(i=0;i<2*n;i+=2)
        {
            if(input[i].num != input[i+1].num)
            {
                printf("-1\n");
                return 0;
            }
            ans.push_back(input[i].indx);
            ans.push_back(input[i+1].indx);
        }
        for(i=0;i<2*n;i+=2)
            printf("%d %d\n",ans[i],ans[i+1]);
    }

    return 0;
}
