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
    long long i,num,n,sum;
    while(scanf("%I64d",&n) == 1)
    {
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&num);
            sum += num;
        }
        if(sum % n == 0) printf("%I64d\n",n);
        else printf("%I64d\n",n-1);
    }

    return 0;
}
