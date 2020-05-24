#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;


int color[1000];

int main()
{
    int i,j,n,k,print;
    map<int , int> M;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&j);
        M[i] = j;
        color[j] = 1;
    }
    j = 1;
    for(i=1;i<=k;i++)
    {
        print = 1;
        printf("%d",M[i]);
        for( ; j<=n*k;j++)
        {
            if(print == n) break;
            if(color[j] == 0)
            {
                print++;
                printf(" %d",j);
            }
        }
        printf("\n");
    }

    return 0;
}
