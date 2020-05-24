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

vector <int> input;

int main()
{
    int i,j,n,k,sum;
    while(scanf("%d %d",&n,&k) == 2)
    {
        input.clear();
        for(i=0;i<n;i++)
        {
            SD(j);
            input.push_back(j);
        }
        for(i=0;i<n && input[i] < 0 && k;i++)
        {
            input[i] *= (-1);
            k--;
        }
        sort(input.begin(),input.end());
        if(k)
        {
            if(k%2 == 1) input[0] *= -1;
        }
        sum = 0;
        for(i=0;i<n;i++) sum += input[i];
        printf("%d\n",sum);
    }


    return 0;
}
