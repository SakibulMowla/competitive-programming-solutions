#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;


int main()
{
    int n, u, d, i, j, k;

    while(scanf("%d %d %d",&n,&u,&d) == 3)
    {
        if(!n) break;

        k = 0;
        j = 0;

        for(i=0;;i++)
        {
            if(i&1)
            {
                j -= d;
            }
            else
            {
                j += u;
                if(j >= n) break;
            }
        }

        printf("%d\n",i+1);
    }

    return 0;
}


