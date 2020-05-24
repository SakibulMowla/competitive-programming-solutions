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
#define SS(n) scanf("%s",&)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

vector <int> input , offer;

int main()
{
    int n,m,i,j,k,cost;
    while(scanf("%d",&m) == 1)
    {
        cost = 0;
        input.clear();
        offer.clear();
        for(i=0;i<m;i++)
        {
            SD(j);
            offer.push_back(j);
        }
        sort(offer.begin(),offer.end());
        SD(n);
        for(i=0;i<n;i++)
        {
            SD(j);
            input.push_back(j);
        }
        sort(input.rbegin(),input.rend());
        cost = 0;
        k = 0;
        for(i=0;i<n;i++)
        {
            if(k == offer[0])
                i = i + 1 , k = 0;
            else
            {
                cost += input[i];
                k++;
            }
        }
        printf("%d\n",cost);
    }


    return 0;
}
