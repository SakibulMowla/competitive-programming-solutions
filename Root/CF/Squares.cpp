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

vector <int> input;

int main()
{
    int i,j,k,r,c,num,n,m;
    while(scanf("%d %d",&n,&k) == 2)
    {
        m = k;
        input.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            input.push_back(num);
        }
        sort(input.rbegin(),input.rend());
        for(i=0;i<input.size() && k;i++)
        {
            k--;
        }
        if(k == 0) printf("%d %d\n",input[i-1],input[i-1]);
        else printf("-1\n");
    }

    return 0;
}
