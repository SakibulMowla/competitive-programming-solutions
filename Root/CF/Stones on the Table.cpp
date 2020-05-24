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
    int i,j,k,n;
    char arr[110];
    while(scanf("%d",&n) == 1)
    {
        scanf("%s",arr);
        k = 0;
        for(i=0;i<n;i=j)
        {
            j = i + 1;
            while(j < n && arr[j] == arr[i])
            {
                k++;
                j++;
            }
        }
        printf("%d\n",k);
    }

    return 0;
}
