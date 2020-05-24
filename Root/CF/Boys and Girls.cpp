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
#define SZ 1010


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n > m)
        j = 0;
        else j = 1;
        while(n && m)
        {
            if(j%2 == 0)
                printf("B") , n--;
            else
                printf("G") , m--;
            j++;
        }
        while(n)
        {
            printf("B") , n--;
        }
        while(m)
        {
            printf("G") , m--;
        }
        printf("\n");
    }


    return 0;
}
