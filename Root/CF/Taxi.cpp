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
    int n, a, b, c, i, j, k, ans;

    scanf("%d",&n);

    a = b = c = ans = 0;

    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        if(k == 1) a++;
        else if(k == 2) b++;
        else if(k == 3) c++;
        else ans++;
    }

    ans +=(b/2);
    b %= 2;

    if(a >= c)
    {
        ans += c;
        a -= c;
        c = 0;
    }

//    printf("a = %d\n",a);

    if(a > b && b>0)
    {
        b = 0;
        ans++;
        a--;
        if(a) a--;
    }

//    printf("a = %d %d\n",a,c);

    if(a < c)
    {
        ans += a;
        c -= a;
        a = 0;
    }

//    printf("a = %d\n",a);

    if(a && b)
        ans++, a--, b--;

    if(a)
    {
//        printf("yes\n");
        ans += (a+3) / 4;
        a = 0;
    }

    ans += a + b + c;

    printf("%d\n",ans);

    return 0;
}


