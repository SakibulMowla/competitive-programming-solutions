#include "stdio.h"
typedef long long ll;
int main()
{
    ll i,a,b;
//    while(1)
    {
        scanf("%I64d %I64d",&a,&b);
        for(i=63;i>=0;i--)
            if( ((1LL<<i)&a) != ((1LL<<i)&b) )
                break;
        printf("%I64d\n",( 1LL<<(i+1) ) - 1 );
    }

    return 0;
}
