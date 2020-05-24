#include "stdio.h"
#include "set"
#include "iostream"
using namespace std;
typedef long long ll;
set <ll> myset;
int main()
{
//    freopen("1.txt","r",stdin);
    ll test,t,i,c,r;
    test = 0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&c,&r);
        printf("Case #%lld:",++test);
        if(c == r)
        {
            printf(" 0\n");
            continue;
        }
        myset.clear();
        for(i=1; i*i <= c - r; i++)
            if((c-r) % i == 0)
            {
                myset.insert(i);
                myset.insert((c-r)/i);
            }

        for(set<ll>::iterator it = myset.begin(); it != myset.end(); it++)
            if(*it > r)
                printf(" %lld",*it);
        printf("\n");
    }

    return 0;
}
