#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 110

vector <int> v;
int taken[SZ] , arr[SZ] , n , m , print;

void bctk(int p)
{
    if(p >= n || print==k) return;
    int i;
    if(v.size() > 0)
    {
        printf("%d",v.size());
        for(i=0;i<v.size();i++)
            printf(" %d",v[i]);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        if( !taken[i] )
        {
            taken[i] = 1;
            v.push_back(arr[i]);
            bctk()
        }
    }
}

int main()
{
    int m,i,j;

    while(scanf("%d %d",&n,&k) == 1)
    {
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        print = 0;
        bctk(0);
    }

    return 0;
}
