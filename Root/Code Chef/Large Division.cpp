#include "stdio.h"
#include "string.h"

char arr[210];

typedef long long ll;

bool divide(ll d)
{
    ll r, i;

    i = r = 0;
    if(arr[i] == '-') i++;

    for(;arr[i];i++)
    {
        r = r*10 + arr[i] - '0';
        r %= d;
    }

    return r==0;
}

int main()
{
    ll t=0, test, n;

    scanf("%lld",&test);

    while(test--)
    {
        scanf("%s %lld",arr,&n);
        if(n < 0 ) n *= -1;
        printf("Case %lld: ",++t);
        if(divide(n)) printf("divisible\n");
        else printf("not divisible\n");
    }

    return 0;
}
