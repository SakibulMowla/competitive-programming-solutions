#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

int main()
{
    ll x, y;

    while(cin >> x >> y)
    {
        if(x>=0 && y>=0)    printf("%I64d %I64d %I64d %I64d\n",0LL, x+y, x+y, 0LL);
        else if(x>=0 && y<0)    printf("%I64d -%I64d %I64d %I64d\n",0LL, abs(x)+abs(y), abs(x)+abs(y), 0LL);
        else if(x<0 && y>=0)    printf("-%I64d %I64d %I64d %I64d\n",abs(x)+abs(y), 0LL, 0LL, abs(x)+abs(y));
        else    printf("-%I64d %I64d %I64d -%I64d\n",abs(x)+abs(y), 0LL, 0LL, abs(x)+abs(y));
    }

    return 0;
}
