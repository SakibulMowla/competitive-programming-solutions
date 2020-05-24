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
    int n, x, y, z;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d %d %d",&x,&y,&z);
        printf("%d\n",z * (2 * x - y) / (x + y));
    }

    return 0;
}

