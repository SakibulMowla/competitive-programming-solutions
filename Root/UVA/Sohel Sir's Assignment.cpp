#include "stdio.h"
#include "iostream"

using namespace std;

typedef long long ll;

int main()
{
    ll t, x, y, tmp, ans, i;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&x,&y);

        if(x+2 == y)
        {
            printf("%lld\n",x+1);
            continue;
        }

        tmp = x-y+2;
        ans = 1e15;

        for(i=1; i*i<=tmp; i++)
        {
            if(!(tmp%i))
            {
                if(x%i+2 == y)
                {
                    ans = i;
                    break;
                }
                else if(x%(tmp/i)+2 == y)
                    ans = tmp/i;
            }
        }

        if(ans == 1e15)
            puts("Impossible");
        else
            printf("%lld\n",ans);
    }

    return 0;
}





