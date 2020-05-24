#include "stdio.h"
#include "string.h"
#include "time.h"
#include "iostream"
using namespace std;
#define SZ 1000010

typedef long long ll;
ll seq[SZ];

int main()
{
    ll i,j,k,n,m,last,pos,ans;
//    freopen("output.txt","w",stdout);
    scanf("%I64d",&n);
    {
//        clock_t t = clock();
//        memset(seq,0ll,sizeof(ll)*(n+1));
        if(n%2) last = 0ll;
        else last = 1ll;
        ans = 0ll;
        for(i=n;i>=last;i--)
        {
            if(seq[i]) continue;
            pos = 0ll;
            k = i;
            j = 0ll;
            while(k)
            {
                if(!(i & 1ll<<pos)) j += 1ll << pos;
                k = k >> 1;
                pos++;
            }
            seq[i] = j;
            seq[j] = i;
//            ans += (i^j)<<1ll;
            ans += ((1ll<<pos)-1ll)<<1ll;
        }
        cout << ans << "\n";
        for(i=0;i<=n;i++)
            printf("%I64d ",seq[i]);
        printf("\n");
//        t = clock() - t;
//        printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    }

    return 0;
}
