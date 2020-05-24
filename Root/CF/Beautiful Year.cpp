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

int col[20];

bool solve(int n)
{
    memset(col,0,sizeof(col));
    int i,j,k;
    while(n)
    {
        col[n%10]++;
        n /= 10;
    }
    for(i=0;i<10;i++)
        if(col[i] > 1) return false;
    return true;
}

int main()
{
    int i,j,k,l,n;
    while(scanf("%d",&n) == 1)
    {
        for(i=n+1;;i++)
            if(solve(i) == true)
                {printf("%d\n",i);break;}
    }

    return 0;
}
