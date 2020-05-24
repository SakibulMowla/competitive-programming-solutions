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



int main()
{
    int n,i,j,k,t;
    char arr[110];
    while(scanf("%d %d",&n,&t) == 2)
    {
        scanf("%s",arr);
        for(i=0;i<t;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j+1 < n && arr[j] ==  'B' && arr[j+1] == 'G')
                {
                    swap(arr[j] , arr[j+1]);
                    j++;
                }
            }
        }
        printf("%s\n",arr);
    }

    return 0;
}
