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

bool check(int a, int b)
{
    if(a > b) swap(a, b);
    if(b-a <= 1 && (a&1)) return true;
    return false;
}

int main()
{
    int n, i, j, k, l;

    while(scanf("%d %d %d",&n,&i,&j) == 3)
    {
        l = 1;

        k = abs(i - j);

        while(!check(i, j))
        {
            l++;
            i = (i+1) / 2;
            j = (j+1) / 2;
        }

        printf("%d\n",l);
    }

    return 0;
}


