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


int main()
{
    int a,b,c,i,j,n,num;
    while(scanf("%d",&n) == 1)
    {
        a=b=c=j = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(j%3 == 0) a+=num;
            if(j%3 == 1) b+=num;
            if(j%3 == 2) c+=num;
            j++;
        }
        if(a>b && a>c) printf("chest\n");
        if(b>a && b>c) printf("biceps\n");
        if(c>a && c>b) printf("back\n");
    }


    return 0;
}
