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
    int n,j,t;
    double i,angle;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag = 0;
        for(j=3;;j++)
        {
            i = j;
            angle = (i-2) * 180 / i;
//            printf("%lf\n",angle);
            if(angle == n)
            {
//                printf("%d\n",j);
                flag = 1;
                break;
            }
            if(angle > n) break;
        }
        if(flag == 0) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
