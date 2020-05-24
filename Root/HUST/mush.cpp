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
    int n, a, b;

    while(scanf("%d %d %d",&n,&a,&b) == 3)
        printf("%d\n",2*n*a*b);

    return 0;
}

