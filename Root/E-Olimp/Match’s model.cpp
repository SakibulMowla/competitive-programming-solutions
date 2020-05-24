#include <stdio.h>

int main()
{
    long long n,ans;
    while(scanf("%lld",&n) == 1)
    {
        ans = 12 + (n-1) * 8;
        printf("%lld\n",ans);
    }

    return 0;
}
