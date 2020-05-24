#include <stdio.h>

int main()
{
    long long n , m , c , ans;
    while(scanf("%lld %lld %lld",&n,&m,&c) == 3 && (n||m))
    {
        ans = ((n-8+1) * (m-8+1)) / 2;
        if((n-8+1) * (m-8+1) % 2 && c) ans++;
        printf("%lld\n",ans);
    }

    return 0;
}
