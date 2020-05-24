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
    int a, b, c;

    while(scanf("%d %d %d",&a,&b,&c) == 3)
    {
        if(a+b+c == 0 || a+b+c == 3)
        {
            printf("*\n");
            continue;
        }
        if(a==b)
        {
            printf("C\n");
        }
        else if(b==c)
        {
            printf("A\n");
        }
        else if(c==a)
        {
            printf("B\n");
        }
    }

    return 0;
}
